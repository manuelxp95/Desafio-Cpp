#include "Cotizador.h"
#include "Prenda.h"

const char* Cotizador::getCotizacion() {
	auto listOfClassConstants = Prenda::getConstants();
	m_view->setWeaponMenuItems(listOfClassConstants);
}

void Cotizador::pickupPrenda(int option) {
	if(Prenda::pickup(option)){return}
}