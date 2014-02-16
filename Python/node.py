#Funciona solo con Python ver2. 
#La version para Python ver3 se llamara node3.py

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
		print "Inicio1"
		current = self.first
		newNode = Node(data)
		newNode.next = current
		self.first = newNode
		self.size = self.size + 1
		print "Inicio2"

	def insertLast(self, data):
		print "Final1"
		current = self.last
		newNode = Node(data)
		current.next = newNode
		self.last=newNode
		self.size = self.size + 1
		print "Final2"

	def insert(self, index, data):


		limit = min(self.size+1, index)
		print "El index es ", limit

		if self.size == 0:
			print "Lista vacia, agregando elemento."
			newNode = Node(data)
			self.first = self.last = newNode
			newNode.next = None
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
						for i in xrange(index-2):
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
		pos = int(pos)
		list1.insert(pos, data)
		print(list1)
		flag = raw_input("Presione 0 para dejar de introducir datos: ")

	#print(list1)
	#list1.insert(6, 'hola')