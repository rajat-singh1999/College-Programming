class Node:
	
	def __init__(self, data):
		self.data = data
		self.next = None
	
class LinkedList:
	
	def __init__(self):
		self.head = None
	
	def printList(self):
		
		temp = self.head
		
		while(temp):
			print(f"{temp.data}->", end=" ")
			temp = temp.next
		
	def insertFirst(self, x):
		if self.head == None:
			self.head = Node(x)
		else:
			newnode = Node(x)
			newnode.next = self.head
			self.head = newnode
		self.printList()
	
	def insertLast(self, x):
		if self.head == None:
			self.head = Node(x)
		else:
			newnode = Node(x) 
			p = self.head
			while p.next != None:
				p = p.next
			p.next = newnode
		self.printList()
		
	def deleteFirst(self):
		if self.head == None:
			print("No node to delete!")
		else:
			self.head = self.head.next
		self.printList()

	def deleteLast(self):
		if self.head == None:
			print("No node to delete!")
		else:
			p = self.head
			while p.next.next != None:
				p = p.next
			p.next = None
		self.printList()
	
	def physicalReverse(self):
		l = []
		p = self.head
		while p != None:
			l.append(p.data)
			p = p.next
		l.reverse()
		p = self.head
		
		i=0
		while p != None:
			p.data = l[i]
			p = p.next
			i = i + 1
		self.printList()	
			
if __name__=='__main__':
	
	llist = LinkedList()
	
	llist.printList()
	llist.insertFirst(10)
	print()
	llist.insertFirst(20)
	print()
	llist.insertFirst(30)
	print()
	llist.insertLast(40)
	print()
	llist.insertLast(50)
	print()
	llist.insertLast(60)
	print()
	llist.physicalReverse()
	print()
	llist.deleteFirst()
	print()
	llist.deleteFirst()
	print()
	llist.deleteLast()
	print()
	llist.deleteLast()
	print()
	llist.deleteLast()
	print()







