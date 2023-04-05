#ifndef PRESENTER_H
#define PRESENTER_H

class IView;
class Cotizador;

class Presenter
{
private:
	IView* m_view = nullptr;
	Cotizador* m_cotizador = nullptr;
public:
	explicit Presenter(IView* view);
	//~Presenter();
	void pickupPrenda(int option);
	//void getListOfWeaponMenuItems();
	//void shoot();
	//void seeCurrentWeapon();
	//void dropCurrentWeapon();
	void getListOfPrendas();
};
#endif //PRESENTER_H
