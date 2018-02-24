#include <stdio.h>
#include <stdlib.h>
#include "logica.h"

#define MAX_NUM_PRO 3

void mostrarMenuRegistro(int posicionInsercion, struct producto * listaProductos); 
void mostrarMenuActualizacion(int longitud, struct producto * listaProductos); 
void mostrarProducto(int posicion, struct producto * listaProductos); 
void mostrarMenuBusqueda(int longitud, struct producto * listaProductos); 

void mostrarMenuInicio() {
	struct producto listaProductos[MAX_NUM_PRO];
	int opcion = -1, numIngresados = 0;
	do {
		printf("\nMenu.");
		printf("\n1- Ingresar Producto.");
		printf("\n2- Actualizar Producto.");
		printf("\n3- Mostrar Producto.");
		printf("\n0- Salir.");
		printf("\nDigite una opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				mostrarMenuRegistro(numIngresados, listaProductos);
				numIngresados++;
			break;
			case 2:
				mostrarMenuActualizacion(numIngresados, listaProductos);
			break;
			case 3:
				mostrarMenuBusqueda(numIngresados, listaProductos);
			break;
			default:
			break;
		}
	} while (opcion != 0);
}

void mostrarMenuRegistro(int posicionInsercion, struct producto * listaProductos) {
	char * codigo, * nombre; 
	int cantidad = -1;
	if (posicionInsercion < 3) {
		codigo = (char *)malloc(sizeof(char) * 10); 
		nombre = (char *)malloc(sizeof(char) * 10);
		printf("Nombre: ");
		scanf("%s", nombre);
		printf("Codigo: ");
		scanf("%s", codigo);
		printf("Cantidad: ");
		scanf("%d", &cantidad);
		insertar(codigo, nombre, cantidad, posicionInsercion, listaProductos);
	}
}

void mostrarMenuActualizacion(int longitud, struct producto * listaProductos) {
	char * codigo, * nombre; 
	int posicion = -1, cantidad = -1;
	codigo = (char *)malloc(sizeof(char) * 10); 
	printf("\nDigite el codigo del producto: ");
	scanf("%s", codigo);
	posicion = obtenerIndiceProducto(codigo, longitud, listaProductos);
	if (posicion != -1) {
		mostrarProducto(posicion, listaProductos);
		printf("\nNuevos Datos.\n");
		nombre = (char *)malloc(sizeof(char) * 10);
		printf("Nombre: ");
		scanf("%s", nombre);
		printf("Codigo: ");
		scanf("%s", codigo);
		printf("Cantidad: ");
		scanf("%d", &cantidad);
		actualizar(codigo, nombre, cantidad, posicion, listaProductos);
	} else {
		printf("Producto no encontrado");
	}
}

void mostrarProducto(int posicion, struct producto * listaProductos) {
	printf("\nInformacion de producto.");
	printf("\nNombre >> %s.", listaProductos[posicion].nombre);
	printf("\nCodigo >> %s.", listaProductos[posicion].codigo);
	printf("\nCantidad >> %d.", listaProductos[posicion].cantidad);
}

void mostrarMenuBusqueda(int longitud, struct producto * listaProductos) {
	char * codigo; 
	int posicion = -1;
	codigo = (char *)malloc(sizeof(char) * 10); 
	printf("\nDigite el codigo del producto: ");
	scanf("%s", codigo);
	posicion = obtenerIndiceProducto(codigo, longitud, listaProductos);
	if (posicion != -1) {
		mostrarProducto(posicion, listaProductos);
	} else {
		printf("Producto no encontrado");
	}
}
