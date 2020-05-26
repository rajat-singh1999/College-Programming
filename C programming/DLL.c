#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head = NULL;

void initialize()
{
	head = NULL;
}

void insertFirst(int i)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = i;
	newnode->next = NULL;
	
	if(head == NULL)
	{
		newnode->prev = NULL;
		head = newnode;
		}
	else
	{
		newnode->next = head;
		newnode->prev = NULL;
		head->prev = newnode;
		head = newnode;
	}
}

void insertEnd(int i)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		newnode->data = i;
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
	}
	else
	{
		newnode->data = i;
		newnode->next = NULL;
		struct node *p;
		p=head;
		while(p->next != NULL)
			p=p->next;
		p->next = newnode;
		newnode->prev = p;
	}
}

void deleteFirst()
{
	if(head == NULL)
		printf("No node to delete.");
	else if(head->next == NULL)
	{
		struct node *p;
		p = head;
		head = NULL;
		free(p);
	}
	else
	{
		struct node *p;
		p = head;
		head = head->next;
		free(p);
	} 
}

void deleteEnd()
{
	if(head == NULL)
		printf("No node to delete.");
	else if(head->next == NULL)
	{
		struct node *p;
		p = head;
		head = NULL;
		free(p);
	}
	else
	{
		struct node *p;
		p = head;
		while(p->next != NULL)
			p = p->next;
		p->prev->next = NULL;
		free(p);
	} 
}

void insertAfterGivenNode(int i)
{
	if(head == NULL)
	{
		printf("\nNode not present in the list.");
	}
	else
	{
		struct node *newnode, *p;
		p = head;
		int a;
		printf("\nEnter data: ");
		scanf("%d", &a);
		newnode = (struct node*)malloc(sizeof(struct node));
		while(p != NULL)
		{
			if(p->data == i)
			{
				break;
			}
			p = p->next;
		}
		if(p != NULL)
		{
			newnode->data = a;
			newnode->prev = p;
				
			if(p->next == NULL)
				newnode->next = NULL;
			else
				newnode->next = p->next;
			p->next = newnode;
		}
		else
			printf("\nNode not present in the list.");
	}
}

void insertBeforeGivenNode(int i)
{
	if(head == NULL)
	{
		printf("\nNode not present in the list.");
	}
	else
	{
		struct node *newnode, *p;
		p = head;
		int a;
		printf("\nEnter data: ");
		scanf("%d", &a);
		newnode = (struct node*)malloc(sizeof(struct node));
		while(p != NULL)
		{
			if(p->data == i)
			{
				break;
			}
			p = p->next;
		}
		if(p != NULL)
		{
			newnode->data = a;
			newnode->next = p;
			
			if(p->prev == NULL)
				newnode->prev = NULL;
			else
				newnode->prev = p->prev;
			p->prev = newnode;
			if(p == head)
				head = newnode;
			else
				newnode->prev->next = p->prev;
		}
		else
			printf("\nNode not present in the list.");
	}
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

void search(int i)
{
	if(head == NULL)
	{
		printf("No nodes to search in.");
	}
	else
	{
		struct node *p;
		p = head;
		while(p != NULL)
		{
			if(p->data == i)
				break;
			p = p->next;
		}
		if(p != NULL)
			printf("\nFound!");
		else
			printf("\nNot found!");
	}
}

void deleteAfterGivenNode(int i)
{
	if(head == NULL)
	{
		printf("\nNode not present in the list.");
	}
	else
	{
		struct node *p, *q;
		p = head;
		while(p != NULL)
		{
			if(p->data == i)
			{
				break;
			}
			p = p->next;
		}
		if(p != NULL)
		{
			if(p->next == NULL)
				printf("No node to delete.");
			else
			{
				q = p->next;
				if(p->next->next == NULL)
				{
					p->next = NULL;
					free(q);
				}
				else
				{
					p->next = q->next;
					q->next->prev = p;
					free(q);
				}
			}
		}
		else
			printf("\nNode not present in the list.");
	}
}

void deleteBeforeGivenNode(int i)
{
	if(head == NULL)
	{
		printf("\nNode not present in the list.");
	}
	else
	{
		struct node *p, *q;
		p = head;
		while(p != NULL)
		{
			if(p->data == i)
			{
				break;
			}
			p = p->next;
		}
		if(p != NULL)
		{
			q = p->prev;
			if(q == NULL)
				printf("No node to delete.");
			else
			{
				if(q == head)
				{
					p->prev = NULL;
					head = p;
					free(q);
				}
				else
				{
					p->prev = q->prev;
					q->prev->next = p;
					free(q);
				}
			}
		}
		else
			printf("\nNode not present in the list.");
	}
}

void count()
{
	if(head == NULL)
		printf("No nodes to count.");
	else
	{
		int c = 0;
		struct node *p;
		p = head;
		while(p != NULL)
		{
			c++;
			p = p->next;
		}
		printf("Number of nodes = %d", c);
	}
}

int main()
{
	int ch, n;
	while(1)
	{
		printf("\nMenu\n1.Insert at first\n2.Insert at end\n3.Delete from First\n4.Display\n5.Count\n6.Delete from last\n7.Insert after a given node\n8.Insert Before a Given node\n9.Delete after a given node\n10.Delete before a given node\n11.Search for a number\n0.Exit\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &n);
				insertFirst(n);
				break;
			case 2:
				printf("\nEnter data: ");
				scanf("%d", &n);
				insertEnd(n);
				break;
			case 3:
				deleteFirst();
				break;
			case 4:
				display();
				break;
			case 5:
				count();
				break;
			case 6:
				deleteEnd();
				break;
			case 7:
				printf("\nEnter data: ");
				scanf("%d", &n);
				insertAfterGivenNode(n);
				break;
			case 8:
				printf("\nEnter data: ");
				scanf("%d", &n);
				insertBeforeGivenNode(n);
				break;
			case 9:
				printf("\nEnter data: ");
				scanf("%d", &n);
				deleteAfterGivenNode(n);
				break;
			case 10:
				printf("\nEnter data: ");
				scanf("%d", &n);
				deleteBeforeGivenNode(n);
				break;
			case 11:
				printf("\nEnter data: ");
				scanf("%d", &n);
				display();
				search(n);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("\nWrong Choice!");
		}
	}				
	return 0;
}

