#include "Presenter.h"
#include "IView.h"
#include "Cotizador.h"
#include "Prenda.h"

Presenter::Presenter(IView* view) : m_view(view), m_cotizador(new Cotizador())
{
}

void Presenter::getListOfPrendas() {
	auto listOfClass = Prenda::getConstants();
	m_view->setPrendaMenuItem(listOfClass);
	//------> retornar a view
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

void Presenter::setPrendaType(std::string op, std::string op2) {
	m_cotizador->setCamisaType(op, op2);
	m_view->showCalidadMenu();
}

void Presenter::setCalidad(std::string optionString) {
	m_cotizador->setCalidad(optionString);
	m_view->showPrecioMenu();
}