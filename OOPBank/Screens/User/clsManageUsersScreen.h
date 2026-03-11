#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidation.h"
#include "clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsersScreen:protected clsScreen
{
	enum enManageUsersOption {
		enListUsers = 1,
		enAddNewUsers=2,
		enDeleteUsers=3,
		enUpdateUsers=4,
		enFindUsers=5,
		enMainMenu=6
	};

	static int _ReadManageUsersOption() {
		
			cout << setw(37) << left << "" << "Choose what you want to do: ";
			short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
			return Choice;
		
		//
		
	}
	static  void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

		system("pause>0");
		ShowManageUsersMenu();
	}

	
	static void _ShowListUsersScreen() {
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen() {
		clsAddNewUser::ShowAddNewUser();
	}

	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowDeleteUsersScreen() {
		clsDeleteUser::ShowDeleteUsersScreen();
	}
	static void _ShowUpdateUsersScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _performManageUsersOption(enManageUsersOption choice) {
		switch (choice)
		{
		case enManageUsersOption::enListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOption::enAddNewUsers:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOption::enFindUsers:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOption::enDeleteUsers:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersOption::enMainMenu:
		{
			
			break;
		}
		case enManageUsersOption::enUpdateUsers:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		}
	}

	
public:
	static void ShowManageUsersMenu() {
		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		_DrawScreenHeader("\t\Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Users.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Users .\n";
		cout << setw(37) << left << "" << "\t[4] Update Users.\n";
		cout << setw(37) << left << "" << "\t[5] Find Users.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_performManageUsersOption((enManageUsersOption)_ReadManageUsersOption());
	}

	
};


