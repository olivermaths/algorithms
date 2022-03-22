#include "queue.h"

typedef struct Queue
{
    i16_int head;
    i16_int tail;
    i16_int size;
    i16_int *queue;
} Queue;

Queue *createQueue(void)
{
    Queue *queue = malloc(sizeof(queue));
    queue->size = 2;
    queue->head = queue->tail = -1;
    queue->queue = malloc(sizeof(int) * 2);
    queue->queue[0] = 0;
    queue->queue[1] = 0;
    return queue;
}

i16_int isEmpty(Queue *queue)
{

    if (queue->tail == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *queue, int element)
{
    if (queue->head < 0)
    {
        queue->head = 0;
    }

    if ((queue->tail + 1) == queue->size)
    {
        queue->size *= 2;
        queue->queue = realloc(queue->queue, queue->size * sizeof(int));
    }

    queue->tail += 1;
    queue->queue[queue->tail] = element;
};

i16_int dequeue(Queue *queue)
{

    int element;
    if (isEmpty(queue))
    {
        return -1;
    }
    else
    {
        element = queue->queue[queue->head];
        queue->head += 1;
        if (queue->head > queue->tail)
        {
            printf("\nresetting queue\n");
            queue->head = queue->tail = -1;
        }
    }
    return element;
}

void printQueue(Queue *queue)
{
    printf("\n");

    for (int i = queue->head; i <= queue->tail; i++)
    {
        printf("%d, ", queue->queue[i]);
    }
    printf("\n");
}

i16_int get_head(Queue *queue)
{
    return queue->queue[queue->head];
};

i16_int get_tail(Queue *queue)
{
    return queue->queue[queue->tail - 1];
};

i16_int get_element(Queue *queue, int index)
{
    if (index >= queue->head && index <= queue->tail)
    {
        return queue->queue[index];
    }
    return 0;
};

i16_int get_size(Queue *queue)
{
    return queue->size;
};
