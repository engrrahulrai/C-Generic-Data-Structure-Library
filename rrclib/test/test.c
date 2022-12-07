#include<stdio.h>
#include<stdlib.h>
#include<rr_required.h>
#include<rr_singly.h>
struct abc
{
int x,y;
char m;
};
int main()
{
int s,i;
struct abc a,b;
struct abc *t;
singlyLinkedListIterator *iii;
singlyLinkedList *list=createSinglyLinkedList(&s);
if(list==NULL)return 0;

a.x=10;
a.y=20;
a.m='a';
b.x=33;
b.y=229;
b.m='b';
addToSinglyLinkedList(list,&a,&s);
addToSinglyLinkedList(list,&b,&s);
iii=getSinglyLinkedListIterator(list);
while(hasMoreElementInSinglyLinkedList(iii))
{
t=getNextElementFromSinglyLinkedList(iii);
printf("%d %d %c\n",t->x,t->y,t->m);
}

releaseSinglyLinkedListIterator(iii);
return 0;
}



