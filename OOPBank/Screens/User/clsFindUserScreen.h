#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsInputValidation.h"
#include"clsUser.h"
class clsFindUserScreen:protected clsScreen
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

	public:

		static void ShowFindUserScreen() {
			
			_DrawScreenHeader(" Find User Screen ");
			cout << "\nEnter UserName: ";
			string UserName = clsInputValidate::ReadString();

			
			switch (!clsUser::IsUserExist(UserName)) {
				cout << "\nCan Not Find User With this UserName! , Tru Again : ";
				UserName = clsInputValidate::ReadString();
			}

			clsUser User = clsUser::Find(UserName);

			if (!User.IsEmpty()) {
				cout << "\nUser Found \n";
				cout << "-------------------" << endl;
			}
			else {
				cout << "User Does Not Exist ! \n";
			}
			_PrintUser(User);

		}
};

