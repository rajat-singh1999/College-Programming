// Implementation of Circular Queue using Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void push(int x)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
		printf("\nQueue Overflow\n");
	else
	{	
		if(front == -1)
		{
			front = 0;
			rear = 0;
		}
		else
		{
			if(rear == MAX-1)
				rear = 0;
			else
				rear = rear + 1;
		}
		queue[rear] = x;
	}
}

int pop()
{
	if(front == -1)
	{
		printf("\nQUEUE UNDERFLOW\n");
		return -9999;
	}
	int x = queue[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	} 
	else
	{
		if(front == MAX-1)
			front = 0;
		else
			front = front + 1;
	}
	return x;
}		

void display()
{
	int f = front;
	int r = rear;
	if(front == -1)
		printf("\nQueueis empty.\n");
	else
	{
		if(f <= r)
		{
			while(f <= r)
			{
				printf("%d", queue[f]);
				f++;
			}
		}
		else
		{
			while(f <= MAX-1)
			{
				printf("%d ", queue[f]);
				f++;
			}
			f = 0;
			while(f <= r)
			{
				printf("%d ", queue[f]);
				f++;
			}
		}
		printf("\n");
	}
}

int main()
{
	int ch, n;
	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEmter the number you want to push: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				n = pop();
				if(n != -9999)
					printf("\nPoped %d\n", n);
				break;
			case 3:
				display();
				break;	
			case 4:
				exit(0);
				break;
			default: printf("\nWrong choice! Please stick to the list, don't improvise.\n");
		}
	}
	return 0;
}

