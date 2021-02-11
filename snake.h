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
#ifndef SNAKE_H
#define SNAKE_H

#include "queue.h"

static const int SnakeDirectionLeft = 0;
static const int SnakeDirectionRight = 1;
static const int SnakeDirectionUp = 2;
static const int SnakeDirectionDown = 3;

extern Queue snakePositions;
extern int snakeDirection;

void snakePositionsInit();
void snakePositionsDestroy();

void snakePositionsReset();

#endif // SNAKE_H