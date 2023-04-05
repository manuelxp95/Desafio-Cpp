#ifndef CAMISA_H
#define CAMISA_H

#include "Prenda.h"

enum tipoManga {
	MANGAS_CORTAS,
	MANGAS_LARGAS
};
enum tipoCuello {
	CUELLO_MAO,
	SIN_CUELLO_MAO
};

class Camisa: public Prenda
{
private:
	tipoManga tipo_Manga;
	tipoCuello tipo_Cuello;
public:
	Camisa();
	void setCamisaTipo(tipoManga tipo_M,tipoCuello tipo_C);
	//const char* shoot() override;
};
#endif //REVOLVER_H