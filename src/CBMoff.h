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

#ifndef DEF_CBPARSER
#define DEF_CBPARSER

#include <vector>
#include "CBVertex.h"
#include "CBTriangle.h"
#include "CBBuffer.h"

const int Draw_Dot = 0,
	Draw_Wire = 1,
	Draw_Flat = 2,
	Draw_Gour = 3;

class Moff {
	public:

		Moff(char *, CBBuffer *b, const int &mode = Draw_Flat);
		~Moff();
		void SetMode(const int);
		void Roteer(const float&, const float&, const float&);
		void Roteer(const CBMatrix&);
		void Move(const CBVertex&);
		void Draw();

		void SetScale(float);

	private:

		CBBuffer *B;
		std::vector<CBTriangle> Driehoek;
		std::vector<CBVertex> *Vertex;
		
		float Scale;
		int mode;
		void DrawDot();
		void DrawWire();
		void DrawFlat();	
};


#endif //DEF_CBPARSER
