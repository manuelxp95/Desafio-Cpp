#include "PrendaFactory.h"
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <algorithm>

PrendaFactory::PrendaFactory() = default;

Prenda* PrendaFactory::GetPrenda(PrendaType prendaSelected) {
	auto prendas = getPrendaList();
	if (prendas.count(prendaSelected) == 0) {
		return nullptr;
	}
	auto item = prendas[prendaSelected];
	return item;
}

std::map<PrendaType, Prenda*> PrendaFactory::getPrendaList()
{
	auto camisa = new Camisa();
	auto pantalon= new Pantalon();

	return std::map<PrendaType, Prenda*> {
		{ PrendaType::Revolver, revolver},
		{ PrendaType::Rifle,    rifle },
		{ PrendaType::Shotgun,  shotgun },
	};
}