#include "Cotizador.h"
#include "Prenda.h"

const char* Cotizador::getCotizacion() {
	auto listOfClassConstants = Prenda::getConstants();
	m_view->setWeaponMenuItems(listOfClassConstants);
}