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
	scanf("%d", &i);
	if(head == NULL)
	{	
		newnode->data = i;
		newnode->next = NULL;
		head = newnode;
	}
	else
	{
		newnode->data = i;
		newnode->next = head;
		head = newnode;
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

void displayReserve()
{
	if(head == NULL)
		printf("\nNo node to display\n");
	else
	{
		struct node *p = head;
		int arr[100];
		int i = -1;
		while(p != NULL)
		{	
			i++;
			arr[i]	= p->data;
			p = p->next;
		}
		printf("\n");
		while(i >= 0)
		{
			printf("<-%d", arr[i]);
			--i;
		}
	}
}

void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}


int main()
{
	initialize();
	insertFirst();
	insertFirst();
	insertFirst();
	insertFirst();
	display();
	displayReserve();
	reverseList();
	display();
	return 0;
}
