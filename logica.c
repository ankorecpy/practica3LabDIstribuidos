#include "logica.h"
#include <string.h>

void insertar(char * codigo, char * nombre, int cantidad, int posicion, struct producto * listaProductos) {
	struct producto auxProducto;
	auxProducto.codigo = codigo;
	auxProducto.nombre = nombre;
	auxProducto.cantidad = cantidad;
	listaProductos[posicion] = auxProducto;
}

void actualizar(char * nuevoCodigo, char * nuevoNombre, int nuevaCantidad, int posicion, struct producto * listaProductos) {
	listaProductos[posicion].nombre = nuevoNombre;
	listaProductos[posicion].codigo = nuevoCodigo;
	listaProductos[posicion].cantidad = nuevaCantidad;
}

int obtenerIndiceProducto(char * codigo, int longitudLista, struct producto * listaProductos) {
	int posi = -1, auxComparacion = -1, resultado = -1, banderaSalida = 0;
	char * auxCodigo;
	for (posi = 0; posi < longitudLista && banderaSalida != 1; posi++) {
		auxCodigo = listaProductos[posi].codigo;
		auxComparacion = strcmp(auxCodigo, codigo);	
		if (auxComparacion == 0) {
			resultado = posi;
			banderaSalida = 1;
		}
	}
	return resultado;
}

