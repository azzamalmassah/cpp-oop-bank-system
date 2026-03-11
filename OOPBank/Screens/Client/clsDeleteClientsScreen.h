#pragma once
#include<iostream>
#include"Lib/clsInputValidation.h"
#include"clsScreen.h"
#include"Core/clsBankClient.h"
#include"Core/clsUser.h"
class clsDeleteClientsScreen: protected clsScreen
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
	static void ShowDeleteClientsScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
		_DrawScreenHeader("Delete Client Screen");

	string AccountNumber = "";
	cout << "Enter Account number : ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Clinet is Not found , plaease Enter Correct Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	_PrintClient(Client);
	char Answer = 'n';

	cout << "Are You sure You Want to delete this Cline Y/N? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y') {

		if (Client.Delete()) {
			system("cls");
			cout << "\n Client Deleted Successfully :-) \n";
			_PrintClient(Client);
		}
		else {
			cout << "Error somthing went wrong" << endl;

		}

	}
	else {
		cout << "this operation is canceled"<<endl;
	}
}

};

