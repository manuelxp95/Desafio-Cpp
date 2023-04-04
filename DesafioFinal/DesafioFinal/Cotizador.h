#ifndef COTIZADOR_H
#define COTIZADOR_H
#include <chrono>
#include <ctime>
#include <iomanip>

class Vendedor;

class Cotizador {
private:
	int id;
	struct fechaHora {
		std::chrono::system_clock::time_point momento;
	};
	int cantidad;
	double result;
	std::shared_ptr<Vendedor> m_Vendedor;
public:
	const char* getCotizacion();
};

#endif