#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
//#include "WeaponFactory.h"
#include <string>

class Presenter;
//class Weapon;

class View : public IView
{
private:
	Presenter* m_presenter;
	std::map<PrendaType, Prenda*> m_prendaMenuItems;
	void showMainMenu();
	void showHeadMenu();
	void runOption(const char* option, bool& exitCondition);
public:
	View();
	//~View() override;
	void showMenuCotizacion();
	void showSubmenuCamisa();
	void showSubmenuPantalon();
	void showCalidadMenu();
	void showPrecioMenu();
	bool checkSelect(const char* option);
	void selectPrenda(const char* option, bool& isValidOption);
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void setPrendaMenuItem(const std::map<PrendaType, Prenda*>& items) override;
};
#endif //VIEW_H