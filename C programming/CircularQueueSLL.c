//Implementation of Circular Queue using liked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front, *rear;

void initialize()
{
	front = NULL;
	rear = NULL;
}

void display()
{
	struct node *temp = front;
	if(front == NULL)
		printf("\nQueue Empty\n");
	else
	{
		printf("\nCIRCULAR QUEUE : ");
		do
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}while (temp != front);
		printf("\n");
	}
}


void push(int x)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	if(front == NULL && rear == NULL)
	{
		front = newnode;
		rear = front;
		rear->next = front;
	}
	else
	{	
		rear->next = newnode;
		rear = newnode;
		rear->next = front;
	}
	display();
}

int pop()
{
	int x = -9999;
	struct node *p;
	if(front == NULL)
		printf("\nQueue Empty\n");
	else
	{
		if(front == rear)
		{
			p = front;
			front = rear = NULL;
		}
		else
		{	
			p = front;
			front = front->next;
			rear->next = front;
		}
		x = p->data;
		free(p);
	}
	display();
	return x;
}
		

int main()
{	
	initialize();
	int ch, n;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter a your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter a number to push: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				n = pop();
				if(n != -9999)
					printf("%d Popped\n", n);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default: printf("\nYou are dumb!\n");
		}
	}
	return 0;
}	

