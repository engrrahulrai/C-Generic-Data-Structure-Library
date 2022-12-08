# Generic-Data-Structure-Library-For-C
* Generic Data structure library for stack, Singly Linked List and Doubly Linked List in C. 
# To use it 
* include the header file rr_required.h and the file needed to you like rr_singly.h, rr_doubly.h, rr_stack.h
* call the initializing method and then call the methods for the operations you wanted to perform.
### To Compile the program type the command   
* gcc -static fileName.c -I  headerFileFolderLocation  -L libraryFileFolderLocation -l libraryFileName -o fileName.exe
### Example:- 
* I am in Test folder now wanted to compile the bst1.c file so, for that I will type this 
* gcc -static bst1.c -I ..\include -L ..\lib -l rrdslib -o bst3.exe


## Success
* It defines the operation is done successfully or not.

# Singly Linked List
### Declaration :
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

### Methods in it.
* singlyLinkedList *createSinglyLinkedList(int *success);
* void addToSinglyLinkedList(singlyLinkedList *sll,void *ptr,int *success);
* void insertAtSinglyLinkedList(singlyLinkedList *sll,void *ptr,int index,int *success);
* void *removeAtSinglyLinkedList(singlyLinkedList *sll,int index,int *success);
* void clearSinglyLinkedList(singlyLinkedList *sll);
* singlyLinkedList *getElementFromSinglyLinkedList(singlyLinkedList *sll,int index,int *success);
* void releaseSinglyLinkedList(singlyLinkedList *sll);
* singlyLinkedListIterator *getSinglyLinkedListIterator(singlyLinkedList *sll);
* int hasMoreElementInSinglyLinkedList(singlyLinkedListIterator *iterator);
* void *getNextElementFromSinglyLinkedList(singlyLinkedListIterator *iterator);
* void releaseSinglyLinkedListIterator(singlyLinkedListIterator *iterator);
* int getSizeOfSinglyLinkedList(singlyLinkedList *sll);


# Doubly Linked List
### Declaration 
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

### Methods
* doublyLinkedList *createDoublyLinkedList(int *success);
* void addToDoublyLinkedList(doublyLinkedList *dll,void *ptr,int *success);
* void insertAtDoublyLinkedList(doublyLinkedList *dll,void *ptr,int index,int *success);
* void *removeAtDoublyLinkedList(doublyLinkedList *dll,int index,int *success);
* void clearDoublyLinkedList(doublyLinkedList *dll);
* doublyLinkedList *getElementFromDoublyLinkedList(doublyLinkedList *dll,int index,int *success);
* void releaseDoublyLinkedList(doublyLinkedList *dll);
* doublyLinkedListIterator *getDoublyLinkedListIterator(doublyLinkedList *dll);
* int hasMoreElementInDoublyLinkedList(doublyLinkedListIterator *iterator);
* void *getNextElementFromDoublyLinkedList(doublyLinkedListIterator *iterator);
* void releaseDoublyLinkedListIterator(doublyLinkedListIterator *iterator);
* int getSizeOfDoublyLinkedList(doublyLinkedList *dll);

# Stack
### Declaration
typedef struct __$__stack
{
singlyLinkedList *list;
}stack;

### Methods
* stack *createStack(int *success);
* void pushToStack(stack *stack, void *ptr,int *success);
* void *popToStack(stack *stack, int *success);
* void clearStack(stack *stack);
* void releaseStack(stack *stack);
* int isStackIsEmpty(stack *stack,int *success);
* int getSizeOfStack(stack *stack);
* void *peekInStack(stack *stack,int *success);
