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
#ifndef GAMEFIELD_H
#define GAMEFIELD_H

static const unsigned long GAME_FIELD_WIDTH = 24;
static const unsigned long GAME_FIELD_HEIGHT = 16;

extern unsigned char* gameField;

void gameFieldInit(bool withWalls);
void gameFieldReset(bool withWalls);
void gameFieldDestroy();

void gameFieldSetValue(unsigned long x, unsigned long y, unsigned char val);
unsigned char gameFieldGetValue(unsigned long x, unsigned long y);

#endif // GAMEFIELD_H