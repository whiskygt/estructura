from doublenode import List

class Menu:
	def showMenu(self):
		list1 = List()
		print ""
		print "Menu de Lista, size de lista: ", list1.getSize()
		print ""
  	
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

  		choice = raw_input("Su opcion: ")
  		return choice

  	def add(self):
		data = raw_input("Inserte un valor: ")
		pos = raw_input("Inserte una posicion: ")
		pos = int(pos)
		list1.insert(pos, data)

	def remove(self):
		data = raw_input("Inserte el elemento que desea eliminar: ")
		list1.delete(data)

	def show(self):
		print(list1)

	def destroy(self):
		#EN DESARROLLO
		print "Aun no disponible"

	def save(self):
		#EN DESARROLLO
		print "Aun no disponible"

	def load(self):
		#EN DESARROLLO
		print "Aun no disponible"

	def exit(self):
		choice=int(7)



if __name__ == '__main__':
	
	choice = 0
	list1 = List()

	menu = Menu()

	options = {1 : menu.add,
                2 : menu.remove,
                3 : menu.show,
                4 : menu.destroy,
                5 : menu.save,
                6 : menu.load,
                7 : menu.exit,
	}

	while choice!=7:

		choice = menu.showMenu()
		choice = int(choice)
		options[choice]()

	flag = 1
	while flag!=0:
		data = raw_input("Inserte un valor: ")
		pos = raw_input("Inserte una posicion: ")
		pos = int(pos)
		list1.insert(pos, data)
		print(list1)
#		pos = list1.searchItem("arreglo")
#		print "Arreglo se encontro en la posicion ", pos
		flag = raw_input("Presione 0 para dejar de introducir datos, o presione 1 para seguir introduciendo: ")
		flag = int(flag)

	flag = 1
	while flag!=0:
		data = raw_input("Inserte el elemento que desea eliminar: ")
		list1.delete(data)
		print(list1)
		flag = raw_input("Presione 0 para dejar de eliminar datos: ")
		flag = int(flag)
	#print(list1)
	#list1.insert(6, 'hola')