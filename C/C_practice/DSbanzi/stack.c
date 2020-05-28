#include <stdio.h>
#include <malloc.h>
#define type int

struct listNode
{
    type data;
    struct listNode *next;
};

struct stack
{
    struct listNode *head;
    int length;
};

struct stack creatStack();
type pop(struct stack s);
type getTop(struct stack s);
int push(struct stack s, type value);
int isEmpty(struct stack s);
void makeEmpty(struct stack s);
void deleteStack(struct stack s);