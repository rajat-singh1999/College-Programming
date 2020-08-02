//#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

Node *head = new Node();

/*
int demo()
{
	Node *head = NULL;
	Node *second = NULL;
	Node *third = NULL;
	
	//allocate three nodes:
	head = new Node();
	second = new Node();
	third = new Node();
	
	head->data = 10;
	head->next = second;
	
	second->data = 20;
	second->next = third;
	
	third->data = 30;
	third->next = NULL;
	
	Node *temp = new Node();
	temp = head;
	
	cout << "\n";
	while(temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "\n";
	return 0;
}
*/

void show()
{
	if(head == NULL)
		cout << "No node to print.";
	else
	{
		Node *p = new Node();
		p = head;
		
		cout << "\n";
		while(p != NULL)
		{
			cout << p->data << "->";
			p = p->next;
		}
	}
		cout << "\n";
}

void insertFirst(int x)
{
	
	Node *newnode = new Node();
	newnode->data = x;

	if(head == NULL)
	{
		newnode->next = NULL;
		head = newnode;
		show();
	}
	else
	{
		newnode->next = head;
		head = newnode;
		show();
	}
}

void insertLast(int x)
{
	Node *newnode = new Node();
	if(head == NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
		head = newnode;
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		
		Node *p = new Node();
		p = head;
		while(p->next != NULL)
			p = p->next;
		p->next = newnode;
	}
}


int main()
{
	head = NULL;
	int ch, x;
	while(true)
	{
		cout << "Menu" << "\n" << "1. Display All Nodes\n" << "2. Insert at First.\n" << "3.Insert At Last\n" << "4. Exit\n";
		cout << "\nYour choice:";
		cin >> ch;
		switch(ch)
		{
			case 1:
				show();
				break;
			case 2:
				cout << "\nWhat to insert? ";
				cin >> x;
				insertFirst(x);
				show();
				break;
			case 3:
				cout << "\nWhat to insert? ";
				cin >> x;
				insertLast(x);
				show();
				break;
			case 4:
				cout << "\nWhat to insert? ";
				cin >> x;
				insertFirst(x);
				show();
				break;
			case 5:
				exit(0);
			default: cout << "\nWrong Choice!";
		}
	}
}







				





























