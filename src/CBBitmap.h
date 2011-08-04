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

#ifndef DEF_CBBitmmap
#define DEF_CBBitmmap
class rgb_color {
	public:
		rgb_color(const int &r = 0, const int &g = 0, const int &b = 0);
		void Set(const int &r = 0, const int &g = 0, const int &b = 0);
/*
		int Red() const;
		void Red(const int &r);
		int Green() const;
		void Green(const int &g);
		int Blue() const;
		void Blue(const int &b);
	private :
*/
		int red;
		int green;
		int blue;
};
#endif //DEF_CBBitmmap	
