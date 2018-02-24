#Creado por: Alejandro Méndez Astudillo.

#Asignacion de variables.
COMPILADOR = gcc
BANDERAS = -Wall -O2
FUENTES = main.c logica.c logica.h menu.c
OBJETO =  main.o logica.o menu.o

all: $(OBJETO)
	$(COMPILADOR) $(BANDERAS) -o ejecutable $(OBJETO)

clean: 
	$(RM) $(OBJETO)

main.o: main.c logica.h  
logica.o: logica.c
menu.o: menu.c
