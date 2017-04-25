#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int elems[100001];
    int top;
} stack;

void StackNew(stack* s)
{
    s->top = 0;
}

void StackPush(stack* s, int val)
{
    s->elems[s->top] = val;
    s->top += 1;
}

int StackPop(stack* s)
{
    s->top -= 1;
    return s->elems[s->top];
}

int StackEmpty(stack* s)
{
    if(s->top == 0)
        return 1;
    else
        return 0;
}

void StackPrint(stack* s)
{
    printf("%d\n", s->elems[s->top -1]);
}

typedef struct
{
    stack* a;
    stack* b;
} queue;

void QueueNew(queue* q)
{
    q->a = (stack*)malloc(sizeof(stack));
    q->b = (stack*)malloc(sizeof(stack));
    StackNew(q->a);
    StackNew(q->b);
}

void Enqueue(queue* q, int val)
{
    StackPush(q->b, val);
}

void Dequeue(queue* q)
{
    if(StackEmpty(q->a))
    {
        while(!StackEmpty(q->b))
        {
            StackPush(q->a, StackPop(q->b));
        }
    }
    StackPop(q->a);
}

void PrintTop(queue* q)
{
    if(StackEmpty(q->a))
    {
        while(!StackEmpty(q->b))
        {
            StackPush(q->a, StackPop(q->b));
        }
    }
    StackPrint(q->a);
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    


    queue q;
    QueueNew(&q);

    Enqueue(&q, 5);
    Enqueue(&q, 6);
    Enqueue(&q, 7);

    PrintTop(&q);
    PrintTop(&q);

    return 0;
}
