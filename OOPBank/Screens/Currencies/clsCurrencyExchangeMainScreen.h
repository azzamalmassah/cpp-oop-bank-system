#pragma once
#include <iostream>
#include"clsScreen.h"
#include"Lib/clsInputValidation.h"
#include"Core/clsUser.h"
#include"clsListCurrencies.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen:protected clsScreen
{


    enum enCurrencyExchangeOptions {
        enListCurrencies=1,
        enFindCurrencies=2,
        enUpdateCurrencies=3,
        enCurrencyCalculator=4,
        enMainMenu=5
    };
    static  void _GoBackToExchangeMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowExchangeMenu();
    }
    static void _ShowListCurrencies() {
        clsListCurrencies::ShowCurrenciesList();
    }
    static void _ShowFindCurrencies() {
     
        clsFindCurrency::ShowFindCurrency();
    }
    static void _ShowUpdateCurrencies() {
        clsUpdateCurrencyRate::ShowUpdateCurrencyRate();
    }
    static void _ShowCurrencyCalculator() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
    }
    
    static void _PreformExchangeMenuOptions(enCurrencyExchangeOptions Option)
    {
        switch (Option) 
        {
        case enCurrencyExchangeOptions::enListCurrencies: {
            system("cls");
            _ShowListCurrencies();
            _GoBackToExchangeMenu();
            break;
        }
        case enCurrencyExchangeOptions::enFindCurrencies: 
        {
            system("cls");
            _ShowFindCurrencies();
            _GoBackToExchangeMenu();
            break;
        }
        case enCurrencyExchangeOptions::enUpdateCurrencies:
        {
            system("cls");
            _ShowUpdateCurrencies();
            _GoBackToExchangeMenu();
            break;
        }
        case enCurrencyExchangeOptions::enCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToExchangeMenu();
            break;
        }
        case enCurrencyExchangeOptions::enMainMenu:
        {
            system("cls");
            
            break;
        }
        }
    }
    static short _ReadOptions() {

        cout << setw(37) << left << "" << "Choose what you want to do: ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5);
        return Choice;
    }
public :
    static void ShowExchangeMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExange))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tCurrency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tExchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currencies.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PreformExchangeMenuOptions((enCurrencyExchangeOptions)_ReadOptions());
    }
};

