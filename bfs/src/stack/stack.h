
#define u16_int unsigned int

typedef struct Stack Stack;

extern Stack *createStack(void);
extern void push_back(Stack *stack, int element);
extern void pop(Stack *stack);
extern int get_capacity(Stack *stack);
extern int s_getElement(Stack *stack, int index);