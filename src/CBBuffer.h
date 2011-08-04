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

#ifndef DEF_CBBuffer
#define DEF_CBBuffer
#include "CBBitmap.h"
#include "CBTriangle.h"
#include "CBPoint.h"
#include <dfb++/dfb++.h>


	class CBBuffer {
		public :
			CBBuffer();
			~CBBuffer();
			void Clear();			
			void DrawDot(const float, const float, const float, rgb_color);
			void Line(int, int, int, int, rgb_color);
			void Point(CBPoint, rgb_color);
//			void DrawDot(CBTriangle);
//			void DrawWire(CBTriangle);
//			void DrawFlat(CBTriangle);
//			void DrawGourand(CBTriangle);
			void MakeReady();
			void Flip();
//			CBVertex light;
			int getWidth();
			int getHeight();
IDirectFBSurface *surface;
		private :
			//uint32*	Buffer_data;
			int width, height;
			//float *ZBuffer;
			//BView *work;
			IDirectFB *work;
			
	};
		
#endif
