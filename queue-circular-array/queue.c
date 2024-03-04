#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

struct Queue {
    Element* elements;
    int front;
    int back;
    int size;
    int capacity;
};

Queue* queue_create(int capacity) {
    Queue* queue = malloc(sizeof(Queue));

    queue->elements = malloc(capacity * sizeof(Element));
    queue->front = 0;
    queue->back = 0;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

void queue_destroy(Queue* queue) {
    free(queue->elements);
    free(queue);
}

bool queue_enqueue(Queue* queue, Element element) {
    if (queue_isFull(queue)) {
        return false;
    }
    queue->elements[queue->back] = element;
    queue->back = (queue->back + 1) % queue->capacity;
    queue->size++;

    return true;
}

Element queue_dequeue(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    Element element = queue->elements[queue->front];

    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return element;
}

Element queue_front(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }
    return queue->elements[queue->front];
}

Element queue_back(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }
    return queue->elements[queue->back];
}

int queue_size(Queue* queue) {
    return queue->size;
}

bool queue_isEmpty(Queue* queue) {
    return queue->size == 0;
}

bool queue_isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

void queue_print(Queue* queue) {
    for (int i = 0; i < queue->size; i++) {
        element_print(queue->elements[(queue->front + i) % queue->capacity]);
        printf(" ");
    }
    printf("\n");
}