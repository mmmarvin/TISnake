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
#pragma less_pedantic

#include <stdlib.h>
#include <stdint.h>
#include "extra_ti_func.h"
#include "keyboard.h"
#include "game.h"
#include "gamefield.h"
#include "snake.h"

static bool gameOver = false;

static void gameCreateRandomFood()
{
	unsigned char v;
	long nx, ny;

	nx = rand() % GAME_FIELD_WIDTH;
	ny = rand() % GAME_FIELD_HEIGHT;
	v = gameFieldGetValue(nx, ny);
	while(v != VALUE_EMPTY_SPACE) {
		nx = rand() % GAME_FIELD_WIDTH;
		ny = rand() % GAME_FIELD_HEIGHT;
		v = gameFieldGetValue(nx, ny);
	}
	
	gameFieldSetValue(nx, ny, VALUE_FOOD);
}

static void gameRender()
{
	renderClearScreen();

	for(unsigned long j = 0; j < GAME_FIELD_HEIGHT; ++j) {
		for(unsigned long i = 0; i < GAME_FIELD_WIDTH; ++i) {
			if(gameFieldGetValue(i, j) != VALUE_EMPTY_SPACE)
				renderDrawPixel(i, j);
		}
	}
	
	renderDisplay();
}

static void gameUpdate()
{
	unsigned char v;
	Vector2 snakeHeadPosition = { 0, 0 };

	if(!gameOver) {
		queueBack(&snakePositions, &snakeHeadPosition);

		if(snakeDirection == SnakeDirectionLeft)
			--snakeHeadPosition.x;
		else if(snakeDirection == SnakeDirectionRight)
			++snakeHeadPosition.x;
		else if(snakeDirection == SnakeDirectionUp)
			--snakeHeadPosition.y;
		else if(snakeDirection == SnakeDirectionDown)
			++snakeHeadPosition.y;

		if(snakeHeadPosition.x < 0)
			snakeHeadPosition.x = GAME_FIELD_WIDTH - 1;
		else if(snakeHeadPosition.x > GAME_FIELD_WIDTH - 1)
			snakeHeadPosition.x = 0;
		else if(snakeHeadPosition.y < 0)
			snakeHeadPosition.y = GAME_FIELD_HEIGHT - 1;
		else if(snakeHeadPosition.y > GAME_FIELD_HEIGHT - 1)
			snakeHeadPosition.y = 0;

		v = gameFieldGetValue(snakeHeadPosition.x, snakeHeadPosition.y);
		if(v != VALUE_WALL) {
			gameFieldSetValue(snakeHeadPosition.x, snakeHeadPosition.y, VALUE_WALL);
			queuePush(&snakePositions, &snakeHeadPosition);

			if(v == VALUE_EMPTY_SPACE) {
				queuePop(&snakePositions, &snakeHeadPosition);
				gameFieldSetValue(snakeHeadPosition.x, snakeHeadPosition.y, VALUE_EMPTY_SPACE);
			} else {
				gameCreateRandomFood();
			}
		} else
			gameOver = true;
	}
}

static bool gameHandleInput(bool withWalls)
{
	unsigned char k;

	if(!gameOver) {
		k = isKeyPressed(0xFE);
		if(k == 0xF7) {
			// up
			if(snakeDirection != SnakeDirectionDown)
				snakeDirection = SnakeDirectionUp;
		} else if(k == 0xFE) {
			// down
			if(snakeDirection != SnakeDirectionUp)
				snakeDirection = SnakeDirectionDown;
		} else if(k == 0xFD) {
			// left
			if(snakeDirection != SnakeDirectionRight)
				snakeDirection = SnakeDirectionLeft;
		} else if(k == 0xFB) {
			// right
			if(snakeDirection != SnakeDirectionLeft)
				snakeDirection = SnakeDirectionRight;
		} else {
			if(isKeyPressed(0xFD) == 0xBF) {
				return true;
			}
		}
	} else {
		if(isKeyPressed(0xFD) == 0xFE) {
			if(gameOver) {
				gameOver = false;
				gameFieldReset(withWalls);
				snakePositionsReset();
				gameCreateRandomFood();
			}
		} else if(isKeyPressed(0xFD) == 0xBF) {
				return true;
		}
	}

	return false;
}

void gameRun(bool withWalls)
{
	bool exitKeyPressed = false;
	srand(164351);

	gameFieldInit(withWalls);
	snakePositionsInit();

	gameCreateRandomFood();
	while(!exitKeyPressed) {
		gameUpdate();
		gameRender();	

		exitKeyPressed = gameHandleInput(withWalls);
	}
	
	snakePositionsDestroy();
	gameFieldDestroy();
}