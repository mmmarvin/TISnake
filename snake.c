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
#include "game.h"
#include "gamefield.h"
#include "snake.h"

Queue snakePositions;
int snakeDirection;

void snakePositionsInit()
{
	queueInit(&snakePositions);
	snakePositionsReset();	
}

void snakePositionsDestroy()
{
	queueDestroy(&snakePositions);
}

void snakePositionsReset()
{
	Vector2 pos;

	queueDestroy(&snakePositions);
	snakeDirection = SnakeDirectionRight;

	pos.x = (GAME_FIELD_WIDTH / 2) - 2;
	pos.y = GAME_FIELD_HEIGHT / 2;
	queuePush(&snakePositions, &pos);
	gameFieldSetValue(pos.x, pos.y, VALUE_WALL);

	pos.x += 1;
	queuePush(&snakePositions, &pos);
	gameFieldSetValue(pos.x, pos.y, VALUE_WALL);

	pos.x += 1;
	queuePush(&snakePositions, &pos);
	gameFieldSetValue(pos.x, pos.y, VALUE_WALL);
}