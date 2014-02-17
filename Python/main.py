from doublenode import List

class Menu:
	
	list1 = List()
	def showMenu(self):
		
		print ""
		print "Menu de Lista, size de lista: "
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
		data = raw_input("Inserte un valor: ")
		pos = raw_input("Inserte una posicion: ")
		pos = int(pos)
		list1.insert(pos, data)
		print "Elemento insertado."
		print ""
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def remove(self):
		data = raw_input("Inserte el elemento que desea eliminar: ")
		list1.delete(data)

		useless = raw_input("Presione cualquier tecla para continuar: ")

	def show(self):
		print ""
		print(list1)
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def destroy(self):
		print "Esta seguro que desea eliminar la lista?" 
		lastChance = raw_imput("Presione Y para eliminarla o cualquier tecla para conservarla: ")
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
		list1.readFile()
		useless = raw_input("Presione cualquier tecla para continuar: ")

	def exit(self):
		choice=int(7)



if __name__ == '__main__':
	
	choice = 0

	list1 = List()

	menu = Menu()

	optionsEmpty = {1 : menu.add,
					 2 : menu.load,
					 3 : menu.exit,
	}

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

		if list1.size==0:
			if choice == 3:
				choice = 7
			else:
				optionsEmpty[choice]()

		else:	
			options[choice]()

	#MAIN ANTIGUO
# 	flag = 1
# 	while flag!=0:
# 		data = raw_input("Inserte un valor: ")
# 		pos = raw_input("Inserte una posicion: ")
# 		pos = int(pos)
# 		list1.insert(pos, data)
# 		print(list1)
# #		pos = list1.searchItem("arreglo")
# #		print "Arreglo se encontro en la posicion ", pos
# 		flag = raw_input("Presione 0 para dejar de introducir datos, o presione 1 para seguir introduciendo: ")
# 		flag = int(flag)

# 	flag = 1
# 	while flag!=0:
# 		data = raw_input("Inserte el elemento que desea eliminar: ")
# 		list1.delete(data)
# 		print(list1)
# 		flag = raw_input("Presione 0 para dejar de eliminar datos: ")
# 		flag = int(flag)
	#print(list1)
	#list1.insert(6, 'hola')