#ifndef __$__rr_stack_h
#define __$__rr_stack_h 2232
#include<rr_singly.h>
typedef struct __$__stack
{
singlyLinkedList *list;
}stack;

stack *createStack(int *success);
void pushToStack(stack *stack, void *ptr,int *success);
void *popToStack(stack *stack, int *success);
void clearStack(stack *stack);
void releaseStack(stack *stack);
int isStackIsEmpty(stack *stack,int *success);
int getSizeOfStack(stack *stack);
void *peekInStack(stack *stack,int *success);





#endif