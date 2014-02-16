#Nodo

class Node:

	def __init__(self, data):
		self.data = data
		self.next = None

	def __str__(self):
		return str(self.data)

#Lista

class List:

	def __init__(self):
		self.first = None
		self.last = None
		self.size = 0


	def insertFirst(self, data):
		current = self.first
		newNode = Node(data)
		newNode.next = current
		self.first = newNode
		self.size = self.size + 1

	def insertLast(self, data):
		current = self.last
		newNode = Node(data)
		current.next = newNode
		self.last=newNode
		self.size = self.size + 1

	def insert(self, index, data):

		limit = min(self.size, index)

		if self.size == 0:

			newNode = Node(data)
			self.first = self.last = newNode
			newNode.next = None

		else:
			if index==1:
				insertFirst(data)
			else:
				if index>=self.size+1:
					insertLast(data)
			
				else:
					current = self.first
					newNode = Node(data)
	
					for i in xrange(index):
						current = current.next

					newNode.next = current.next
					current.next = newNode
				
					self.size = self.size + 1




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




if __name__ == '__main__':
	#node1 = Node('hola')
	list1 = List()
	#list1.insert(1, 5)
	flag = 1
	while flag!=0:
		data = raw_input("Inserte un valor: ")
		pos = raw_input("Inserte una posicion: ")
		list1.insert(pos, data)
		print(list1)
		flag = raw_input("Presione 0 para dejar de introducir datos: ")

	#print(list1)
	#list1.insert(6, 'hola')