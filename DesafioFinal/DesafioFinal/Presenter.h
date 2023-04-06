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
	virtual void setPrendaType(std::string op, std::string op2);
	virtual void setPrendaType(std::string op) ;
	void setCalidad(std::string op);
	void getListOfPrendas();
};
#endif //PRESENTER_H
