#pragma once
#include<iostream>
#include"clsScreen.h"
#include "Lib/clsInputValidation.h"
#include"Core/clsBankClient.h"


class clsWithdrawScreen:protected clsScreen
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
		_DrawScreenHeader("Withdraw Screen");
		string AccountNumber;
		cout << "Please Enter Account Number: ";
		cin >> AccountNumber;

		return AccountNumber;
	}

public:
	static void ShowWithDrawScreen() {
		string AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsClientExist(AccountNumber)) 
		{
			cout << "Client with Account Number [" << AccountNumber << "] Does not exist! " << endl;
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double Amount=0;
		cout << "Enter Amount to Withdraw: ";
		Amount = clsInputValidate::ReadDblNumber();
		char Answer = 'n';
		cout << "Are you sure you want to withdraw [" << Amount << "] Y/N ? ";
		cin >> Answer;
		bool result=0;
		if (Answer == 'y' || Answer == 'Y') {
			result = Client.Withdraw(Amount);
			if (!result) {
				cout << "Can not Withdraw, Insuffecient Balance!";
				cout << "Your balance is " << Client.AccountBalance;
			}
			else {
				cout << "\nAmount withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			
		}
		else {
						cout << "\nOperation was cancelled.\n";

		}
	}

	

};

