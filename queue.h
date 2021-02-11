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
#ifndef QUEUE_H
#define QUEUE_H

#include "vector2.h"

struct QueueNodeC
{
	Vector2 			val;
	struct QueueNodeC* 	next;
	struct QueueNodeC* 	prev;
};

struct QueueC
{
	unsigned long 		size;
	struct QueueNodeC* 	front;
	struct QueueNodeC* 	back;
};

typedef struct QueueNodeC 	QueueNode;
typedef struct QueueC 		Queue;

void queueInit(Queue* q);
void queueDestroy(Queue* q);

void queuePush(Queue* q, Vector2* val);
void queuePop(Queue* q, Vector2* result);
void queueFront(Queue* q, Vector2* result);
void queueBack(Queue* q, Vector2* result);

#endif // QUEUE_H