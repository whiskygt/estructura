#Funciona solo con Python ver2. 
#La version para Python ver3 se llamara node3.py

#Nodo

class Node:

	def __init__(self, data):
		self.data = data
		self.next = None
		self.previous = None

	def __str__(self):
		return str(self.data)

#Lista

class List:

	def __init__(self):
		self.first = None
		self.last = None
		self.size = 0

	def __str__(self):
		result = '['
		current = self.first
		for i in xrange(self.size):
			if i == self.size - 1:  result += str(current)
			else:
				result += str(current) + ", "
				current = current.next
		result += ']'
		return result

	def insertFirst(self, data):
		current = self.first
		newNode = Node(data)

		newNode.next = current
		newNode.previous = None
		newNode.next.previous = newNode
		self.first = newNode
		self.size = self.size + 1

	def insertLast(self, data):
		current = self.last
		newNode = Node(data)

		newNode.next = None
		newNode.previous = current
		newNode.previous.next = newNode
		self.last=newNode
		self.size = self.size + 1

	def insert(self, index, data):
		limit = min(self.size+1, index)
		print "El index es ", limit

		if self.size == 0:
			print "Lista vacia, agregando elemento."
			newNode = Node(data)
			self.first = self.last = newNode
			newNode.next = None
			newNode.previous = None
			self.size = self.size + 1

		else:
			if limit==1:
				print "Insertando al principio."
				self.insertFirst(data)

			else:
				if index !=1 and index>=self.size+1:
					print "Insertando al final."
					self.insertLast(data)
			
				else:
					if index!=1 or index<self.size+1:
						print "Insertando en ", index, " posicion."
						current = self.first
						newNode = Node(data)

						for i in xrange(index-1):
							current = current.next

						
						newNode.previous = current.previous
						newNode.next = current
						current.previous.next = newNode
						current.previous = newNode
			
						self.size = self.size + 1

	def delete(self, data):
		if(self.size == 0):
			print "La lista esta vacia."
		else:
			pos = self.searchItem(data)


	def searchItem(self, data):
		if(self.size == 0):
			print "La lista esta vacia"
			return 0
		else:
			i=1
			search = self.first

			while(search.data != data):
				search=search.next
				i = i + 1

			return i




