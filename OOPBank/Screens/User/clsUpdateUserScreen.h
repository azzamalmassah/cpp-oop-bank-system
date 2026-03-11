#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidation.h"
#include"clsUser.h"
class clsUpdateUserScreen:protected clsScreen
{

private:
	static void _PrintUser(clsUser& User)
	{


		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nPassword       : " << User.Password;
		cout << "\nPermissions    : " << User.Permissions;
		cout << "\n___________________\n";



	}
	
	static int _ReadPermissions() {
		char Answer = 'n';
		int Permissions = 0;
		cout << "Do you want to give full access Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			return Permissions += clsUser::enPermissions::pAll;
		}
		else
		{



			cout << "\nDo you Want to give access to :" << endl;
			//1
			cout << "\nShow Client List Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pListClients;
			}
			//2
			cout << "\nAdd New Client Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pAddNewClient;
			}
			//3
			cout << "\nDelete Clients Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pDeleteClient;
			}
			//4
			cout << "\nUpdate Clients Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pUpdateClient;
			}
			//5
			cout << "\Find Clients Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pFindClient;
			}
			//6
			cout << "\nTransactions Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pTransactions;
			}
			//7
			cout << "\n Manage Users Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pManageUsers;
			}
			//8
			cout << "\n Login Register Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				Permissions += clsUser::enPermissions::pLoginRegister;
			}
			return Permissions;
		}
	}
	static void _ReadUserInfo(clsUser& User) {
		cout << "Enter First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email ID: ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone Number: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permission: ";
		User.Permissions = _ReadPermissions();
	}



public:
	static void ShowUpdateUserScreen(){
		
		
		_DrawScreenHeader("Update Screen");
		cout << "Enter UserName ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << " Can Not Find User Try Another UserName: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		char Answer = 'N';
		cout << "\nAre you sure You want to Update This User Y/N ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') 
		{
			cout << "\nUpdate User Info";
			cout << "\n-----------------------\n";
		_ReadUserInfo(User);
		
		clsUser::enSaveResults Result;
		Result = User.Save();

		switch (Result)
		{
		case clsUser::enSaveResults::svSucceeded: 
		{
			cout << "\nUser Updated successfully " << endl;
			cout << "\nUser After Update" << endl;
			_PrintUser(User);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError somthing went wrong ! " << endl;
			break;

		}
		}
		}
	}
};

