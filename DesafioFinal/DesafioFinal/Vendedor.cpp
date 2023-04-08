#include "Vendedor.h"

Vendedor::Vendedor() {//->inicializacion ficticia
	nombre = "Pablo";
	apellido = "Perez";
	cod_vendedor = 001;
}

int Vendedor::getCodigo() {
	return cod_vendedor;
}

std::string Vendedor::getNombreyApellido() {
	return (nombre + " " + apellido);
}