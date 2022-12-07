#include<stdio.h>
#include<stdlib.h>
#include<rr_required.h>
#include<rr_stack.h>
struct Node
{
int num;
struct Node *right;
struct Node *left;
};
struct Node *root;

void insert(int num)
{
struct Node *t,*j;
if(root==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->right=NULL;
t->left=NULL;
root=t;
return;
}
j=root;
while(1)
{
if(num==j->num) return;
if(num<j->num)
{
if(j->left==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=NULL;
t->right=NULL;
j->left=t;
return;
}
else
{
j=j->left;
}

}
else
{
if(j->right==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->right=NULL;
t->left=NULL;
j->right=t;
return;
}
else
{
j=j->right;
}

}


}

}

void inOrderDisplay()
{
struct Node *t,*j;
int success;
stack *stack=createStack(&success);
if(!success)
{
printf("unable to create\n");
return;
}


for(t=root;t!=NULL;t=t->left)pushToStack(stack,t,&success);
while(!isStackIsEmpty(stack,&success))
{
j=(struct Node *)popToStack(stack,&success);
printf("%d\n",j->num);
for(t=j->right;t!=NULL;t=t->left)pushToStack(stack,t,&success);
}


}

void removeEntry(int num)
{
struct Node *t,*j,**p2p,*rr,*k;
if(root==NULL)
{
printf("you did not added any entry till now\n");
printf("press enter to continue.....\n");
getchar();
fflush(stdin);
}
t=root;
while(t!=NULL)
{
if(num==t->num)break;
j=t;
if(num<t->num) t=t->left;
else
{
t=t->right;
}
}
if(t==NULL)
{
printf("Invalid number\n");
printf("press enter to continue....\n");
getchar();
fflush(stdin);
return;
}
if(t==root) p2p=&root;
else
{
if(t==j->left) p2p=&(j->left);
else
{
p2p=&(j->right);
}
}
if(t->left==NULL && t->right==NULL)
{
*p2p=NULL;
free(t);
return;
}
if(t->right!=NULL)
{
for(k=t->right;k->left!=NULL;k=k->left)rr=k;
k->left=t->left;
if(t->right!=k)
{
rr->left=k->right;
k->right=t->right;
}
}
else
{
for(k=t->left;k->right!=NULL;k=k->right)rr=k;
k->right=t->right;
if(t->left!=k)
{
rr->right=k->left;
k->left=t->left;
}
}
*p2p=k;
free(t);
printf("entry is deleted\n");
printf("press enter to continue....\n");
getchar();
fflush(stdin);

}

int main()
{
int ch,num;
root=NULL;
while(1)
{
printf("1 for add\n");
printf("2 for remove\n");
printf("3 for Inorder display\n");
printf("4 for exit\n");
scanf("%d",&ch);
fflush(stdin);
if(ch<0 || ch>4)
{
printf("Invalid number");
continue;
}
if(ch==1)
{
printf("enter any Number:");
scanf("%d",&num);
fflush(stdin);
insert(num);
}
if(ch==2)
{
printf("enter the number you want to delete:");
scanf("%d",&num);
fflush(stdin);
 removeEntry(num);
}
if(ch==3) inOrderDisplay();
if(ch==4)break;

}



return 0;
}