class List:
	def __init__(self):
		self.next = None

class Data(List):
	def __init__(self, data):
		List.__init__(self)
		self.data = data;

	def __repr__(self):
		return 'Data(%r)'%self.data

class LinkedList:
	def __init__(self):
		self.first = None

	def append(self, data):
		current = self.first
		if not current: 
			self.first = data
			data.next = None
		
		else:
			while current.next:
				current = current.next

			current.next = data
			data.next = None

	def showList(self):
		print '[',
		current = self.first
		
		while current:
			print current, ',',
			current = current.next

		print ']'

	def __main__():		
		name = raw_input("Escriba cualquier cosa: ")
		data1 = Data(name)

		#data1 = "Prueba"
		list = LinkedList()
		list.append(data1)
		list.showList
		print "End"

name = raw_input("Escriba cualquier cosa: ")
data1 = Data(name)

#data1 = "Prueba"
list = LinkedList()
list.append(data1)
list.showList
# print "End"
# print "End"