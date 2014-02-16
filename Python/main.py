from doublenode import List

class Menu:
	def showMenu(self):
		list1 = List()
		print "Menu de Lista"
  	
  		if list1.size == 0:
  			print "1. Insertar un elemento."
  			print "2. Cargar lista."
  			print "3. Salir."

  		else:
  			print "1. Insertar un elemento."
  			print "2. Eliminar un elemento."
  			print "3. Mostrar lista."
  			print "4. Destruir lista."
  			print "5. Guardar lista."
  			print "6. Cargar lista."
  			print "7. Salir" 	

  		eleccion = raw_input("Su opcion: ")


if __name__ == '__main__':
	#node1 = Node('hola')
	list1 = List()
	menu = Menu()
	menu.showMenu()
	#list1.insert(1, 5)
	
	flag = 1
	while flag!=0:
		data = raw_input("Inserte un valor: ")
		pos = raw_input("Inserte una posicion: ")
		pos = int(pos)
		list1.insert(pos, data)
		print(list1)
		pos = list1.searchItem("arreglo")
		print "Arreglo se encontro en la posicion ", pos
		flag = raw_input("Presione 0 para dejar de introducir datos: ")
		flag = int(flag)
	#print(list1)
	#list1.insert(6, 'hola')