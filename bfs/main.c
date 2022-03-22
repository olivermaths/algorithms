#include <stdio.h>
#include "src/queue/queue.h"

int main(void)
{
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    printQueue(queue);
    printf("\nthe tail is: %d\n", get_tail(queue));
    printf("\nthe size is: %d\n", get_size(queue));
}