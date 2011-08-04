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

#include "CBMoff.h"

class CBScreenSaver
{
	public:
		CBScreenSaver();

		~CBScreenSaver();

//		virtual void StartConfig(BView *view);
//		virtual void StopConfig();
//		virtual void StopSaver();

		std::vector<Moff> Object;
		virtual void Draw();
CBBuffer Buffer;
		int i, x, y, b;
		int detail;
	private :
		
		

};

