/**********
 *
 *     Snake for TI-84
 *     by Marvin Manese
 *     
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>. 
 *
 **********/
#include <stdio.h>
#include "data_ports.h"
#include "game.h"
#include "extra_ti_func.h"

static void LcdBusyQuick()
{
	__asm
		call 0x000B
	__endasm;
}

void renderDrawPixel(unsigned long x, unsigned long y)
{
	unsigned long pos, maskCount, yMax;
	unsigned char mask;
	unsigned char* plotSScreen;

	maskCount = x % 2;
	x /= 2;
	y *= 4;
	yMax = y + 4;

	for(; y < yMax; ++y) {
		pos = x + y * 12;
		plotSScreen = (unsigned char*) 0x9340;
		mask = maskCount ? 0x0F : 0xF0;

		plotSScreen += pos;
		*plotSScreen |= mask;
	}
}

void renderClearScreen()
{
	int i, n;
	unsigned char* plotSScreen = (unsigned char*) 0x9340;

	for(i = 0, n = 12 * 64; i < n; ++i)
		*(plotSScreen++) = 0x00;
}

void renderDisplay()
{
	// __asm         
	// 	rst 0x28
	// 	.dw 0x486A
	// __endasm;
	unsigned char* plotSScreen = (unsigned char*) 0x9340;
	unsigned char* screen = plotSScreen;
	unsigned char c = 20 - 1;

	LCD_CMD_PORT = 0x80; // start at column 0
	for(;;) {
		c++;
		if(c > 0x2C)
			break;
		// LcdBusyQuick();
		LCD_CMD_PORT = c;

		screen = plotSScreen;
		screen += c - 20;
		for(int i = 0; i < 63; ++i) {
			// LcdBusyQuick();
			LCD_DATA_PORT = *screen;
			screen += 12; // the screen is row major, so increment by column size
		}

		// LcdBusyQuick();
		LCD_CMD_PORT = 0x80;
	}
}
