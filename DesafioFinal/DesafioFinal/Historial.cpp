#include "Historial.h"

Historial::Historial() {
}

void Historial::setHistorial(const std::string& str) {
	historialList.push_back(str);
};

std::vector<std::string> Historial::getHistorial() {
	return historialList;
};