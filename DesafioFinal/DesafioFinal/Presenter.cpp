#include "Presenter.h"
#include "IView.h"
//#include "Soldier.h"
//#include "Weapon.h"

Presenter::Presenter(IView* view) : m_view(view), m_soldier(new Soldier())
{
}
