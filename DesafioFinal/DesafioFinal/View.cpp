#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include <algorithm>
#include <vector>

const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";

//--------------> Constructor
View::View()
{
	SetConsoleTitleW(L"COTIZADOR EXPRESS");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
	showMainMenu();
}

//-----------> Metodos view
void View::showText(const char* text)
{
	std::cout << text << std::endl;
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}

//---------------> Menus
void View::showMenuCotizacion() {
	std::string optionString = "";
	bool isValidOption = true;
	do {
		std::system("cls");
		showText("COTIZADOR EXPRES - COTIZAR");
		showText("----------------------------------------------");
		showText("Presiona 3 para volver al menu principal");
		showText("----------------------------------------------");
		showText("PASO 1: Selecciona la prenda a cotizar: ");
		m_presenter->getListOfPrendas();
	
	} while (!isValidOption);
}

void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;

	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS MENÚ PRINCIPAL");
		showText("----------------------------------------------");
		showText("Nombre de la tienda | Dirección de la tienda");
		showText("----------------------------------------------");
		showText("Nombre y Apellido del vendedor | Código del vendedor");
		showText("----------------------------------------------");
		showText("");
		showText("SELECCIONE UNA OPCIÓN DEL MENÚ:");
		showText("");
		showText("1) Historial de Cotizaciones");
		showText("2) Realizar Cotización");
		showText("3) Salir");
		std::cin >> option;
		std::system("cls");
		runOption(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::runOption(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		//showMenuToTakeAWeapon();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		showMenuCotizacion();
		//m_presenter->dropCurrentWeapon();
		std::cin.get();
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}

