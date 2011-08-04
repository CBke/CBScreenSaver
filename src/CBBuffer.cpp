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

#include "CBBuffer.h"
#include "CBPoint.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>   // one of two
using namespace std; 
const float EPS0 = 0.0 + 1.0e-15;
const float EPS1 = 1.0 - 1.0e-15;



CBBuffer::CBBuffer() {

//	Buffer_data = (uint32*)Bits();
//	width = (int)(rect.right - rect.left) + 1;
//	height = (int)(rect.bottom - rect.top) + 1;
	
	//ZBuffer = new float[width*height];
	//for (long i=0; i < width*height; i++)
	//	ZBuffer[i] = -1.0e+20;
	work = DirectFB::Create();
try {
          /* try fullscreen mode */
         // m_dfb->SetCooperativeLevel( DFSCL_FULLSCREEN );
 DFBSurfaceDescription dsc;
 dsc.flags = DSDESC_CAPS;
     dsc.caps  = DSCAPS_PRIMARY;
/*
     if (m_flipping)
          DFB_ADD_SURFACE_CAPS( dsc.caps, DSCAPS_DOUBLE );

     if (m_width) {
          DFB_ADD_SURFACE_DESC( dsc.flags, DSDESC_WIDTH );
          dsc.width  = m_width;
     }

     if (m_height) {
          DFB_ADD_SURFACE_DESC( dsc.flags, DSDESC_HEIGHT );
          dsc.height = m_height;
     }
*/
     /* create the primary surface */
   surface = work->CreateSurface( dsc );

surface->GetSize(&width, &height);

//DFBSurfaceDescription dsc;
//surface = work->CreateSurface( dsc );
     }
     catch (DFBException *ex) {
          if (ex->GetResultCode() == DFB_ACCESSDENIED)
               std::cerr << "Warning: " << ex << std::endl;
          else
std::cerr << "CBERR: " << ex << std::endl;
               //throw;
     }
 //DFB_ADD_SURFACE_CAPS( DSCAPS_PRIMARY, DSCAPS_DOUBLE );


//return Setup( width, height );
cout << "end constr buffer" << endl;
}

CBBuffer::~CBBuffer(){
	work->Release();
}

void CBBuffer::Clear(){
surface->Clear( 0x00, 0x00, 0x00 );
	//BView *view = new BView(Bounds(),NULL,B_FOLLOW_LEFT|B_FOLLOW_TOP,B_WILL_DRAW);
	//AddChild(view);
	//Lock();
	//rgb_color c;
	//c.red=255; c.green=255; c.blue=255;
	//view->SetHighColor(c);
	//view->FillRect(Bounds());
	//RemoveChild(view);
//	uint32* bits=(uint32*)Bits();//+y*(BytesPerRow()/4)+x;
//	for(long i = 0; i < width * height; i++){
//		*bits = 0x00000000;
//		bits++;
		//ZBuffer[i] = -1.0e+20;
//	}
	//delete view;
	//for (long i=0; i < width*height; i++)
		
}

void CBBuffer::DrawDot(const float px, const float py, const float d, rgb_color c)
{	
//surface->Clear();
	int x = (int)(px + width / 2);
	int y = (int)(py + height / 2);
	if ((x >= 0) && (y >= 0) && (x < width) && (y < height)){
	//	if (d > ZBuffer[x+y*width])
	//	{
	
//			uint32* bits=(uint32*)Bits()+y*(BytesPerRow()/4)+x;
//			*(bits)= (uint32)(c.red * 0x00010000 + c.green * 0x00000100 + c.blue * 0x00000001);
			//ZBuffer[x+y*width] = d;
	//	}
	}

}

int CBBuffer::getWidth(){
	return width;
}

int CBBuffer::getHeight(){
	return height;
}

void CBBuffer::Line(int x0, int y0, int x1, int y1, rgb_color c)
{
	int dx = x1- x0;
	int dy = y1 -y0;
	int p;
	int incx = 1;
	int incy = 1;

	if(dx < 0)
		incx = -1;
	if(dy < 0)
		incy = -1;
	if (dx > dy) // yvarieren
	{
		dy = abs(dy);
		dx = abs(dx);
		p = 2 * dx - dy;
		if ((dx < 0) || (dy <0)) 
			printf ("jongen daar klop gene klood van abs\n");
		//////////////
		if ((x0 >= 0) && (y0 >= 0) && (x0 < width) && (y0 < height)){
//			uint32* bits=(uint32*)Bits()+y0*(BytesPerRow()/4)+x0;
//			*(bits)= (uint32)(c.red*0x00010000+c.green*0x00000100+c.blue*0x00000001);
		}
		///////////////
		while (y0 != y1)
		{
		//////////////
			if ((x0 >= 0) && (y0 >= 0) && (x0 < width) && (y0 < height)){
//				uint32* bits=(uint32*)Bits()+y0*(BytesPerRow()/4)+x0;
//				*(bits)= (uint32)(c.red*0x00010000+c.green*0x00000100+c.blue*0x00000001);
			}
		///////////////
		
	
			if (p <= 0) {
				p += 2*dx;
			} else {
				p += 2 * dx -2 * dy;
				x0 += incx;
			}
			y0 += incy;
		}
	}
	else
	{	
		
		dy = abs(dy);
		dx = abs(dx);
		p = 2 * dy - dx;
		//////////////
		if ((x0 >= 0) && (y0 >= 0) && (x0 < width) && (y0 < height)){
//			uint32* bits=(uint32*)Bits()+y0*(BytesPerRow()/4)+x0;
//			*(bits)= (uint32)(c.red*0x00010000+c.green*0x00000100+c.blue*0x00000001);
		}
		///////////////
		while (x0 != x1)
		{
		//////////////
		if ((x0 >= 0) && (y0 >= 0) && (x0 < width) && (y0 < height)){
//			uint32* bits=(uint32*)Bits()+y0*(BytesPerRow()/4)+x0;
//			*(bits)= (uint32)(c.red*0x00010000+c.green*0x00000100+c.blue*0x00000001);
		}
		///////////////
			if (p <= 0) {
				p += 2 * dy;
			} else {
				p += 2 * dy - 2 * dx;
				y0 += incy;
			}
			x0 += incx;
		}
	}

}


int InvalideLambda(float l1, float l2, float l3)
{

	if ((l1 < EPS0) || (l1 > EPS1))
		return 1;
	else if ((l2 < EPS0) || (l2 > EPS1))
		return 2;
	else if ((l3 < EPS0) || (l3 > EPS1))
		return 3;
	else {
		if ((l1 <= EPS0) || (l1 >= EPS1))
			return 1;
		else if ((l2 <= EPS0) || (l2 >= EPS1))
			return 2;
		else if ((l3 <= EPS0) || (l3 >= EPS1))
			return 3;
		else
			return -1; //inclrrect labda's
	}
	
}


void CBBuffer::Flip()
{
surface->Flip();
}
/*
void CBBuffer::DrawGourand(CBTriangle t)
{
	
	int maxy = (int)(t.MaxPar()*Scale), Left=0, Right=0,
	miny =(int)(t.MinPar()*Scale);
	CBVertex LeftV, RightV, CV;
	if (0 <= miny)
		miny++;
	
	if(maxy>=0)
		maxy++;
	float lambda1, lambda2, lambda3,depth = (t.Dot[0].z+t.Dot[1].z+t.Dot[2].z)/3;
	for(int Scanny=miny; Scanny < maxy; Scanny++){
	
	
		if (t.Dot[1].y- t.Dot[0].y)
			lambda1 = (Scanny/Scale-t.Dot[0].y) / (t.Dot[1].y- t.Dot[0].y);
		else
			lambda1 = Scanny/Scale-t.Dot[0].y;
	
								
		if (t.Dot[2].y- t.Dot[0].y)
			lambda2 = (Scanny/Scale-t.Dot[0].y) / (t.Dot[2].y- t.Dot[0].y);
		else
			lambda2 = Scanny/Scale-t.Dot[0].y;
		
								
		if (t.Dot[2].y- t.Dot[1].y)
			lambda3 = (Scanny/Scale-t.Dot[1].y) / (t.Dot[2].y- t.Dot[1].y);
		else
			lambda3 = Scanny/Scale-t.Dot[1].y;
														
		switch (InvalideLambda(lambda1, lambda2, lambda3))
		{
			case 1:{
				
				Left = (int)(Scale*(t.Dot[0].x+lambda2*(t.Dot[2].x-t.Dot[0].x)));
				Right = (int)(Scale*(t.Dot[1].x+lambda3*(t.Dot[2].x-t.Dot[1].x)));
//				LeftV = t.Edge[0]+(t.Edge[2]-t.Edge[0])*lambda2;
//				RightV = t.Edge[1]+(t.Edge[2]-t.Edge[1])*lambda3;
				if (Left > Right){
					Right = (int)(Scale*(t.Dot[0].x+lambda2*(t.Dot[2].x-t.Dot[0].x)));
					Left = (int)(Scale*(t.Dot[1].x+lambda3*(t.Dot[2].x-t.Dot[1].x)));
//					RightV = t.Edge[0]+(t.Edge[2]-t.Edge[0])*lambda2;
//					LeftV = t.Edge[1]+(t.Edge[2]-t.Edge[1])*lambda3;
				}
				
				break;
			}
			case 2:{
				
				Left = (int)(Scale*(t.Dot[0].x+lambda1*(t.Dot[1].x-t.Dot[0].x)));
				Right = (int)(Scale*(t.Dot[1].x+lambda3*(t.Dot[2].x-t.Dot[1].x)));
//				LeftV = t.Edge[0]+(t.Edge[1]-t.Edge[0])*lambda1;
//				RightV = t.Edge[1]+(t.Edge[2]-t.Edge[1])*lambda3;
				if (Left > Right){
					Right = (int)(Scale*(t.Dot[0].x+lambda1*(t.Dot[1].x-t.Dot[0].x)));
					Left = (int)(Scale*(t.Dot[1].x+lambda3*(t.Dot[2].x-t.Dot[1].x)));
//					RightV = t.Edge[0]+(t.Edge[1]-t.Edge[0])*lambda1;
//					LeftV = t.Edge[1]+(t.Edge[2]-t.Edge[1])*lambda3;
				}	
				
				break;
			}
			case 3:{
				
				Left = (int)(Scale*(t.Dot[0].x+lambda1*(t.Dot[1].x-t.Dot[0].x)));
				Right = (int)(Scale*(t.Dot[0].x+lambda2*(t.Dot[2].x-t.Dot[0].x)));
//				LeftV = t.Edge[0]+(t.Edge[1]-t.Edge[0])*lambda1;
//				RightV = t.Edge[0]+(t.Edge[2]-t.Edge[0])*lambda2;
				if (Left > Right){
					Right = (int)(Scale*(t.Dot[0].x+lambda1*(t.Dot[1].x-t.Dot[0].x)));
					Left = (int)(Scale*(t.Dot[0].x+lambda2*(t.Dot[2].x-t.Dot[0].x)));
//					RightV = t.Edge[0]+(t.Edge[1]-t.Edge[0])*lambda1;
//					LeftV = t.Edge[0]+(t.Edge[2]-t.Edge[0])*lambda2;
				}
				
				break;
			}
			default :{
				//printf("DEBUG !!!!!!\n");
				break;
			}
		};//case
		
		
		for(int Scannix=Left; Scannix<=Right; Scannix++){
			if (Right-Left)
				CV = LeftV +(RightV-LeftV)*((Scannix-Left)/(Right-Left));
			else
				CV = LeftV;
			rgb_color c=t.col;
			float a = 1.0-sqrt(CV.x*CV.x+CV.y*CV.y)/1.5;
			c.red = (int)(c.red*a);
			c.green = (int)(c.green*a);
			c.blue = (int)(c.blue*a);
	
			DrawDot(Scannix, Scanny, depth, c);
		}
		
	}//Scanny
	
}
*/

void CBBuffer::MakeReady()
{
//	RemoveChild(work);
//	delete work;
//	work = NULL;
}
