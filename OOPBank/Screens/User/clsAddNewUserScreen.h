#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidation.h"
class clsAddNewUser :protected clsScreen
{
private:
	

	
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
		//7
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
		cout << "\nPermissions        : " << User.Permissions;
		cout << "\n___________________\n";



	}

public:
	 static void ShowAddNewUser() {

		
		_DrawScreenHeader("Add New User Screen");
		string UserName;
		cout << "Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName)) {
			cout << "User Already Exists, Try New UserName" << endl;
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::GetAddNewUser(UserName);

		_ReadUserInfo(User1);
		
		clsUser::enSaveResults Result;

		Result =  User1.Save();

		switch (Result) {
		case clsUser::enSaveResults::svSucceeded:
		{
			system("cls");
			cout << "\n User Added Successfully :-) \n";
			_PrintUser(User1);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			system("cls");
			cout << "Error Somthing went Wrong !\n";
			break;

		}
		}
	}
};

