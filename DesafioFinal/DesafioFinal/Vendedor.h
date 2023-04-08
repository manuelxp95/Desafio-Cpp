#ifndef VENDEDOR_H
#define VENDEDOR_H
#include <string>

class Vendedor
{
private:
	std::string nombre;
	std::string apellido;
	int cod_vendedor;
public:
	Vendedor();
	int getCodigo();
	std::string getNombreyApellido();
};
#endif 
