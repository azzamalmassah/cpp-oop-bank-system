#pragma once
#include<iostream>
#include "clsPerson.h"
#include <fstream>
#include"Lib/clsString.h"
#include <vector>
#include"Lib/clsDate.h"
#include"Lib/clsUtil.h"
class clsUser :public clsPerson
{
private:
	enum enMode {
		EmptyMode=0,
		UpdateMode=1,
		AddNewMode=2
	};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions=0;

	bool _MarkForDelete = false;
	static clsUser _ConvertLineToUserObject(string Line,string Seperator="#//#") {
		vector<string> vUserData;
		vUserData = clsString::split(Line,Seperator);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

		
	

	}
	string _LoginRecord(string Seperator="#//#") {
		string Record = "";
		Record += clsDate::getSystemDateTimeString();
		Record += Seperator+UserName + Seperator;
		Record += clsUtil::EncryptText(Password)+Seperator;
		Record += to_string(Permissions);
		return Record;
	}

	static string _convertObjectToLine(clsUser& User,string Seperator="#//#") {
		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtil::EncryptText(User.Password) + Seperator;
		UserRecord += to_string(User.Permissions);
		return UserRecord;

	}
	static vector<clsUser> _LoadUsersDataFromFile() {
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile, Line)) {
				vUsers.push_back(_ConvertLineToUserObject(Line));
			}
			MyFile.close();
		}
		return vUsers;
	}
	static void _SaveUsersDataToFile(vector <clsUser>& Users) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open()) {
			string Line;
			for (clsUser& U : Users) {
				if (U._MarkForDelete == false) {
					Line=_convertObjectToLine(U);
					MyFile << Line << endl;

				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector <clsUser>vUsers;
		vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName) 
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew() {
		_AddDataLineToFile(_convertObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConverRecordToStruct(string Line, string separetor = "#//#") {
		vector<string> vLoginData;
		stLoginRegisterRecord sRecord;
		vLoginData = clsString::split(Line, separetor);
		sRecord.Date = vLoginData[0];
		sRecord.UserName = vLoginData[1];
		sRecord.Password = vLoginData[2];
		sRecord.Permission = stoi(vLoginData[3]);
		return sRecord;
	}

public:
	enum enPermissions {
		pAll = -1,
		pListClients = 1 << 0,
		pAddNewClient = 1 << 1,
		pDeleteClient = 1 << 2,
		pUpdateClient = 1 << 3,
		pFindClient = 1 << 4,
		pTransactions = 1 << 5,
		pManageUsers = 1 << 6,
		pLoginRegister=1<<7,
		pCurrencyExange=1<<8
	};
	struct stLoginRegisterRecord {
		string Date;
		string UserName;
		string Password;
		int Permission;

	};
	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}

	void SetUserName(string UserName) {
		_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;


	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Permissions) {
		_Permissions = Permissions;
	}
	int GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	
	static clsUser Find(string UserName) {
		fstream Myfile;
		Myfile.open("Users.txt", ios::in);

		if (Myfile.is_open()) {
			string Line = "";
			while (getline(Myfile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {
					Myfile.close();

					return User;
				}
			}
			Myfile.close();

		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName,string Password) {
		fstream Myfile;
		Myfile.open("Users.txt", ios::in);

		if (Myfile.is_open()) {
			string Line = "";
			while (getline(Myfile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password) {
					Myfile.close();

					return User;
				}
			}
			Myfile.close();

		}
		return _GetEmptyUserObject();
	}
	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}
	bool Delete()
	{
		vector <clsUser>_vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : _vUsers) {
			if (U.UserName == UserName)
			{
				
				
				U._MarkForDelete = true;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;

	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	 enSaveResults Save() 
	{
		switch (_Mode)
	{
		case enMode::EmptyMode:
		{


			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;

			}



		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;

			}
		}
	}
	}
	static clsUser GetAddNewUser(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
}
	static vector <clsUser>GetUsersList() {
		return _LoadUsersDataFromFile();
	}
	bool CheckAccessPermission(enPermissions Permission) 
	{
		if (Permission == this->pAll) {
			return true;
		}
		else if ((Permission & this->Permissions) == Permission) {
			return true;
		}
		else {
			return false;
		}
	}
	 void RegisterLogin() {
		 string Record = _LoginRecord();
		 
		 fstream MyFile;
		MyFile.open("LoginFile.txt", ios::out | ios::app);
		if (MyFile.is_open()) {

			MyFile << Record << endl;
		}
		MyFile.close();
	}

	 
	 
	 static vector<stLoginRegisterRecord> GetUserLoginList() {
		 vector <stLoginRegisterRecord>vLoginRegisterRecord;

		 //
		 fstream MyFile;
		 
		 MyFile.open("LoginFile.txt", ios::in);
		 if (MyFile.is_open()) {
			 string Line = "";
			 while (getline(MyFile, Line)) {
				 vLoginRegisterRecord.push_back(_ConverRecordToStruct(Line));

			 }
			 MyFile.close();
		 }
		 return vLoginRegisterRecord;
		 //
	 }

	

	 

};

