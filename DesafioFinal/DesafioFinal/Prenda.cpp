#include "Prenda.h"
#include "PrendaFactory.h"

std::map<PrendaType, Prenda*> Prenda::getConstants()
{
	return PrendaFactory::getPrendaList();
}

const char* Prenda::getName() const
{
	return m_name;
}

Prenda* Prenda::pickup(int option) {
	return PrendaFactory::GetPrenda((PrendaType) option);

}
