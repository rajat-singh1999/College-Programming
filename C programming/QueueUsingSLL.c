#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *f;
struct node *r;

void initialize()
{
	f = NULL;
	r = NULL;
}

void display()
{
	if(f == NULL && r == NULL)
		printf("\nUnderflow! List is empty!");
	else
	{
		struct node *p;
		p = f;
		while(p != NULL)
		{
			printf("%d->", p->data);
			p = p->next;
		}
	}
}

void push(int i)
{
	if(f == NULL && r == NULL)
	{
		struct node *newnode;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = i;
		newnode->next = NULL;
		f = newnode;
		r = newnode;
	}
	else
	{		
		struct node *newnode;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = i;
		newnode->next = NULL;
		r->next = newnode;
		r = newnode;
		if(f == NULL)
			f = newnode;
	}
	display();
}

void pop()
{
	if(f == NULL && r == NULL)
		printf("\nUnderflow! List is empty!");
	else
	{
		struct node *p;
		p = f;
		f = f->next;
		printf("\npoped %d\n", p->data);
		free(p);
		if(f == NULL && f != r)
			r = NULL;
	}
	display();
}
		
	
int main()
{
	initialize();
	int ch, n;
	while(1)
	{
		printf("\nMENU\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter a value to push: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default: printf("\nWrong Choice! Please stick to the menu!");
		}
	}
	return 0;
}

