#ifndef COTIZADOR_H
#define COTIZADOR_H
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>

class Vendedor;

class Cotizador {
private:
	int id;
	std::vector<std::string> prendaList;
	struct fechaHora {
		std::chrono::system_clock::time_point momento;
	};
	int cantidad;
	double result;
	std::shared_ptr<Vendedor> m_Vendedor;
public:
	const char* getCotizacion();
	const char* pickupPrenda(int option);
	void setCamisaType(std::string op, std::string op2);
	void setCalidad(std::string op);
	void AddString(const std::string& str);
};

#endif