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

#include "CBVertex.h"
#include <math.h>
#include <stdio.h>
#include <string>
#include <fstream>

CBVertex::CBVertex(const float xp, const float yp, const float zp): x(xp), y(yp), z(zp)
{
}

CBVertex::CBVertex(const CBVertex& v)
{
	*this = v;
}

CBVertex::CBVertex(std::ifstream &ff)
{
	ff >> x >> y >> z;
}

CBVertex& CBVertex::Set(const float x, const float y, const float z)
{
	this->x = x; 
	this->y = y; 
	this->z = z;
	return *this;
}

CBVertex& CBVertex::Inverse()
{
	Set(-x, -y, -z);
	return *this;
}

float CBVertex::Length() const
{
	return	sqrt(x*x + y*y + z*z);
}

CBVertex& CBVertex::Normalize()
{
	float l = Length();
	if (l)
		Set(x/l, y/l, z/l);
	else
		Set(0.0, 0.0, 0.0);
	return *this;
}

CBVertex& CBVertex::Normalize(const CBVertex& v)
{
	*this = v;
	Normalize();
	return *this;
}

CBVertex CBVertex::operator+(const CBVertex& v)const
{
	return CBVertex(x+v.x, y+v.y, z+v.z);
}

CBVertex CBVertex::operator-(const CBVertex& v)const
{
	return CBVertex(x-v.x, y-v.y, z-v.z);
}

CBVertex& CBVertex::operator+=(const CBVertex& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

CBVertex& CBVertex::operator-=(const CBVertex& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

float CBVertex::Sproduct(const CBVertex &v) const
{
	return  x * v.x + y * v.y + z * v.z;
}

CBVertex& CBVertex::operator=(const CBVertex& v)
{
	Set(v.x, v.y, v.z);
	return *this;
}

CBVertex CBVertex::operator*(const CBVertex& v)const
{
	return  CBVertex((y*v.z)-(z*v.y), (z*v.x)-(x*v.z), (x*v.y)-(y*v.x));
}

CBVertex CBVertex::operator*(const CBMatrix& m)const
{
	return CBVertex(
			m.Matrix[0][0] * x + m.Matrix[1][0] * y + m.Matrix[2][0] * z,
			m.Matrix[0][1] * x + m.Matrix[1][1] * y + m.Matrix[2][1] * z,
			m.Matrix[0][2] * x + m.Matrix[1][2] * y + m.Matrix[2][2] * z);
}

CBVertex CBVertex::operator*(const float &f)const
{
	return CBVertex(x*f, y*f, z*f);
}

CBVertex& CBVertex::operator*=(const float &f)
{

	Set(x*f, y*f, z*f);

	return *this;
}

CBVertex& CBVertex::operator*=(const CBMatrix& m)
{
	Set(
		m.Matrix[0][0] * x + m.Matrix[1][0] * y + m.Matrix[2][0] * z,
		m.Matrix[0][1] * x + m.Matrix[1][1] * y + m.Matrix[2][1] * z,
		m.Matrix[0][2] * x + m.Matrix[1][2] * y + m.Matrix[2][2] * z);
	
	return *this;
}

CBVertex& CBVertex::operator/=(const float f)
{
	if (f)
		Set(x/f, y/f, z/f);
	else
		Set(0, 0, 0);
	return *this;
}

bool CBVertex::operator==(const CBVertex& v)const
{
	return  (v.x == x) && (v.y == y) && (v.z == z);
}


std::ostream& operator<<(std::ostream& ost, const CBVertex& v)
{
    ost <<  "x : " << v.x << "\ny : " << v.y << "\nz : " << v.z << std::endl;
    return ost;
 }

CBVertex::~CBVertex(){}
