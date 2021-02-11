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
#ifndef DATA_PORTS_H
#define DATA_PORTS_H

__sfr __at (0x1) KEY_PORT;				// Port to communicate with the keypards
__sfr __at (0x10) LCD_CMD_PORT;			// Port to communicate with the LCD Driver's status
__sfr __at (0x11) LCD_DATA_PORT;		// Port to communicate with teh LCD Driver
__sfr __at (0x20) LCD_DATA_COLUMN_0;

#endif // DATA_PORTS_H