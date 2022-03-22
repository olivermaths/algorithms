#include <stdlib.h>
#include <stdio.h>
#define u16_int unsigned int
#define i16_int int

typedef struct Queue Queue;

extern Queue *createQueue();
extern void enqueue(Queue *queue, int element);
extern i16_int dequeue(Queue *queue);
extern i16_int get_element(Queue *queue, int index);
extern i16_int get_head(Queue *queue);
extern i16_int get_tail(Queue *queue);
extern i16_int get_size(Queue *queue);
extern i16_int isEmpty(Queue *queue);
extern void printQueue(Queue *queue);