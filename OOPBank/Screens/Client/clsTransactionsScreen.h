#pragma once
#include <iostream>
#include"Lib/clsInputValidation.h"
#include <iomanip>
#include "clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLog.h"
#include"Core/clsUser.h"

using namespace std;

class clsTransactionsScreen:protected clsScreen
{
private:

	enum enTransactionsMenuOptions {
		eDeposit = 1,
		eWithdraw=2,
		eShowTotalBalances=3,
		eTransfer=4,
		eTransferLog=5,
		eShowMainMenu=6
	};

	
	static void _preformTransactionsMenuOption(enTransactionsMenuOptions choice) {

		switch (choice)
		{
		case enTransactionsMenuOptions::eDeposit:
		{
			system("cls");
			ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eWithdraw:
		{
			system("cls");
			ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowTotalBalances:
		{
			system("cls");
			ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransfer:
		{
			system("cls");
			ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransferLog: 
		{
			system("cls");
			ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowMainMenu:
		{
			system("cls");
			break;
		}
		}
	}

	static  void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenu();
	}
public:
	
	static void ShowTransferScreen() {
	
		clsTransferScreen::ShowTransferScreen();
	
	};
	static void ShowTransferLogScreen() {

		clsTransferLog::ShowTransferLogs();

	};

	static short ReadTransactionsMenuOptions() {
		
		cout << setw(37) << left << "" << "Choose what you want to do: ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return Choice;
	}
	static void ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();

	}
	static void ShowWithdrawScreen() {
		
		clsWithdrawScreen::ShowWithDrawScreen();

	}
	
	static void ShowTotalBalancesScreen() {
		clsShowTotalBalancesScreen::ShowTotalBalances();
		
	}

	
	static void ShowTransactionsMenu() {
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions)) {
			return;
		}
		_DrawScreenHeader("\t\Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Transactions Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances .\n";
		cout << setw(37) << left << "" << "\t[4] Transfer\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_preformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOptions());
	}

	


};

