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
#include <stdlib.h>
#include "game.h"
#include "gamefield.h"

unsigned char* gameField;

void gameFieldInit(bool withWalls)
{
	gameField = malloc(sizeof(unsigned char) * GAME_FIELD_WIDTH * GAME_FIELD_HEIGHT);
	gameFieldReset(withWalls);
}

void gameFieldReset(bool withWalls)
{
	unsigned long i, j;

	// initializte the values to 0
	for(j = 0; j < GAME_FIELD_HEIGHT; ++j) {
		for(i = 0; i < GAME_FIELD_WIDTH; ++i) {		
			gameFieldSetValue(i, j, VALUE_EMPTY_SPACE);
		}
	}

	if(withWalls) {
		// set walls to 1
		for(i = 0; i < GAME_FIELD_WIDTH; ++i) {
			gameFieldSetValue(i, 0, VALUE_WALL);
			gameFieldSetValue(i, GAME_FIELD_HEIGHT - 1, VALUE_WALL);
		}

		for(i = 0; i < GAME_FIELD_HEIGHT; ++i) {
			gameFieldSetValue(0, i, VALUE_WALL);
			gameFieldSetValue(GAME_FIELD_WIDTH - 1, i, VALUE_WALL);
		}
	}
}

void gameFieldDestroy()
{
	free(gameField);
}

void gameFieldSetValue(unsigned long x, unsigned long y, unsigned char val)
{
	gameField[x + (y * GAME_FIELD_WIDTH)] = val;
}

unsigned char gameFieldGetValue(unsigned long x, unsigned long y)
{
	return gameField[x + (y * GAME_FIELD_WIDTH)];
}