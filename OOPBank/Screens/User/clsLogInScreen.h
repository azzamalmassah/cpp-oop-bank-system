#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsMainScreen.h"
#include"clsInputValidation.h"
#include"clsUser.h"
#include"Global.h"
#include"clsUtil.h"

class clsLogInScreen:protected clsScreen
{
private:


	
	static bool _Login() 
	{
		string UserName; string Password;
		
		bool FailedLogin = false;
		short Counter = 3;
		do {
			if (FailedLogin)
			{
				Counter--;
				cout << "\nInvalid UserName/Password!, try again! " << endl;
				cout << "You have " << Counter << " trial(s) left.\n";
			}
			if (Counter == 0) {
				cout << "\nYou are Locked after 3 faild login attempts\n";
				return false;
			}
			cout << "\nEnter UserName: ";
			 UserName = clsInputValidate::ReadString();
			 cout << "\nEnter Password: ";

			 Password = clsInputValidate::ReadString();
			 CurrentUser = clsUser::Find(UserName, Password);
			 
			 
			 
				 FailedLogin = CurrentUser.IsEmpty();
			 
		} while (FailedLogin);
		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenu();
		return true;
	
	}

	public:
		
		static bool ShowLoginScreen() {
			_DrawScreenHeader("\t  Login Screen", "");

			
			return  _Login();
					
		}
		
};

