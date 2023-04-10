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

void View::setHistorial(std::vector<std::string> historial) { //-------------->guardan en variables para presentacion
	historialActual = historial;
}

void View::setLogin(std::string t_nom, std::string t_dir, std::string v_nom, int id_v) {
	tienda_nom = t_nom;
	tienda_dir = t_dir;
	vend_nom = v_nom;
	cod_vend = id_v;
}

//-----------------------> Menus

void View::showHistorialMenu() {
	std::system("cls");
	showText("COTIZADOR EXPRES - HISTORIAL DE COTIZACIONES");
	showText("----------------------------------------------");
	showText("Presiona 3 para volver al menu principal");
	showText("----------------------------------------------");
	m_presenter->getHistorialCotizaciones();
	for (auto item : historialActual) {
		showText(item);
		showText("\n");
	}
	std::cin.get();
};

void View::showHeadMenu() {
	std::system("cls");
	showText("COTIZADOR EXPRES - COTIZAR");
	showText("----------------------------------------------");
	showText("Presiona 3 para volver al menu principal");
	showText("----------------------------------------------");
}

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

void View::showSubmenuPantalon() {
	std::string optionString = "";
	bool isValidOption = true;
	showHeadMenu();
	showText("PASO 2: El Pantalon a cotizar ¿Es Chupin?");
	showText("1) Si");
	showText("2) No");
	showText("----------------------------------------------");
	std::cin >> optionString;
	if (checkSelect(optionString.c_str())) {
		m_presenter->setPrendaType(optionString);
	}
	else { showMainMenu(); }
};

void View::showSubmenuCamisa() {
	std::string optionString = "";
	std::string optionString2 = "";
	bool isValidOption = true;
	showHeadMenu();
	showText("PASO 2.a: La camisa a cotizar, ¿Es Manga corta?");
	showText("1) Si");
	showText("2) No");
	showText("----------------------------------------------");
	std::cin >> optionString;
	if (checkSelect(optionString.c_str())) {
		showHeadMenu();
		showText("PASO 2.b: La camisa a cotizar, ¿Es Cuello Mao?");
		showText("1) Si");
		showText("2) No");
		showText("----------------------------------------------");
		std::cin >> optionString2;
		if (checkSelect(optionString2.c_str())){
			m_presenter->setPrendaType(optionString, optionString2);
		}
		else { showMainMenu(); };
	}
	else {
		showMainMenu();
	};
}

void View::showCalidadMenu() {
	std::string optionString = "";
	showHeadMenu();
	showText("PASO 3: Seleccione la calidad de la prenda");
	showText("1) Standard");
	showText("2) Premium");
	showText("----------------------------------------------");
	std::cin >> optionString;
	if (checkSelect(optionString.c_str())) {
		m_presenter->setCalidad(optionString);
	}
	else { showMainMenu();}
};

void View::showPrecioMenu() {
	std::string optionString = "";
	showHeadMenu();
	showText("PASO 4: Ingrese el precio unitario de la prenda a cotizar");
	showText("_");
	showText("----------------------------------------------");
	std::cin >> optionString;
	if (checkSelect(optionString.c_str())) {
		m_presenter->setPrecioUni(optionString);
	}
	else { showMainMenu(); }
};

void View::showCantidadMenu(int stockActual) {
	std::string optionString = "";
	showHeadMenu();
	showText("INFORMACION:");
	showText("EXISTE "+std::to_string(stockActual) + " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
	showText("");
	showText("PASO 5: Ingrese la cantidad de unidades a cotizar");
	showText("_");
	showText("----------------------------------------------");
	std::cin >> optionString;
	//-------------->Control antes de seguir
	if (std::stoi(optionString) > stockActual) {
		showHeadMenu();
		showText("");
		showText("ERROR: CANTIDAD DE STOCK INSUFICIENTE");
		showText("----------------------------------------------");
		std::cin.get();
		std::cin.get();
		showMainMenu();
	}
	else {
		if (checkSelect(optionString.c_str())) {
			m_presenter->setCantidadPrendas(optionString);
		}
		else { showMainMenu(); }
	}
};

void View::showResultCotizacion(std::string text) {
	std::string optionString = "";
	showHeadMenu();
	showText(text);
	std::cin >> optionString;
	if (checkSelect(optionString.c_str())) {
		m_presenter->setCantidadPrendas(optionString);
	}
	else { showMainMenu(); }

};

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

bool View::checkSelect(const char* option) {
	auto str_option = std::string(option);
	try {
		if (str_option == "3")
		{
			std::system("cls");
			showText("Volveremos al menú principal.");
			std::cin.get();
			return false;
		}
	}catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return false;
	}
	showText("");
	showText(ANY_KEY_MESSAGE);
	return true;

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
		showText(tienda_nom + " | " + tienda_dir);
		showText("----------------------------------------------");
		showText(vend_nom + " | " + std::to_string(cod_vend));
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
		showHistorialMenu();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		showMenuCotizacion();
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

