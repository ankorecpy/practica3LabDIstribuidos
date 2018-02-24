struct producto {
	char * codigo;
	char * nombre;
	int cantidad;
};

void insertar(char * codigo, char * nombre, int cantidad, int posicion, struct producto * listaProductos);
void actualizar(char * nuevoCodigo, char * nuevoNombre, int nuevaCantidad, int posicion, struct producto * listaProductos); 
