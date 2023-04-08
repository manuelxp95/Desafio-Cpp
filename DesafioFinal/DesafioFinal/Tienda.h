#ifndef TIENDA_H
#define TIENDA_H
#include <string>
#include <vector>

//------------>Definicion de tipos de prenda existentes
struct Camisa {
    int total;
    struct MangaCorta {
        int total;
        struct CuelloMao {
            int total;
            int standard;
            int premium;
        } cuelloMao;
        struct CuelloComun {
            int total;
            int standard;
            int premium;
        } cuelloComun;
    } mangaCorta;
    struct MangaLarga {
        int total;
        struct CuelloMao {
            int total;
            int standard;
            int premium;
        } cuelloMao;
        struct CuelloComun {
            int total;
            int standard;
            int premium;
        } cuelloComun;
    } mangaLarga;
};
struct Pantalon {
    int total;
    struct Chupin {
        int total;
        int standard;
        int premium;
    } chupin;
    struct Comun {
        int total;
        int standard;
        int premium;
    } comun;
};
struct prendasStock {
    struct Camisa camisa;
    struct Pantalon pantalon;
};

class Tienda {
private:
	std::string nombreTienda;
	std::string direccionTienda;
    prendasStock inventario;

public:
	Tienda();
	std::string getDireccion();
    std::string getNombre();
    int getStock(std::vector<std::string> prendaActual);
};
#endif
