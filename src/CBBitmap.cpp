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

#include "CBBitmap.h"

rgb_color::rgb_color(const int &r, const int &g, const int &b):red(r), green(g), blue(b){};
void rgb_color::Set(const int &r, const int &g, const int &b )
{
	red = r;
	green =g;
	blue = b;
	//return *this;
};
/*
int rgb_color::Red() const
{
	return red;
};
void rgb_color::Red(const int &r)
{
	red = r;
};
int rgb_color::Green() const
{
	return green;
};
void rgb_color::Green(const int &g)
{
	green = g;
};
int rgb_color::Blue() const
{
	return blue;
};
void rgb_color::Blue(const int &b)
{
	blue = b;
};
*/
