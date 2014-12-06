#include<stdio.h>
#include<conio.h>
#include "alloc.h"
struct treenode
{
 int info;
 struct treenode *llink;
 struct treenode *rlink;
};
typedef struct treenode NODE;
NODE *root;

void create(int item)
{
 NODE *temp,*currptr,*ptr;
 temp=(NODE*)malloc(sizeof(NODE));
 temp->info=item;
 temp->llink=NULL;
 temp->rlink=NULL;
 if(root==NULL)
 root=temp;
 else
 {
 currptr=root;
 while(currptr!=NULL)
 {
  ptr=currptr;
  currptr=(item>currptr->info)?currptr->rlink:currptr->llink;
 }
 if(ptr->info<item)
 ptr->rlink=temp;
else

 ptr->llink=temp;
}
}
 void preorder(NODE*ptr)
 {
  if(ptr!=NULL)
  {
   printf("%d\t",ptr->info);
   preorder(ptr->llink);
   preorder(ptr->rlink);
  }
}
void inorder(NODE*ptr)
{
	if(ptr!=NULL)
  {
   inorder(ptr->llink);
	printf("%d\t",ptr->info);
	inorder(ptr->rlink);
  }
}
void postorder(NODE*ptr)
{
	if(ptr!=NULL)
  {

   postorder(ptr->llink);
	postorder(ptr->rlink);
	printf("%d\t",ptr->info);

  }
}
 void display(NODE*q,int level)
 {
 int i;
 if(q!=NULL)
 {
  display(q->rlink,level+1);
  for(i=1;i<level;i++)
  printf(" ");
  printf("%2d\n",q->info);
  display(q->llink,level+1);
 }
}
void main()
{
 int ele,i,n;
 clrscr();
 printf("enter how many nodes\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("enter the data for the node\n");
  scanf("%d",&ele);
  create(ele);
 }
 printf("binary tree");
 display(root,1);
 printf("\npreorder traversal\n");
 preorder(root);
 printf("\ninorder\n");
 inorder(root);
 printf("\npostorder\n");
 postorder(root);
 getch();
}




