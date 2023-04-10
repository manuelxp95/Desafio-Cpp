#ifndef PANTALON_H
#define PANTALON_H

#include "Prenda.h"

enum tipoPantalon {
	CHUPIN,
	NORMAL
};

class Pantalon : public Prenda
{
private:
	tipoPantalon tipo_pantalon;
public:
	Pantalon();
	void setPantalonTipo(tipoPantalon tipo_P);
};
#endif
