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


#include "CBMatrix.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

CBMatrix::CBMatrix()
{
	Reset();
}

CBMatrix::~CBMatrix()
{
	//	std::cout << "calling destr CBMatrix" << std::endl;
	//	delete []Matrix;
	//	std::cout << "end destr CBMatrix" << std::endl;
}

void CBMatrix::Reset(){
	Matrix[0][0] = 1.0;	Matrix[0][1] = 0.0;	Matrix[0][2] = 0.0;
	Matrix[1][0] = 0.0;	Matrix[1][1] = 1.0;	Matrix[1][2] = 0.0;
	Matrix[2][0] = 0.0;	Matrix[2][1] = 0.0;	Matrix[2][2] = 1.0;
}

CBMatrix& CBMatrix::MakeRotateX(const float alpha)
{
	float m_alpha = alpha * M_PI / 180.0;

	Matrix[0][0] = 1.0;	Matrix[1][0] = 0.0; 		Matrix[2][0] = 0.0;
	Matrix[0][1] = 0.0;	Matrix[1][1] = cos(m_alpha);	Matrix[2][1] = -sin(m_alpha);
	Matrix[0][2] = 0.0;	Matrix[1][2] = sin(m_alpha);	Matrix[2][2] = cos(m_alpha);

	return *this;
}

CBMatrix& CBMatrix::MakeRotateY(const float alpha)
{
	float m_alpha = alpha * M_PI / 180.0;

	Matrix[0][0] = cos(m_alpha);	Matrix[1][0] = 0.0;	Matrix[2][0] = sin(m_alpha);
	Matrix[0][1] = 0.0;		Matrix[1][1] = 1.0;	Matrix[2][1] = 0.0;
	Matrix[0][2] = -sin(m_alpha);	Matrix[1][2] = 0.0;	Matrix[2][2] = cos(m_alpha);

	return *this;
}

CBMatrix& CBMatrix::MakeRotateZ(const float alpha)
{
	float m_alpha = alpha * M_PI / 180.0;

	Matrix[0][0] = cos(m_alpha);	Matrix[1][0] = -sin(m_alpha);	Matrix[2][0] = 0.0;
	Matrix[0][1] = sin(m_alpha);	Matrix[1][1] = cos(m_alpha);	Matrix[2][1] = 0.0;
	Matrix[0][2] = 0.0;		Matrix[1][2] = 0.0;		Matrix[2][2] = 1.0;

	return *this;
}

CBMatrix CBMatrix::operator+(const CBMatrix& m2) const
{
	CBMatrix m;
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			m.Matrix[x][y] = Matrix[x][y] + m2.Matrix[x][y];
	return m;
}

CBMatrix CBMatrix::operator-(const CBMatrix& m2) const
{
	CBMatrix m;
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			m.Matrix[x][y] = Matrix[x][y] - m2.Matrix[x][y];
	return m;
}

CBMatrix CBMatrix::operator*(const CBMatrix& m2) const
{
	CBMatrix m;
	float tmp;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			tmp = 0.0;
			for(int k=0; k<3; k++)
				tmp += Matrix[i][k] * m2.Matrix[k][j];
			m.Matrix[i][j] = tmp;
		};

	return m;
}

CBMatrix& CBMatrix::operator+=(const float f){
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			Matrix[x][y] += f;

	return *this;
}

CBMatrix& CBMatrix::operator-=(const float f){
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			Matrix[x][y] -= f;

	return *this;
}

CBMatrix& CBMatrix::operator*=(const CBMatrix& m){
	CBMatrix m2;
	float tmp;
	for (int r=0; r <3; r++){
		for(int k=0; k<3; k++){
			tmp = 0.0;
			for (int i=0; i<3; i++)
				tmp+=m.Matrix[r][i]*Matrix[i][k];
			m2.Matrix[r][k]=tmp;
		}
	}
	*this = m2;
	return *this;
}

CBMatrix& CBMatrix::operator*=(const float f){
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			Matrix[x][y] *= f;

	return *this;
}

CBMatrix& CBMatrix::operator/=(const float f){
	if (f){
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				Matrix[x][y] /= f;

	}
	else
	{
		Reset();
	}
	return *this;
}

void CBMatrix::Transponeer(){
	CBMatrix m;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			m.Matrix[i][j] = Matrix[j][i];
	*this = m;
}

void CBMatrix::Invert(){
	Transponeer();
}

CBMatrix CBMatrix::Getransponeerde() const
{
	CBMatrix m;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			m.Matrix[i][j] = Matrix[j][i];

	return m;
}

CBMatrix CBMatrix::Inverted() const
{
	CBMatrix m;
	m = *this;
	m.Transponeer();
	return m;
}

std::ostream& operator<<(std::ostream& ost, const CBMatrix& m)
{
	ost << std::endl;
	ost.precision(4);
	
	//ost.width(20);
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			ost.precision(4);
			ost.width(20);
   			ost <<  m.Matrix[x][y];
		}

		ost << std::endl;
	}
	return ost;
 }


void CBMatrix::Print(){
	printf("%f  %f  %f\n%f  %f  %f\n%f  %f  %f\n\n\n",	Matrix[0][0], Matrix[0][1], Matrix[0][2], Matrix[1][0], Matrix[1][1], Matrix[1][2], Matrix[2][0], Matrix[2][1], Matrix[2][2]);
}
