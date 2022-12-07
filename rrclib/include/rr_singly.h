#ifndef __$__rr_singly_h
#define __$__rr_singly_h 3334
struct __$__SLL_NODE 
{
void *ptr;
struct __$__SLL_NODE *next;
};

typedef struct __$__singlyLinkedList
{
struct __$__SLL_NODE *start; 
struct __$__SLL_NODE *end;
int count;
}singlyLinkedList;

typedef struct __$__singlyLinkedListIterator
{
struct __$__SLL_NODE *node;
}singlyLinkedListIterator;

singlyLinkedList *createSinglyLinkedList(int *success);
void addToSinglyLinkedList(singlyLinkedList *sll,void *ptr,int *success);
void insertAtSinglyLinkedList(singlyLinkedList *sll,void *ptr,int index,int *success);
void *removeAtSinglyLinkedList(singlyLinkedList *sll,int index,int *success);
void clearSinglyLinkedList(singlyLinkedList *sll);
singlyLinkedList *getElementFromSinglyLinkedList(singlyLinkedList *sll,int index,int *success);
void releaseSinglyLinkedList(singlyLinkedList *sll);
singlyLinkedListIterator *getSinglyLinkedListIterator(singlyLinkedList *sll);
int hasMoreElementInSinglyLinkedList(singlyLinkedListIterator *iterator);
void *getNextElementFromSinglyLinkedList(singlyLinkedListIterator *iterator);
void releaseSinglyLinkedListIterator(singlyLinkedListIterator *iterator);
int getSizeOfSinglyLinkedList(singlyLinkedList *sll);
#endif