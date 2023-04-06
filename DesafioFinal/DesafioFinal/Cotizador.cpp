#include "Cotizador.h"
#include "Prenda.h"

void Cotizador::AddString(const std::string& str) {
	prendaList.push_back(str);
}

const char* Cotizador::getCotizacion() {
	auto listOfClassConstants = Prenda::getConstants();
	//m_view->setWeaponMenuItems(listOfClassConstants);
	return "boca";
}

const char* Cotizador::pickupPrenda(int option) {

	auto prendaSelected = Prenda::pickup(option);
	
	if (prendaSelected->getName() == "Camisa") {
		return "Camisa";//-----------> Comportamiento de menu camisa
	}else if (prendaSelected->getName() == "Pantalon") {
		return "Pantalon";
	};
}

void Cotizador::setCamisaType(std::string op, std::string op2) {
	//if (Tienda::getPrendas().count > 0) {
	if (op == "1") {//------->camisa corta?
		AddString("MANGAS_CORTAS");
	}
	else {
		AddString("MANGAS_LARGAS");
	}
	if (op2 == "1") {//----------->camisa mao?
		AddString("CUELLO_MAO");
	}
	else {
		AddString("SIN_CUELLO_MAO");
	}
//	}
};

void Cotizador::setCalidad(std::string op) {
	if (op == "1") {
		AddString("Standard");
	}
	else {
		AddString("Premium");
	}
};