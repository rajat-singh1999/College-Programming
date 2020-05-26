#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void initialize()
{
	head = NULL;
}

void insertFirst()
{
	struct node *newnode;
	int i;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	i = scanf("%d", &i);
	newnode->data = i;
	newnode->next = head;
	head = newnode;
}

void display()
{
	if(head == NULL)
	{
		printf("No nodes to display");
	}
	else
	{
		struct node *p;
		p = head;
		while(p != NULL)
		{
			printf("%d->", p->data);
			p = p->next;
		}
	}
}

int main()
{
	initialize();
	insertFirst();
	display();
	return 0;
}
