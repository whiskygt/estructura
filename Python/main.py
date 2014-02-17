from doublenode import List
import sys

class Menu:
	
	list1 = List()
	def showMenu(self):
		
		print ""
		print "Menu de Lista"
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

  		print ""
  		choice = raw_input("Su opcion: ")
  		print ""
  		return choice

  	def add(self):
  		flag = 0
		data = raw_input("Inserte un valor: ")
		while flag == 0:
			try:
				pos = raw_input("Inserte una posicion: ")
				pos = int(pos)
				flag = 1
			except ValueError:
				print ""
	  			print "Introduzca solo numeros."
	  			useless = raw_input("Presione cualquier tecla para continuar: ")
	  			print ""
	  			flag = 0

		list1.insert(pos, data)
		print "Elemento insertado."
		print ""
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def remove(self):
		data = raw_input("Inserte el elemento que desea eliminar: ")
		list1.delete(data)

		useless = raw_input("Presione cualquier tecla para continuar: ")

	def show(self):
		print(list1)
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def destroy(self):
		print "Esta seguro que desea eliminar la lista?" 
		lastChance = raw_input("Presione Y para eliminarla o cualquier tecla para conservarla: ")
		if lastChance == 'Y' or lastChance == 'y':
			list1.destroy()
			print "Se ha eliminado la lista."
			useless = raw_input("Presione cualquier tecla para continuar: ")

		else:
			print "La lista no se ha eliminado."
			useless = raw_input("Presione cualquier tecla para continuar: ")

	def save(self):
		list1.saveFile()
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def load(self):
		list1.destroy()
		list1.readFile()
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def exit(self):
		sys.exit(0)



if __name__ == '__main__':
	
	choice = 0
	

	list1 = List()

	menu = Menu()

	optionsEmpty = {1 : menu.add,
					 2 : menu.load,
	}

	options = {1 : menu.add,
                2 : menu.remove,
                3 : menu.show, 
                4 : menu.destroy,
                5 : menu.save,
                6 : menu.load,
                7 : menu.exit
	}

	while choice!=7:
		flag = 0
		while flag == 0:
			try:
				choice = menu.showMenu()
				choice = int(choice)
				flag = 1
			except ValueError:
				print ""
				print "Introduzca solo numeros."
				useless = raw_input("Presione cualquier tecla para continuar: ")
				print ""
				flag = 0

		if list1.size==0:
			if choice == 3:
				choice = 7
			else:
				optionsEmpty[choice]()

		else:	
			options[choice]()