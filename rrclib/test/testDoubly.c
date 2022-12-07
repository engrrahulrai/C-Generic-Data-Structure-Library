#include<stdio.h>
#include<stdlib.h>
#include<rr_required.h>
#include<rr_doubly.h>
#include<string.h>
struct student
{
int rollNumber;
char *name;
};

void addStudent(doublyLinkedList *list)
{
int num,success;
struct student *s;
doublyLinkedListIterator *iterator;
int x,found;
char m,name[21];
if(list==NULL)return;
printf("enter roll number:");
scanf("%d",&num);
fflush(stdin);
if(num<0)
{
printf("Invalid roll number\n");
return;
}
iterator=getDoublyLinkedListIterator(list);
while(hasMoreElementInDoublyLinkedList(iterator))
{
s=getNextElementFromDoublyLinkedList(iterator);
if(num==s->rollNumber)
{
found=1;
break;
}
}
if(found==1)
{
printf("this roll number has already alloted to another one\n");
return;
}

printf("enter the name of student:");
fgets(name,21,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
printf("you want to save it Y/N:");
m=getchar();
if(m!='y' && m!='Y')
{
printf("entry is not added\n");
return;
}
s=(struct student *)malloc(sizeof(struct student));
if(s==NULL)
{
printf("Insufficient space\n");
return;
}
s->name=(char *)malloc(sizeof(char)*(strlen(name)+1));
if(s->name==NULL)
{
free(s);
printf("Isufficient space\n");
return;
}
s->rollNumber=num;
strcpy(s->name,name);
addToDoublyLinkedList(list,s,&success);
if(!success)
{
free(s->name);
free(s);
printf("student is not added\n");
return;
}
printf("student is added\n");

}

void editStudent(doublyLinkedList *list)
{
int roll,found;
doublyLinkedListIterator *iterator;
struct student *s;
char m,name[21];
printf("enter the roll number of student\n");
scanf("%d",&roll);
fflush(stdin);
iterator=getDoublyLinkedListIterator(list);
found=0;
while(hasMoreElementInDoublyLinkedList(iterator))
{
s=getNextElementFromDoublyLinkedList(iterator);
if(roll==s->rollNumber)
{
found=1;
break;
}
}
if(found==0)
{
printf("Invalid roll number press enter to continue\n");
getchar();
fflush(stdin);
return;
}
printf("%s\n",s->name);
printf("you want to edit (Y/N):");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student is not edited\n");
printf("press enter to continue\n");
getchar();
fflush(stdin);
return;
}
printf("enter the name:");
fgets(name,21,stdin);
name[strlen(name)-1]='\0';
fflush(stdin);
printf("you want to edit (Y/N):\n");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student is not edited\n");
return;
}
strcpy(s->name,name);
printf("student is edited\n");

}
void insertStudent(doublyLinkedList *list)
{
int nu,success,pos;
struct student *s;
doublyLinkedListIterator *iterator;
int x,found;
char m,nam[21];
if(list==NULL)return;
printf("enter roll number:");
scanf("%d",&nu);
fflush(stdin);
if(nu<0)
{
printf("Invalid roll number\n");
return;
}
iterator=getDoublyLinkedListIterator(list);
while(hasMoreElementInDoublyLinkedList(iterator))
{
s=getNextElementFromDoublyLinkedList(iterator);
if(nu==s->rollNumber)
{
found=1;
break;
}
}
if(found==1)
{
printf("this roll number has already alloted to another one\n");
return;
}

printf("enter the name of student:");
fgets(nam,21,stdin);
fflush(stdin);
nam[strlen(nam)-1]='\0';
printf("enter the position on which you want add an entry:");
scanf("%d",&pos);
fflush(stdin);
printf("you want to save it Y/N:");
m=getchar();
if(m!='y' && m!='Y')
{
printf("entry is not added\n");
return;
}
s=(struct student *)malloc(sizeof(struct student));
if(s==NULL)
{
printf("Insufficient space\n");
return;
}
s->name=(char *)malloc(sizeof(char)*(strlen(nam)+1));
if(s->name==NULL)
{
free(s);
printf("Isufficient space\n");
return;
}
s->rollNumber=nu;
strcpy(s->name,nam);
insertAtDoublyLinkedList(list,&s,pos,&success);
if(!success)
{
free(s->name);
free(s);
printf("unable to add an entry\n");
printf("press enter to continue.....\n");
getchar();
fflush(stdin);
return;
}
printf("student entry is added\n");

}

void removeStudent(doublyLinkedList *list)
{
int roll,found,j,success;
doublyLinkedListIterator *iterator;
struct student *s;
char m,name[21];
printf("enter the roll number of student\n");
scanf("%d",&roll);
fflush(stdin);
iterator=getDoublyLinkedListIterator(list);
found=0;
j=0;
while(hasMoreElementInDoublyLinkedList(iterator))
{
s=getNextElementFromDoublyLinkedList(iterator);
if(roll==s->rollNumber)
{
found=1;
break;
}
j++;
}
if(found==0)
{
printf("Invalid roll number press enter to continue\n");
getchar();
fflush(stdin);
return;
}
printf("%s\n",s->name);
printf("you want to remove (Y/N):\n");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("student entry is not deleted\n");
printf("press enter to continue.....\n");
getchar();
fflush(stdin);
return;
}
s=removeAtDoublyLinkedList(list,j,&success);
if(success==false)
{
printf("we are unable to delete the entry\n");
printf("press enter to continue...\n");
getchar();
fflush(stdin);
return;
}
printf("%d->%s\n",s->rollNumber,s->name);
printf("student entry is removed\n");
printf("press enter to continue....\n");
getchar();
fflush(stdin);



}

void displayStudent(doublyLinkedList *list)
{
struct student *t;
doublyLinkedListIterator *iterator;
if(list==NULL) return;
iterator=getDoublyLinkedListIterator(list);
while(hasMoreElementInDoublyLinkedList(iterator))
{
t=getNextElementFromDoublyLinkedList(iterator);
printf("%d->%s\n",t->rollNumber,t->name);
}

}



int main()
{
int s,i,ch;
doublyLinkedList *list=createDoublyLinkedList(&s);
if(!list)
{
printf("Insufficient space");
return 0;
}
while(1)
{
printf("1 for add any student\n");
printf("2 for edit any student entry\n");
printf("3 for insert at position\n");
printf("5 for remove any entry\n");
printf("6 for display list of student\n");
printf("7 for clear the list\n");
printf("8 for exit\n");
scanf("%d",&ch);
fflush(stdin);
if(ch<0 || ch>8)
{
printf("Invalid number:\n");
continue;
}
if(ch==1) addStudent(list);
if(list->count==0)
{
printf("you did not enter any entry\n");
continue;
}
if(ch==2) editStudent(list);
if(ch==3) insertStudent(list);
if(ch==5) removeStudent(list);

if(ch==6) displayStudent(list);


if(ch==8) break;




}





return 0;
}

