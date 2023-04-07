#ifndef HISTORIAL_H
#define HISTORIAL_H
#include <string>
#include <vector>

class Historial {
private:
	std::vector<std::string> historialList;
public:
	Historial();
	void setHistorial(const std::string& str);
	std::vector<std::string> getHistorial();
};
#endif