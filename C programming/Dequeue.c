#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int arr[MAX];
int r = -1;
int f = -1;

void display()
{
	if(f==-1)
		printf("\nQUEUE Empty\n");
	else
	{
		printf("\n");
		for(int i=f; i<=r; i++)
			printf("%d(%d) ", arr[i], i);
		printf("\n");
	}
}

void frontPush(int x)
{
	if(f==0 && r==MAX-1)
		printf("\nQUEUE FULL\n");
	else
	{
		if(f==-1)
		{
			f = 0;
			r = 0;
			arr[f] = x;
		}
		else
		{
			if(f==0)
			{
				for(int i=r+1; i>f; i--)
					arr[i] = arr[i-1];
				r++;
				arr[f] = x;
			}
			else
			{
				f--;
				arr[f] = x;
			}
		}
	}
	display();
}

void frontPop()
{
	if(f==-1)
		printf("\nQUEUE EMPTY\n");
	else
	{
		if(f==r)
		{
			printf("\nPOPPED %d\n", arr[f]);
			f = r = -1;
		}
		else
		{
			printf("\nPOPPED %d\n", arr[f]);
			f++;
		}
	}
	display();
}

void endPush(int x)
{
	if(f==0 && r==MAX-1)
		printf("\nQUEUE FULL\n");
	else
	{
		if(r==MAX-1)
		{
			for(int i=f-1; i<r; i++)
				arr[i] = arr[i+1];
			f--;
			arr[r] = x;
		}
		else
		{
			r++;
			arr[r] = x;
		}
	}
	display();
}

void endPop()
{
	if(f==-1)
		printf("\nQUEUE IS EMPTY\n");
	else
	{
		if(f==r)
		{
			printf("\nPOPPED %d\n", arr[r]);
			f = r = -1;
		}
		else
		{
			printf("\nPOPPED %d\n", arr[r]); 
			r--;
		}
	}
	display();
}

int main()
{
	int ch, n;
	while(1)
	{
		printf("\n1.FrontPush\n2.FrontPop\n3.EndPush\n4.EndPop\n5.Display\n6.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter value you want to push: ");
				scanf("%d", &n);
				frontPush(n);
				break;
			case 2:
				frontPop();
				break;
			case 3:
				printf("\nEnter value you want to push: ");
				scanf("%d", &n);
				endPush(n);
				break;
			case 4:
				endPop();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default: printf("\nWrong choice!\n");
		}
	}
	return 0;
}




