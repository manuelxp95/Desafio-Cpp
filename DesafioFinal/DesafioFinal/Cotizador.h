#ifndef COTIZADOR_H
#define COTIZADOR_H
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

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
	std::string setFormato(double precioCotizacion, int cod_vendedor);
public:
	std::string getCotizacion(int cod_vendedor);
	std::vector<std::string> getPrendaActual();
	const char* pickupPrenda(int option);
	void setCamisaType(std::string op, std::string op2);
	void setPantalonType(std::string op);
	void setCalidad(std::string op);
	void setPrecioUni(std::string optionString);
	void setCantidadPrendas(std::string optionString);
	void AddString(const std::string& str);
};

#endif