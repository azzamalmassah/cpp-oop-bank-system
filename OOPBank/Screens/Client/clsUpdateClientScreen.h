#pragma once
#include "clsScreen.h"
#include <iostream>
#include"Lib/clsInputValidation.h"
#include"Core/clsBankClient.h"
#include"Core/clsUser.h"
class clsUpdateClientScreen: protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "Enter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email ID: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone Number: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter Balance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}


	static void _PrintClient(  clsBankClient& Client)
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


	static void ShowUpdateClientsScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient)) {
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen");

	string AccountNumber = "";
	cout << "Please Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Account number was not found , please try again" << endl;
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	
	_PrintClient(Client);

	cout << "\n\nUpdate Client Info:";
	cout << "\n__________________________\n";
	_ReadClientInfo(Client);

	clsBankClient::enSaveResults SaveResults;

	SaveResults = Client.Save();

	switch (SaveResults) 
	{
	case clsBankClient::enSaveResults::svSucceeded :
	{
		system("cls");
		cout << "\n Account Updated Successfully :-) \n";
		_PrintClient(Client);
		break;
	}
	case clsBankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "Error Somthing went Wrong !\n";
		break;
	}
	}

}


};

