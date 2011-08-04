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
#include "CBScreenSaver.h"
#include "CBMoff.h"
#include <mcheck.h>
#include <math.h>

float f = 0.05;
float dx = 0.05;

CBScreenSaver::CBScreenSaver()
{
	
	b = 0;
	//this->Buffer = new CBBuffer();
	this->detail = 5;
	//Object = std::vector<Moff>(1, Moff("", this->Buffer, this->detail));

	//Object[0].Create(this->detail);
	
	//Object[0].SetMode(Draw_Flat);
//Object[0].Set(1.0*11/10);
//Object[0].B->light=CBVertex(1.5, 0.5, -2.0);  
//Object[0].B->light.Normalize();



//char t;

//for (int i=1; i<11; i++)
//for (int d=0; d<360; d++)
//{

//Roteer(-0.4,0.1,4.0);
//Object[0].B->light.Normalize();
//Object[0].Set(1.0*11/10);
//Object[0].Roteer(-0.4,1.1,4.0);
//Object[0].Draw();
//cout << "LEVEL " << i << endl;

//}
//cin >> t;
//cout<<"errr"<<endl;

}
CBScreenSaver::~CBScreenSaver(){
//	delete this->Buffer;i
	Object.clear();
}




void CBScreenSaver::Draw()
{
/*
	if (frame == 0){
		Buffer = new CBBuffer(view->Bounds(), (int)(view->Bounds().bottom - view->Bounds().top)/2);
		Object = new Moff("", Buffer, i);
		if ( this->detail_slider != NULL )
			this->detail = this->detail_slider->Value();
		Create(Object, detail);
	}

		Buffer -> Clear();
		
		if ((f >= 1.0) || (f <= 0.01))
			dx = -dx;
		f += dx;
		Set(Object, f);
		Object->Roteer(-15.0,10.0,0.0);
		Object->Draw();
		Buffer->MakeReady();
		view->DrawBitmap(Buffer);
*/
	
}

int main(int argc, char** argv)
{

//mtrace();
	DirectFB::Init( &argc, &argv );
	CBScreenSaver saver;
//for (
int i=1; 
//i < argc; i++)
//{
std::cout << "reading " << argv[i] << std::endl;
//saver.Object = std::vector<Moff>(1, Moff(argv[i], &saver.Buffer));
Moff *b = new Moff(argv[1], &saver.Buffer);
saver.Object.push_back(*b);
std::cout << "reading " << argv[i] << "done" << std::endl;
//}

//saver.Object[0].Create(saver.detail);
	
//saver.Object[0].SetMode(Draw_Flat);
//saver.Object[0].SetMode(Draw_Wire);
//saver.Object[0].SetMode(Draw_Dot);
//saver.Object[0].Set(1.0*11/10);
//saver.Object[0].B->light=CBVertex(1.5, 0.5, -2.0);  
//saver.Object[0].B->light.Normalize();
//saver.Object[0].SetScale(40);
//saver.Object[0].Roteer(0,0,180);

CBMatrix mx, my, mz;
	mx = mx.MakeRotateX(10.0) * my.MakeRotateY(0.0) * mz.MakeRotateZ(180.0);
//	mx = mx.MakeRotateX(0.0) * my.MakeRotateY(0.0) * mz.MakeRotateZ(180.0);


saver.Object[0].Move(CBVertex(0,0,0.85)) ;
saver.Object[0].Roteer(mx);

	//mx = mx.MakeRotateX(-7) * my.MakeRotateY(11) * mz.MakeRotateZ(1);

	mx.Reset();
//for(;;)
for (int s = 4; s < 26*2; s+=2)
for (int i = 0; i < 360/(s>26?58-s:s); i++)
{
mx =  my.MakeRotateY(90*sin(i*(s>26?58-s:s)*3.14/180)) * mz.MakeRotateZ(0);
saver.Object[0].Roteer(mx);

saver.Object[0].Draw();

saver.Object[0].Roteer(0,-90*sin(i*(s>26?58-s:s)*3.14/180),  0);
}
//char c;
//cin >> c;
	return 0;
}
