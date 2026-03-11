#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Lib/clsInputValidation.h"
#include"Core/clsBankClient.h"
#include"Global.h"
class clsTransferScreen:protected clsScreen
{

	static void _PrintClient(clsBankClient& Client)
	{


		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.AccountNumber;
		cout << "\nBalance        : " << Client.AccountBalance;
		cout << "\n___________________\n";



	}
	static string _ReadAccountNumber(string Message) {
		cout << Message;
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number[" << AccountNumber << "] Is Invalid ,Try Again!" << endl;;
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient &SenderClient) {
		double Amount = 0;
		cout << "Enter Transfer Amount: ";
		Amount = clsInputValidate::ReadDblNumber();
		while (Amount<0 || Amount > SenderClient.AccountBalance) {

			cout << "Amount Exceeded The available Balance [" << SenderClient.AccountBalance << "] Enter Another Amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

	
public:
	 static void ShowTransferScreen() {
		_DrawScreenHeader("Transfer Screen");
		
		
		string AccountNumber = _ReadAccountNumber("\nPlease Enter Account Number To Transfer From : ");
		clsBankClient SenderClient = clsBankClient::Find(AccountNumber);

		_PrintClient(SenderClient);


		//2
		 
		string AccountNumber2 = _ReadAccountNumber("\nPlease Enter Account Number To Transfer To: ");
		
		while (AccountNumber == AccountNumber2) {
			cout << "You Can Not Transfer To The Same Account Number!,Try Another Account Number: ";
			AccountNumber2 = clsInputValidate::ReadString();
		}
		

		clsBankClient ReseverClient = clsBankClient::Find(AccountNumber2);

		_PrintClient(ReseverClient);

		
		double Amount = _ReadAmount(SenderClient);
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		
		if (Answer == 'Y' || Answer == 'y')
	{
		

		if (SenderClient.Transfer(Amount, ReseverClient,CurrentUser.UserName))
		{
			cout << "Operation Done Successfully!" << endl;
		}
		else {
			cout << "Somthing Went Wrong!\nTransfer Faild " << endl;
		}
		}
	}
};

