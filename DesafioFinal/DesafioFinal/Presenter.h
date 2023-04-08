#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>
#include <vector>

class IView;
class Cotizador;
class Historial;
class Tienda;
class Vendedor;

class Presenter
{
private:
	IView* m_view = nullptr;
	Cotizador* m_cotizador = nullptr;
	Historial* m_historial = nullptr;
	Tienda* m_tienda = nullptr;
	Vendedor* m_vendedor = nullptr;
public:
	explicit Presenter(IView* view);
	//~Presenter();
	void pickupPrenda(int option);
	virtual void setPrendaType(std::string op, std::string op2);
	virtual void setPrendaType(std::string op);
	void getHistorialCotizaciones();
	void setCalidad(std::string op);
	void setPrecioUni(std::string op);
	void setCantidadPrendas(std::string optionString);
	void getListOfPrendas();
};
#endif //PRESENTER_H
