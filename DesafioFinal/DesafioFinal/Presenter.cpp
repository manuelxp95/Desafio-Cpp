#include "Presenter.h"
#include "IView.h"
#include "Cotizador.h"
#include "Prenda.h"
#include "Historial.h"

Presenter::Presenter(IView* view) : m_view(view), m_cotizador(new Cotizador()), m_historial(new Historial())
{
}

void Presenter::getListOfPrendas() {
	auto listOfClass = Prenda::getConstants();
	m_view->setPrendaMenuItem(listOfClass);
}


void Presenter::pickupPrenda(int option)
{
	std::system("cls");
	const char* behaviour = m_cotizador->pickupPrenda(option);
	if (behaviour == "Camisa") {
		m_view->showSubmenuCamisa();
	}
	else if (behaviour == "Pantalon") {
		m_view->showSubmenuPantalon();

	}
	m_view->showText(behaviour);
}

void Presenter::setPrendaType(std::string op) {
	m_cotizador->setPantalonType(op);
	m_view->showCalidadMenu();
}

void Presenter::setPrendaType(std::string op, std::string op2){
	m_cotizador->setCamisaType(op, op2);
	m_view->showCalidadMenu();
}

void Presenter::setCalidad(std::string optionString) {
	m_cotizador->setCalidad(optionString);
	m_view->showPrecioMenu();
}

void Presenter::setPrecioUni(std::string optionString) {
	m_cotizador->setPrecioUni(optionString);
	m_view->showCantidadMenu();//----------->if->Cantidad de stock disponible
}

void Presenter::setCantidadPrendas(std::string optionString) {
	m_cotizador->setCantidadPrendas(optionString);
	std::string resultCotizacion = m_cotizador->getCotizacion();
	m_historial->setHistorial(resultCotizacion);
	m_view->showResultCotizacion(resultCotizacion);
}

void Presenter::getHistorialCotizaciones() {
	auto historial = m_historial->getHistorial();
	m_view->setHistorial(historial);
};