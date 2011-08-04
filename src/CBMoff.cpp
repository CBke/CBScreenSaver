/*
 * This file is part of CBScreenSaver.
 *
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Authors: CBke cb@linux.be
 */

#include "CBMoff.h"
#include "CBVertex.h"
#include <math.h>
#include <algorithm>
#include <fstream>

Moff::Moff(char *FileName, CBBuffer *b, const int &m):B(b)
{
	int points, triangles, objects;	

	std::ifstream is(FileName);
	is >> points >> triangles >> objects;

	Vertex = new std::vector<CBVertex>;		

	for (int point = 0; point < points; point++)
		(*Vertex).push_back(CBVertex(is));

	std::cout << "win" << Vertex->size() << (*Vertex).size()<< std::endl;
	for (int triangle = 0; triangle < triangles; triangle++)
		Driehoek.push_back(CBTriangle(is, Vertex));

	

	float maxx(0.0), maxy(0.0), maxz(0.0), minx(0.0), miny(0.0), minz(0.0), max(0.0), length(0.0);

	for (unsigned int point = 0; point < (*Vertex).size(); point++)
	{
		if ((*Vertex)[point].x > maxx)
			maxx = (*Vertex)[point].x;
		if ((*Vertex)[point].y > maxy)
			maxy = (*Vertex)[point].y;
		if ((*Vertex)[point].z > maxz)
			maxz = (*Vertex)[point].z;
		if ((*Vertex)[point].x < minx)
			minx = (*Vertex)[point].x;
		if ((*Vertex)[point].y < miny)
			miny = (*Vertex)[point].y;
		if ((*Vertex)[point].z < minz)
			minz = (*Vertex)[point].z;
		length = (*Vertex)[point].Length();
		if (max < length) 
			max = length;
	}

	Move(CBVertex(-(maxx+minx)/2.0, -(maxy+miny)/2.0, -(maxz+minz)/2.0));

//	SetScale(b->getHeight() / (2 * max)*0.8);
	SetScale(b->getHeight() *1.5/ ( max));


	SetMode(m);
	std::cout << "end constr moff" << std::endl;
};

Moff::~Moff(){
	std::cout << "calling destr Moff" << std::endl;


	std::cout << "CLEAR: " << (*Vertex).size() << std::endl;
	(*Vertex).clear();
	
	delete Vertex;
	std::cout << "end destr Moff" << std::endl;
}

void Moff::SetScale(const float s){
	if(s > 0)
	{
		Scale = s;
		std::cout << "scaled to : " << s << std::endl;
	}
}

void Moff::SetMode(const int m){
	if ((m >= 0) && (m < 4))
		mode = m;
}

void Moff::Roteer(const float &x, const float &y, const float &z)
{
	CBMatrix mx, my, mz;
	
	mx = mx.MakeRotateX(x) * my.MakeRotateY(y) * mz.MakeRotateZ(z);
	Roteer(mx);

}
void Moff::Roteer(const CBMatrix &m)
{

	for(unsigned int i = 0; i < (*Vertex).size(); i++)
			(*Vertex)[i] *= m;

	for(unsigned int i = 0; i < Driehoek.size(); i++)
		Driehoek[i].norm.Normalize(((*Vertex)[Driehoek[i].Dot[2]] - (*Vertex)[Driehoek[i].Dot[0]]) * ((*Vertex)[Driehoek[i].Dot[1]] - (*Vertex)[Driehoek[i].Dot[0]]));

}
void Moff::Move(const CBVertex& v)
{
	for(unsigned int i = 0; i < (*Vertex).size(); i++)
			(*Vertex)[i] += v;

}

void Moff::Draw(){
	//std::cout << Vertex << std::endl;
	B->Clear();
	switch (mode)
	{
		case Draw_Dot :
		{
			DrawDot();
			break;
		}
		case Draw_Wire :
		{
			DrawWire();
			break;
		}
		case Draw_Flat :
		{
			DrawFlat();
			break;
		}
		default:
		{
			printf("Invalid draw mode...\n");
			break;
		}
	}
	B->Flip();
}

void Moff::DrawDot()
{
	int width = B->getWidth();
	int height = B->getHeight();

	CBVertex light=  CBVertex(1.5, 0.5, 2.0);        
	light.Normalize();

	std::vector<CBTriangle>::iterator it;

	for (it=Driehoek.begin(); it!=Driehoek.end(); ++it)
	{
		if ((*it).norm.z<0)
		{
/*
			rgb_color c = (*it).col;
			CBVertex v = (*it).norm*light;

			float a = 1.0 - sqrt(v.x * v.x + v.y * v.y) / 1.5;
			c.Red = (int)(c.Red * a);
			c.Green = (int)(c.Green * a);
			c.Blue = (int)(c.Blue * a);
			B->surface->SetColor(c.Red,c.Green, c.Blue, 50);
*/
			B->surface->DrawLine(
				int(Scale * (*Vertex)[(*it).Dot[0]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[0]].y + height / 2),	
				int(Scale * (*Vertex)[(*it).Dot[0]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[0]].y + height / 2));

			B->surface->DrawLine(
				int(Scale * (*Vertex)[(*it).Dot[1]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[1]].y + height / 2),	
				int(Scale * (*Vertex)[(*it).Dot[1]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[1]].y + height / 2));

			B->surface->DrawLine(
				int(Scale * (*Vertex)[(*it).Dot[2]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[2]].y + height / 2),
				int(Scale * (*Vertex)[(*it).Dot[2]].x + width / 2),
				int(Scale * (*Vertex)[(*it).Dot[2]].y + height / 2));
		}	
	}
}
void Moff::DrawWire()
{
	int width = B->getWidth();
	int height = B->getHeight();

	CBVertex light=  CBVertex(1.5, 0.5, -2.0);        
	light.Normalize();

	std::vector<CBTriangle>::iterator it;

	for (it=Driehoek.begin(); it!=Driehoek.end(); ++it)
	{
		if ((*it).norm.z<0)
		{
/*
			rgb_color c = (*it).col;
			CBVertex v = (*it).norm*light;
			float a = 1.0 - sqrt(v.x * v.x + v.y * v.y);// / 1.5;
			c.red = (int)(c.red * a);
			c.green = (int)(c.green * a);
			c.blue = (int)(c.blue * a);

			B->surface->SetColor(c.red,c.green, c.blue, 0);
*/
			B->surface->DrawLine(
				int(Scale * (*Vertex)[(*it).Dot[0]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[0]].y + height / 2),	
				int(Scale * (*Vertex)[(*it).Dot[1]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[1]].y + height / 2));

			B->surface->DrawLine(
				int(Scale * (*Vertex)[(*it).Dot[1]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[1]].y + height / 2),	
				int(Scale * (*Vertex)[(*it).Dot[2]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[2]].y + height / 2));

			B->surface->DrawLine(
				int(Scale * (*Vertex)[(*it).Dot[0]].x + width / 2), 
				int(Scale * (*Vertex)[(*it).Dot[0]].y + height / 2),
				int(Scale * (*Vertex)[(*it).Dot[2]].x + width / 2),
				int(Scale * (*Vertex)[(*it).Dot[2]].y + height / 2));
		}	
	}
}


void Moff::DrawFlat()
{
	CBVertex light=  CBVertex(-0.5, 0.8, -20.0);        
	light.Normalize();

	int width = B->getWidth();
	int height = B->getHeight();

	std::vector<CBTriangle>::iterator it;
	sort (Driehoek.begin(), Driehoek.end()); 

	for (it=Driehoek.begin(); it!=Driehoek.end(); it++)
	{
		if ((*it).norm.z>0)
		{

			rgb_color c = (*it).col;

			CBVertex v = (*it).norm*light;
			float a = 1.0 - sqrt(v.x * v.x + v.y * v.y) / 1.2;
	

			c.red = (int)(c.red * a);
			c.green = (int)(c.green * a);
			c.blue = (int)(c.blue * a);

			B->surface->SetColor(c.red,c.green, c.blue, 0);

			B->surface->FillTriangle(
				Scale*(*Vertex)[(*it).Dot[0]].x + width / 2,
				Scale*(*Vertex)[(*it).Dot[0]].y + height / 2,
				Scale*(*Vertex)[(*it).Dot[1]].x + width / 2,
				Scale*(*Vertex)[(*it).Dot[1]].y + height / 2,
				Scale*(*Vertex)[(*it).Dot[2]].x + width / 2,
				Scale*(*Vertex)[(*it).Dot[2]].y + height / 2
			);
		}
	}

/*
	for (it=Driehoek.begin(); it!=Driehoek.end(); ++it)
	{
		if ((*it).norm.z>0)
		{
			
			
			float x, y;
			x = ((*Vertex)[(*it).Dot[0]].x + (*Vertex)[(*it).Dot[1]].x + (*Vertex)[(*it).Dot[2]].x)/3;
			y = ((*Vertex)[(*it).Dot[0]].y + (*Vertex)[(*it).Dot[1]].y + (*Vertex)[(*it).Dot[2]].y)/3;
			

B->surface->SetColor(255,0, 0, 50);
			B->surface->DrawLine(
				int(Scale * x + width / 2), 
				int(Scale * y + height / 2),
				int(Scale * x+(*it).norm.x*20 + width / 2),
				int(Scale * y+(*it).norm.y*20 + height / 2));
		}
	}
*/
}
