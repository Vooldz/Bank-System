#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

class clsCurrencyScreen : protected clsScreen
{

private:

    static short _ReadCurrencyOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    enum enCurrencyOptions 
    {
        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalulator = 4, MainMenu = 5
    };

    static void _GoBackToCurrencyMenu()
    {
        cout << "\n\nPress Any Key To Go Back To Currency Menu";
        system("pause>0");
        ShowCurrencyScreen();
    }

    static void _ShowCurrenciesListScreen() 
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyExchangeMainScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToMainMenu()
    {

    }

    static void _PerformCurrencyOption(enCurrencyOptions Option )
    {
        switch (Option)
        {
        case clsCurrencyScreen::eListCurrency:
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyMenu();
            break;
        case clsCurrencyScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMenu();
            break;
        case clsCurrencyScreen::eUpdateRate:
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrencyMenu();
            break;
        case clsCurrencyScreen::eCurrencyCalulator:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToCurrencyMenu();
            break;
        case clsCurrencyScreen::MainMenu:
            _GoBackToMainMenu();
            break;
        }
    }

public:
	static void ShowCurrencyScreen()
	{
        system("cls");
		_DrawScreenHeader("\t Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyOption((enCurrencyOptions)_ReadCurrencyOption());
	}

};

