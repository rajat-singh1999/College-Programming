#include<stdio.h>
#include<stdlib.h>

int que[100];
int f = -1;
int r = -1;

void display()
{
	if(f == -1 && r==-1)
		printf("\nQueue empty!");
	else
	{
		for(int i = f; i <= r; i++)
			printf("%d ", que[i]);
	}
}

void push(int x)
{
	if(r == 99)
		printf("\nOverflow!");
	else
	{
		if(f == -1)
			f = 0;
		r++;
		que[r] = x;
		display();
	}
}

int pop()
{
	int x;
	if(f == -1 && r==-1)
	{	
		printf("\nQueue empty!");
		x = -1;
	}
	else
	{
		x = que[f];
		f++;
		if(f >= r)
			r = f = -1;
		display();
	}
	return x;
}

int main()
{
	int ch;
	int n;
	
	while(1)
	{
		printf("\nMenu\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the number you want to push: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				n = pop();
				if(n != -1)
					printf("\n %d is popped.\n", n);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default: printf("\nWrong choice! Stick to the menu please!\n");
		}
	}
	return 0;
}
