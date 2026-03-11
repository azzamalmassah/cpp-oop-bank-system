#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidation.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientsScreen.h"
#include "clsDeleteClientsScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h";
#include"../User/clsManageUsersScreen.h"
#include"Global.h"
#include"../User/clsLoginRegister.h"
#include"clsCurrencyExchangeMainScreen.h"
using namespace std;
class clsMainScreen: protected clsScreen
{

private:
    enum enMainMenuOptions {
        eListClients =1,
        enAddNewClient=2,
        enDeleteClient=3,
        enUpdateClient=4,
        enFindClient=5,
        eShowTransactionsMenu =6,
        enManageUsers=7,
        enLoginRegister=8,
        enCurrencyExchange=9,
        enLogout=10
    };
    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenu();
    }
    static void  _ShowAllClientsScreen() {
        clsClientListScreen::ShowClientsList();
   }
    static void  _ShowAddNewClientsScreen() {
        clsAddNewClientsScreen::AddNewClientScreen();
    };
    static void  _ShowCurrencyExchangeMenu() {
        clsCurrencyExchangeMainScreen::ShowExchangeMenu();
    };
    static void _ShowFindClientsScreen() {
        clsFindClientScreen::ShowFindClientsScreen();
    }

    static void _ShowUpdateClientsScreen() {
        clsUpdateClientScreen::ShowUpdateClientsScreen();
    }

    static void _ShowDeleteClientsScreen() {
        clsDeleteClientsScreen::ShowDeleteClientsScreen();
    }
    static void _ShowLoginRegisterScreen() {
        clsLoginRegister::ShowLoginRegisterScreen();
    }
    static void _ShowTransactionsScreen() {
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenu() {
        clsManageUsersScreen::ShowManageUsersMenu();
    }
    static void _Logout() {
        CurrentUser = clsUser::Find("", "");
    }
    
    static void _PreformMainMenuOptions(enMainMenuOptions option) {
        switch (option)
        {
        case enMainMenuOptions::eListClients:
        {
            system("cls");

            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::enAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::enFindClient:
        {
            system("cls");
            _ShowFindClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::enUpdateClient:
        {
            system("cls");
            _ShowUpdateClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::enDeleteClient:
        {
            system("cls");
            _ShowDeleteClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eShowTransactionsMenu:
        {
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::enCurrencyExchange: 
        {
            system("cls");
            _ShowCurrencyExchangeMenu();
            _GoBackToMainMenu();
            break;
            
        }
        case enMainMenuOptions::enManageUsers:
        {
            system("cls");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::enLoginRegister: {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();

        }
        case enMainMenuOptions::enLogout:
        {
            system("cls");
            _Logout();
            break;
        }
        }

    }
    static short _ReadOptions() {

        cout << setw(37) << left << "" << "Choose what you want to do: ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10);
        return Choice;
    }
public:
	static void ShowMainMenu() 
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";

        cout << setw(37) << left << "" << "===========================================\n";
                _PreformMainMenuOptions((enMainMenuOptions)_ReadOptions());
	}
};

