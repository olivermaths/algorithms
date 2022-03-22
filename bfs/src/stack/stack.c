#include "stack.h"
#include <stdlib.h>

typedef struct Stack
{
    u16_int size;
    u16_int capacity;
    int *array;
} Stack;

Stack *createStack()
{
    Stack *stack = malloc(sizeof(stack));
    stack->size = 2;
    stack->capacity = 0;
    stack->array = malloc(sizeof(int) * 2);
    stack->array[0] = 0;
    stack->array[1] = 0;
    return stack;
}
void push_back(Stack *stack, int element)
{
    if (stack->capacity == stack->size)
    {
        stack->size *= 2;
        stack->array = realloc(stack->array, stack->size * sizeof(int));
    }

    stack->array[stack->capacity] = element;
    stack->capacity += 1;
};
void pop(Stack *stack)
{
    stack->capacity -= 1;
    stack->array[stack->capacity] = 0;
};

int get_capacity(Stack *stack)
{
    return stack->capacity;
}
int s_getElement(Stack *stack, int index)
{
    if (index <= stack->capacity)
    {
        return stack->array[index];
    }
    return 0;
}