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

   implementation of rotation matrices only ...

*/

#ifndef DEF_MATRICES
#define DEF_MATRICES

#include <iostream>

class CBMatrix{
	public :

		float Matrix[3][3];

		CBMatrix ();
		~CBMatrix ();
		void Reset();

		CBMatrix& MakeRotateX(const float);
		CBMatrix& MakeRotateY(const float);	
		CBMatrix& MakeRotateZ(const float);

		CBMatrix operator+(const CBMatrix&) const;
		CBMatrix operator-(const CBMatrix&) const;
		CBMatrix operator*(const CBMatrix&) const;
		CBMatrix operator*(const float) const;

		CBMatrix& operator+=(const float);
		CBMatrix& operator-=(const float);
		CBMatrix& operator*=(const CBMatrix&);
		CBMatrix& operator*=(const float);
		CBMatrix& operator/=(const float);

		void Transponeer();
		void Invert();

		CBMatrix Getransponeerde() const;
		CBMatrix Inverted() const;
		void Print();

};
std::ostream& operator<< (std::ostream&, const CBMatrix&);
#endif //DEF_MATRICES
