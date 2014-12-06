#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class node
{
	int info;
	node *next;
 public:

	void insert(int x)
		{
			node *temp=new node;
			temp->info=x;
			temp->next=NULL;
			while(this->next!=NULL)
			{
				temp=temp->next;
			 }
			 node *p=new node;
			 p->next=this;






