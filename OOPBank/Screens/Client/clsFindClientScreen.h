#pragma once
#include "clsScreen.h"
#include <iostream>
#include"Lib/clsInputValidation.h"
#include"Core/clsBankClient.h"
#include"Core/clsUser.h"

class clsFindClientScreen: protected clsScreen
{
private:
	static void _PrintClient(clsBankClient& Client)
	{


		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << Client.FirstName;
		cout << "\nLastName       : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.AccountNumber;
		cout << "\nPassword       : " << Client.PinCode;
		cout << "\nBalance        : " << Client.AccountBalance;
		cout << "\n___________________\n";



	}
public:

	static void ShowFindClientsScreen() {
		
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}
		_DrawScreenHeader("\tFind Screen");

		string Accountnumber = "";
		cout << "Enter Account Number: ";
		Accountnumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(Accountnumber)) 
		{
			cout << "Account number was not found!,choose another Number: ";
			Accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Accountnumber);

		_PrintClient(Client);
	}
};

