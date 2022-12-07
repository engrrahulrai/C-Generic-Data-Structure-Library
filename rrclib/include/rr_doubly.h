#ifndef __$__rr_doubly_h
#define __$__rr_doubly_h 3334
struct __$__DLL_NODE 
{
void *ptr;
struct __$__DLL_NODE *next;
struct __$__DLL_NODE *previous;
};

typedef struct __$__doublyLinkedList
{
struct __$__DLL_NODE *start; 
struct __$__DLL_NODE *end;
int count;
}doublyLinkedList;

typedef struct __$__doublyLinkedListIterator
{
struct __$__DLL_NODE *node;
}doublyLinkedListIterator;

doublyLinkedList *createDoublyLinkedList(int *success);
void addToDoublyLinkedList(doublyLinkedList *dll,void *ptr,int *success);
void insertAtDoublyLinkedList(doublyLinkedList *dll,void *ptr,int index,int *success);
void *removeAtDoublyLinkedList(doublyLinkedList *dll,int index,int *success);
void clearDoublyLinkedList(doublyLinkedList *dll);
doublyLinkedList *getElementFromDoublyLinkedList(doublyLinkedList *dll,int index,int *success);
void releaseDoublyLinkedList(doublyLinkedList *dll);
doublyLinkedListIterator *getDoublyLinkedListIterator(doublyLinkedList *dll);
int hasMoreElementInDoublyLinkedList(doublyLinkedListIterator *iterator);
void *getNextElementFromDoublyLinkedList(doublyLinkedListIterator *iterator);
void releaseDoublyLinkedListIterator(doublyLinkedListIterator *iterator);
int getSizeOfDoublyLinkedList(doublyLinkedList *dll);
#endif