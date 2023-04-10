#ifndef PRENDA_H
#define PRENDA_H

#include <map>
#include "PrendaFactory.h"

class Prenda
{
	friend class Camisa;
	friend class Pantalon;

public:
	static Prenda* pickup(int weaponSelected);
	static std::map<PrendaType, Prenda*> getConstants();
	const char* getName() const;
private:
	const char* m_name;
};
#endif 
