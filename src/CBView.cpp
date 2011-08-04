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

/*
#include "CBView.h"
#include <stdio.h>
#include <Message.h>
#include <Application.h>

CBView::CBView(BRect rect) : BView(rect, NULL, B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW)
{

	Buffer = new CBBuffer(rect, 15.0);
	i = 0;
	//Object = new Moff("Doghtnut.Raw", Buffer, i);
	Object = new Moff("Bunny.raw", Buffer, i);

}

CBView::~CBView(){
	delete Buffer;
}

void CBView::Flash()
{
	DrawBitmap(Buffer);
}

void CBView::Action(){

	//while(1){
	Object->Roteer(.0,2.5,1.3);
	Buffer->Clear();
	Object->Draw();
	Flash();
	//}

}
void CBView::MouseDown(BPoint p){

	uint32 mouseButtons;
	BPoint where;
	GetMouse(&where, &mouseButtons, true);
	switch (mouseButtons)
	{
		case B_PRIMARY_MOUSE_BUTTON:{
						    do {
							    p = where;
							    GetMouse(&where, &mouseButtons, true);
							    Object->Roteer(-(where.y-p.y), (where.x-p.x), 0);
							    Buffer->Clear();
							    Object->Draw();
							    Flash();
						    } while (mouseButtons);
						    break;
					    }
		case B_SECONDARY_MOUSE_BUTTON:{
						      while (mouseButtons == B_SECONDARY_MOUSE_BUTTON){
							      CBVertex v ((where.x-p.x)/50.0,(where.y-p.y)/50,0.0);
							      p = where;
							      Object->Move(v);
							      Buffer -> Clear();
							      Object->Draw();
							      Flash();
							      GetMouse(&where, &mouseButtons, true);
						      };
						      break;
					      }
		case B_TERTIARY_MOUSE_BUTTON:{
						     
							Object->BeginPosition();
							Buffer -> Clear();
							Object->Draw();
							Flash();
							break;
							
						     i++;
						     i %= 5;
						     Object->SetMode(i);
					     }
		default :
					     break;
	}
}

void CBView::MouseMoved(BPoint point, uint32 transit, BMessage *message){
	printf("Mouse move : x %f, y %f\n", point.x, point.y);
}

void CBView::KeyDown(const char *bytes, int32 numBytes)
{
	cout << "KeyPressed !" << endl;

	switch ( *bytes )
	{ 
		case B_F1_KEY: 
			Object->SetMode(0);
			break; 
		case B_F2_KEY: 
			Object->SetMode(1);
			break; 
		case B_F3_KEY: 
			Object->SetMode(2);
			break; 
		case B_F4_KEY: 
			Object->SetMode(3);
			break; 

	}

}
*/

