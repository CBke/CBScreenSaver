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

#ifndef DEF_CBVERTEX
#define DEF_CBVERTEX

#include "CBMatrix.h"
#include <iostream>

class CBVertex{
	public :
		float x, y, z;

		CBVertex(const CBVertex&);
		CBVertex(const float x = 0.0, const float y = 0.0, const float z = 0.0);
		CBVertex(std::ifstream &ff);
		
		~CBVertex();

		CBVertex& Set(const float, const float, const float);
		CBVertex& Normalize();
		CBVertex& Normalize(const CBVertex&);
		float Length() const;
		CBVertex& Inverse();
		float Sproduct(const CBVertex&)const;

		CBVertex operator+(const CBVertex&)const;
		CBVertex operator-(const CBVertex&)const;
		CBVertex operator*(const CBVertex&)const;
		CBVertex operator*(const float&)const ;
		CBVertex operator*(const CBMatrix&)const;
		CBVertex operator/(const float&)const ;
		CBVertex& operator=(const CBVertex&);
		CBVertex& operator+=(const CBVertex&);
		CBVertex& operator-=(const CBVertex&);
		CBVertex& operator*=(const CBVertex&);
		CBVertex& operator*=(const float&);
		CBVertex& operator*=(const CBMatrix&);
		CBVertex& operator/=(const float);
		bool operator==(const CBVertex&)const;
};
std::ostream& operator<< (std::ostream& , const CBVertex&);
#endif //DEF_CBVERTEX
