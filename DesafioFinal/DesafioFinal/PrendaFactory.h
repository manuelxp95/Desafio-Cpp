#ifndef PRENDA_FACTORY_H
#define PRENDA_FACTORY_H
#include <map>

class Prenda;
enum class PrendaType { Camisa = 1, Pantalon};

class PrendaFactory
{
public:
	PrendaFactory();
	~PrendaFactory() = default;
	static Prenda* GetPrenda(PrendaType PrendaSelected);
	static std::map<PrendaType, Prenda*> getPrendaList();
};
#endif 