#pragma once
#include<iostream>
#include"Core/clsBankClient.h"
#include "clsScreen.h"
#include "Lib/clsInputValidation.h"
class clsDepositScreen: protected clsScreen
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

	static string _ReadAccountNumber() {
		string AccountNumber;
		cout << "Please Enter Account Number: ";
		cin >> AccountNumber;

		return AccountNumber;
	}
public:

	static void ShowDepositScreen()
	{
		double Amount = 0;
		_DrawScreenHeader("Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) 
		{
			cout << "Client with Account Number [" << AccountNumber << "] Does not exist! " << endl;
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		cout << "Please Enter Deposit Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "Are you sure you want to deposit [" << Amount << "] Y/N?" << endl;
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance;
		}
		else {
			cout << "\nOperation was cancelled.\n";

		}

	}


};

