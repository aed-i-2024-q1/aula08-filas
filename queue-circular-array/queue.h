#ifndef QUEUE_H
#define QUEUE_H

#include "element.h"

#include <stdbool.h>

typedef struct Queue Queue;

Queue* queue_create(int size);
void queue_destroy(Queue* queue);
bool queue_enqueue(Queue* queue, Element element);
Element queue_dequeue(Queue* queue);
Element queue_front(Queue* queue);
Element queue_back(Queue* queue);
int queue_size(Queue* queue);
bool queue_isEmpty(Queue* queue);
bool queue_isFull(Queue* queue);
void queue_print(Queue* queue);

#endif