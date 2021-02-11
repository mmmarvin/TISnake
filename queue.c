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
#include "queue.h"

void queueInit(Queue* q)
{
	q->size = 0;
	q->front = NULL;
	q->back = NULL;
}

void queueDestroy(Queue* q)
{
	Vector2 garbage;
	while(q->size)
		queuePop(q, &garbage);
}

void queuePush(Queue* q, Vector2* val)
{
	if(!q->size) {
		q->front = malloc(sizeof(QueueNode));
		q->front->val = *val;
		q->front->prev = NULL;
		q->front->next = NULL;
		q->back = q->front;
	} else {
		q->back->next = malloc(sizeof(QueueNode));
		q->back->next->val = *val;
		q->back->next->prev = q->back;
		q->back->next->next = NULL;
		q->back = q->back->next;
	}

	++q->size;
}

void queuePop(Queue* q, Vector2* result)
{
	QueueNode* temp;

	if(q->size) {
		temp = q->front;

		if(q->size == 1) {
			q->front = q->back = NULL;
		} else {
			q->front = q->front->next;
			q->front->prev = NULL;
		}

		*result = temp->val;
		free(temp);
		--q->size;
	}
}

void queueFront(Queue* q, Vector2* result)
{
	*result = q->front->val;
}

void queueBack(Queue* q, Vector2* result)
{
	*result = q->back->val;
}