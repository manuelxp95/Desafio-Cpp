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
	m_view->showText(behaviour);
}