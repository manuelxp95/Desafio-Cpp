#ifndef IVIEW_H
#define IVIEW_H
#include <map>
#include<vector>
#include <string>

class Prenda;
enum class PrendaType;

class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const char* text) = 0;
	virtual void showText(const std::string& text) = 0;
	virtual void showSubmenuCamisa() = 0;
	virtual void showSubmenuPantalon()=0;
	virtual void showCalidadMenu() = 0;
	virtual void showCantidadMenu() = 0;
	virtual void showPrecioMenu()=0;
	virtual void showResultCotizacion(std::string text) = 0;
	virtual void setPrendaMenuItem(const std::map<PrendaType, Prenda*>& items) = 0;
	virtual void setHistorial(std::vector<std::string> historial) = 0;
};
#endif // IVIEW_H