#include "Tienda.h"

Tienda::Tienda() { //------->inicializacion ficticia
	//nombres y direcciones
	nombreTienda = "Tienda One";
	direccionTienda = "Av. Peperonni 123";

	// Cargar datos de camisas
	inventario.camisa.total = 1000;
	inventario.camisa.mangaCorta.total = 500;
	inventario.camisa.mangaCorta.cuelloMao.total = 200;
	inventario.camisa.mangaCorta.cuelloMao.standard = 100;
	inventario.camisa.mangaCorta.cuelloMao.premium = 100;
	inventario.camisa.mangaCorta.cuelloComun.total = 300;
	inventario.camisa.mangaCorta.cuelloComun.standard = 150;
	inventario.camisa.mangaCorta.cuelloComun.premium = 150;
	inventario.camisa.mangaLarga.total = 500;
	inventario.camisa.mangaLarga.cuelloMao.total = 150;
	inventario.camisa.mangaLarga.cuelloMao.standard = 75;
	inventario.camisa.mangaLarga.cuelloMao.premium = 75;
	inventario.camisa.mangaLarga.cuelloComun.total = 350;
	inventario.camisa.mangaLarga.cuelloComun.standard = 175;
	inventario.camisa.mangaLarga.cuelloComun.premium = 175;

	// Cargar datos de pantalones
	inventario.pantalon.total = 2000;
	inventario.pantalon.chupin.total = 1500;
	inventario.pantalon.chupin.standard = 750;
	inventario.pantalon.chupin.premium = 750;
	inventario.pantalon.comun.total = 500;
	inventario.pantalon.comun.standard = 250;
	inventario.pantalon.comun.premium = 250;
}

std::string Tienda::getDireccion() {
	return direccionTienda;
};

std::string Tienda::getNombre() {
	return nombreTienda;
};

int Tienda::getStock(std::vector<std::string> prendaActual) {
	if (prendaActual[0] == "MANGAS_CORTAS") {
		if (prendaActual[1] == "CUELLO_MAO") {
			if (prendaActual[2] == "Standard") { 
				return inventario.camisa.mangaCorta.cuelloMao.standard; 
			}else{
				return inventario.camisa.mangaCorta.cuelloMao.premium;
			}
		}
		else {

		}
	}else if (prendaActual[0] == "MANGAS_LARGAS"){
		if (prendaActual[1] == "CUELLO_MAO") {
			if (prendaActual[2] == "Standard") {
				return inventario.camisa.mangaLarga.cuelloMao.standard;
			}
			else {
				return inventario.camisa.mangaLarga.cuelloMao.premium;
			}
		}
	}else if (prendaActual[0] == "CHUPIN") {
		if (prendaActual[2] == "Standard") {
			return inventario.pantalon.chupin.standard;
		}
		else {
			return inventario.pantalon.chupin.premium;
		}
	}else if (prendaActual[0] == "COMUNES") {
		if (prendaActual[2] == "Standard") {
			return inventario.pantalon.comun.standard;
		}
		else {
			return inventario.pantalon.comun.premium;
		}
	}

};