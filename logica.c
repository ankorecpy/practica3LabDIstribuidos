#include "logica.h"

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

