#pragma once
#include "clsScreen.h"
#include "Lib/clsInputValidation.h"
#include "Core/clsBankClient.h"
#include"Core/clsUser.h"
#include <iomanip>
class clsAddNewClientsScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient &Client)
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

	static void ReadClientInfo(clsBankClient& Client) {
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

public:
	static void AddNewClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		_DrawScreenHeader("Add New Client Screen");
		
		string AccountNumber = "";
	
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
	
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is already in use , choose Another Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
	
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(NewClient);
	
	
		clsBankClient::enSaveResults SaveResults;
	
		SaveResults = NewClient.Save();
	
	
		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			system("cls");
			cout << "\n Account Added Successfully :-) \n";
			_PrintClient(NewClient);
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

