#pragma once
#include"clsScreen.h"
#include"clsInputValidation.h"


class clsDeleteUser :protected clsScreen
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
		cout << "\nPermissions        : " << User.Permissions;
		cout << "\n___________________\n";



	}
public:


	static void ShowDeleteUsersScreen(){
		
		_DrawScreenHeader("Delete Users Screen");

		cout << "Please Enter UserName: ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {
			cout << "User is not Found choose another user name " << endl;
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);
		char Answer = 'n';
		cout << "Are You Sure You want to delete this User Y/N?  " << endl;
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			if (User1.Delete()) {
				cout << "\n User Deleted successfully :-)\n";
				cout << "\n user after delete" << endl;
				_PrintUser(User1);

			}
			else {
				cout << "\nError User was not Deleted!";
			}
		}
	}

};

