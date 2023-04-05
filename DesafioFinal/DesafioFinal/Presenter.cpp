#include "Presenter.h"
#include "IView.h"
#include "Cotizador.h"
//#include "Weapon.h"

Presenter::Presenter(IView* view) : m_view(view), m_cotizador(new Cotizador())
{
}

void Presenter::getListOfPrendas() {

}