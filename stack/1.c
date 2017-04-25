#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct
{
    int* elems;
    int logLength;
    int allocLength;
} stack;

stack* StackNew()
{
    stack* s = malloc(sizeof(stack));
    s->allocLength = 4;
    s->elems = malloc(s->allocLength*sizeof(int));
    s->logLength = 0;

    assert(s->elems != NULL);

    return s;
}

void StackPush(stack* s, int val)
{
    if(s->logLength == s->allocLength)
    {
        s->allocLength *= 2;
        s->elems = realloc(s->elems, s->allocLength*sizeof(int));
    }

    s->elems[s->logLength] = val;
    s->logLength += 1;
}

int StackEmpty(stack* s)
{
    if(s->logLength == 0)
        return 1;
    return 0;
}

void StackPop(stack* s)
{
    if(StackEmpty(s))
        printf("Stack is empty\n");
    else
    {
        s->logLength -= 1;
        printf("%d\n", s->elems[s->logLength]);
    }
}

void StackDispose(stack* s)
{
    free(s->elems);
    free(s);
}

int main()
{
    stack* s = StackNew();
    StackPush(s, 1);
    StackPush(s, 2);
    StackPush(s, 3);
    StackPush(s, 4);
    StackPush(s, 5);
    StackPush(s, 6);
    StackPush(s, 7);
    StackPop(s);
    StackPop(s);
    StackPop(s);
    StackPop(s);
    StackPop(s);
    StackPop(s);
    StackPop(s);
    StackPop(s);

    StackDispose(s);

    return 0;
}
