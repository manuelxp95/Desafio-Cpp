#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include "Prenda.h"
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

void View::setPrendaMenuItem(const std::map<PrendaType, Prenda*>& items) {
	if (items.empty())
	{
		showText("Ups!... parece que no hay prendas disponibles por aquí...");
	}
	else
	{
		m_prendaMenuItems = items;
	}
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

		for (const auto& item : m_prendaMenuItems)
		{
			const auto* prenda = m_prendaMenuItems[item.first];
			std::string prendaName = prenda->getName();
			auto numberOfItem = (int)item.first;
			std::string  str_numberOfItem = std::to_string(numberOfItem);
			std::string menuItem = str_numberOfItem + "- " + prendaName; // construímos el ítem/opción de menú (por ejemplo: "2- Rifle")
			showText(menuItem.c_str());
		}

		std::cin >> optionString;
		selectPrenda(optionString.c_str(), isValidOption);
		std::cin.get();
	
	} while (!isValidOption);
}

void View::selectPrenda(const char* option, bool& isValidOption)
{
	try
	{
		int optionInt = std::stoi(option);
		for (const auto& item : m_prendaMenuItems)
		{
			if (optionInt == (int)item.first)
			{
				m_presenter->pickupPrenda(optionInt);
				isValidOption = true;
				std::cin.get();
				break;
			}
			else
			{
				isValidOption = false;
			}
		}
		if (!isValidOption)
		{
			std::system("cls");
			showText(INVALID_OPTION_MESSAGE);
			std::cin.get();
		}
	}
	catch (std::invalid_argument)
	{
		auto str_option = std::string(option);
		if (str_option == "3")
		{
			isValidOption = true;
			std::system("cls");
			showText("Volveremos al menú principal.");
			std::cin.get();
		}
		else
		{
			std::system("cls");
			showText(INVALID_OPTION_MESSAGE);
			isValidOption = false;
		}
	}

	showText("");
	showText(ANY_KEY_MESSAGE);
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

