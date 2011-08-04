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

#ifndef DEF_CBTRIANGLE
#define DEF_CBTRIANGLE
#include "CBBitmap.h"
#include "CBVertex.h"
#include <vector>

class CBTriangle{
	public :
		CBTriangle(const int&, const int&, const int&, const rgb_color&);
		CBTriangle(std::ifstream &ff, std::vector<CBVertex> *Vertex);
		~CBTriangle();
		float getDepth() const;
		bool operator<(const CBTriangle &b) const;
		CBVertex norm;
		int Dot[3];
		rgb_color col; 
		std::vector<CBVertex> *Vertex;
};
std::ostream& operator<< (std::ostream& , const CBTriangle&);
#endif //DEF_CBTRIANGLE
