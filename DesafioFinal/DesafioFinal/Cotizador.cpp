#include "Cotizador.h"
#include "Prenda.h"

Prenda* prendaSelected;

void Cotizador::AddString(const std::string& str) {
	prendaList.push_back(str);
}

std::string Cotizador::getCotizacion(int cod_vendedor) {
	double precioPrenda= std::stod(prendaList[3]);
	for (auto item : prendaList) {
		if (item == "MANGAS_CORTAS") {
			precioPrenda = precioPrenda - precioPrenda * 0.1; //R1
		}
		if (item == "CUELLO_MAO") {
			precioPrenda = precioPrenda + precioPrenda * 0.03; //R2YR3
		}
		if (item == "CHUPIN") {
			precioPrenda = precioPrenda - precioPrenda * 0.12; //R4
		}
		if (item == "Premium") {
			precioPrenda = precioPrenda + precioPrenda * 0.3; //R6
		}
	}
	return (setFormato(precioPrenda,cod_vendedor));
}

std::string Cotizador::setFormato(double precioCotizacion, int cod_vend) {
	id++;
	std::ostringstream stream;
	fechaHora fh;
	fh.momento = std::chrono::system_clock::now();
	std::time_t tiempo = std::chrono::system_clock::to_time_t(fh.momento);

	stream << "Número de identificación: " << id << "\n";
	stream << "Fecha y Hora de la cotización: " << std::ctime(&tiempo) << "\n";
	stream << "Código del Vendedor: " << cod_vend << "\n"; //-------->id vendedor
	stream << "Prenda cotizada: " << prendaSelected->getName() << " - ";
	stream << prendaList[0] <<" - " << prendaList[1] <<" - " << prendaList[2] << "\n";
	stream << "Precio unitario: $" << prendaList[3] << "\n";
	stream << "Cantidad de unidades cotizadas: " << prendaList[4] << "\n";
	stream << "Precio Final: $" << precioCotizacion * std::stoi(prendaList[4]) << "\n";
	return stream.str();
}

const char* Cotizador::pickupPrenda(int option) {

	prendaSelected = Prenda::pickup(option);
	prendaList.clear();
	
	if (prendaSelected->getName() == "Camisa") {
		return "Camisa";//-----------> Comportamiento de menu camisa
	}else if (prendaSelected->getName() == "Pantalon") {
		return "Pantalon";
	};
}

void Cotizador::setPantalonType(std::string op) {
	if (op == "1") {//------->pantalon chupin?
		AddString("CHUPIN");
		AddString("");
	}
	else {
		AddString("COMUNES");
		AddString("");
	}
};

void Cotizador::setCamisaType(std::string op, std::string op2) {
	
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
};

void Cotizador::setCalidad(std::string op) {
	if (op == "1") {
		AddString("Standard");
	}
	else {
		AddString("Premium");
	}
};

void Cotizador::setPrecioUni(std::string optionString) {
	AddString(optionString);
}

void Cotizador::setCantidadPrendas(std::string optionString) {
	AddString(optionString);
}

std::vector<std::string> Cotizador::getPrendaActual() {
	return prendaList;
};