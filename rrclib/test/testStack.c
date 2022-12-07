#include<rr_required.h>
#include<rr_singly.h>
#include<rr_stack.h>
#include<stdio.h>
#include<stdlib.h>
struct abc
{
int x,y;
char m;
};
int main()
{
struct abc a,b;
int s,success;
struct abc *k;
stack *j=createStack(&s);
if(j==NULL)
{
printf("unable to create an stack:");
return 0;
}
a.x=19;
a.y=122;
a.m='a';
b.x=29;
b.y=3933;
b.m='e';
pushToStack(j,&a,&success);
pushToStack(j,&b,&success);

while(!isStackIsEmpty(j,&success))
{
k=popToStack(j,&success);
printf("%d %d %c\n",k->x,k->y,k->m);
}



return 0;
}