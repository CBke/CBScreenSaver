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

#include "CBTriangle.h"
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream> 


CBTriangle::CBTriangle(const int &v0, const int &v1, const int &v2, const rgb_color &c)
{
	Dot[0] = v0;
	Dot[1] = v1;
	Dot[2] = v2;
	norm.Normalize((Dot[2] - Dot[0]) * (Dot[1] - Dot[0]));
	col = c;
}

CBTriangle::CBTriangle(std::ifstream &ff, std::vector<CBVertex> *V)
{
	int i;

	ff >> i >> Dot[0] >> Dot[1] >> Dot[2];
	col.Set(255, 255, 255);
	Vertex = V;
}


CBTriangle::~CBTriangle(){
	// std::cout << "calling destr CBTriangle" << std::endl;
	// delete []Dot;
	// std::cout << "end destr CBTriangle" << std::endl;
}

float  CBTriangle::getDepth() const
{
	return ((*Vertex)[Dot[2]].z + (*Vertex)[Dot[1]].z + (*Vertex)[Dot[0]].z) / 3;
};

bool CBTriangle::operator<(const CBTriangle &b) const
{
	//std::cout << Vertex << "   *" << std::endl;
	return getDepth() < b.getDepth();
}

std::ostream& operator<<(std::ostream& ost, const CBTriangle& t)
{
    ost <<  "idx0 : " << t.Dot[0] << "\nidx1 : " << t.Dot[1] << "\nzidx2 : " << t.Dot[2] << std::endl;
    return ost;
 }
