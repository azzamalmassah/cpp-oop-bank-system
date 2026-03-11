#pragma once
#include "clsPerson.h"
#include"Lib/clsDate.h"
#include "Lib/clsString.h"
#include <vector>
#include<string>
#include<fstream>

class clsBankClient: public clsPerson
{

private:
	enum enMode { EmptyMode = 0, UpdateMode=1, AddNewMode=2 , DeleteMode=3
	};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToObject(string Line, string seprator = "#//#") 
	{
		vector <string>vClientData;

		vClientData = clsString::split(Line, seprator);
		return clsBankClient(enMode::UpdateMode,vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}
	static clsBankClient _EmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientsDataFromFile() {
		vector <clsBankClient> _vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";

			while (getline(MyFile, Line)) {
				
				_vClients.push_back(_ConvertLineToObject(Line));

			}
			MyFile.close();
			
		}
		return _vClients;
	}
	
	static string _ConvertObjectToLine(clsBankClient& client, string seprator = "#//#") {
		string Record = "";
		Record += client.FirstName + seprator;
		Record += client.LastName + seprator;
		Record += client.Email + seprator;
		Record += client.Phone + seprator;
		Record += client.AccountNumber+ seprator ;
		Record += client.PinCode + seprator;
		Record+=to_string(client.AccountBalance);
				return Record;
	}
	static void _SaveClientDataToFile(vector <clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open()) {
			for (clsBankClient& c : vClients) {
				if (c._MarkForDelete == false) {
					MyFile << _ConvertObjectToLine(c) << endl;

				}
			}
			MyFile.close();
		}
		return;
	}
	void _AddDataLineToFile(string Line) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}
		return;

	}
	
	void  _Update() {
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClients) {
			if (c.AccountNumber == AccountNumber) {
				c = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}
	 void _AddNew() {
		 _AddDataLineToFile(_ConvertObjectToLine(*this));
	 }

	 void _RegisterTransferLogs(double Amount, clsBankClient& To,string UserName) {
		 string Line = _PrepareTransferLog(Amount, To, UserName);
		 fstream MyFile;
		 MyFile.open("TransferLogs.txt", ios::out | ios::app);
		 if (MyFile.is_open()) {
			 MyFile << Line << endl;
			 MyFile.close();
		 }

	 }

	 

	 string _PrepareTransferLog(double &Amount,clsBankClient &To,string UserName,string Seprator="#//#") {
		 string TransferLog="";
		 TransferLog += clsDate::getSystemDateTimeString()+ Seprator;
		 TransferLog += _AccountNumber + Seprator;
		 TransferLog += To.AccountNumber + Seprator;
		 TransferLog += to_string(Amount)+Seprator;
		 TransferLog += to_string(AccountBalance)+Seprator;
		 TransferLog += to_string(To.AccountBalance) + Seprator;
		 TransferLog += UserName ;

		 return TransferLog;
	 }
	 struct sLogsData;

	 static sLogsData _ConvertLogToStruct(string Line, string Seprater = "#//#") {
		 vector<string> vLogData = clsString::split(Line, Seprater);
		 sLogsData sLog;
		 sLog.Date = vLogData[0];
		 sLog.SenderAccountNumber = vLogData[1];
		 sLog.ReciverAccountNumber = vLogData[2];
		 sLog.Amount = stod(vLogData[3]);
		 sLog.SenderBalanceAfter = stod(vLogData[4]);
		 sLog.ReciverBalanceAfter = stod(vLogData[5]);
		 sLog.User = vLogData[6];
		 return sLog;
	 }
	 static vector <sLogsData> _LoadLogsFromFile()
	 {
		 vector <sLogsData>vLogs;
		 fstream MyFile;
		 MyFile.open("TransferLogs.txt", ios::in);

		 if (MyFile.is_open()) {
			 string Line = "";
			 while (getline(MyFile, Line)) {
				 vLogs.push_back(_ConvertLogToStruct(Line));


			 }
			 MyFile.close();

		 }
		 return vLogs;
	 }
	 
public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone) 
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
	}


	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	void SetAccountNumber(string AccountNumber) {
		_AccountNumber = AccountNumber;
	}
	string GetAccountNumber() {
		return  _AccountNumber;
	}


	__declspec(property(get = GetAccountNumber, put = SetAccountNumber))string AccountNumber;


	//AccountBalance
	void SetAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;



	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	// transfer log screen
	struct sLogsData {
		double Amount;
		string Date;
		string SenderAccountNumber;
		string ReciverAccountNumber;
		double SenderBalanceAfter;
		double ReciverBalanceAfter;
		string User;

	};
	

	

	// FindClient

	static clsBankClient Find(string AccountNumber) 
	{
		string Line;
		vector <clsBankClient> vClients;
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToObject(Line);
				if (Client.AccountNumber == AccountNumber) {
					MyFile.close();

					return Client;

				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _EmptyClientObject();
	}


	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		string Line;
		vector <clsBankClient> vClients;
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToObject(Line);
				if ((Client.AccountNumber == AccountNumber) && (Client.PinCode == PinCode)) {
					MyFile.close();

					return Client;

				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _EmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());

	}



	enum enSaveResults {svFaildEmptyObject=0,svSucceeded=1,svFaildAccountNumberExists};

	enSaveResults Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildEmptyObject;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		}
	}

	// Add client 
	static clsBankClient  _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode," "," "," "," ",AccountNumber," ",0);
	}
	 bool Delete() {

		 vector <clsBankClient> _vClients;
		 _vClients = _LoadClientsDataFromFile();

			 for (clsBankClient& C : _vClients) {
				 if (C.AccountNumber == _AccountNumber) {
					 C._MarkForDelete = true;
					 break;
				 }
			 }


			 _SaveClientDataToFile(_vClients);
		 


		*this= _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList() {
		 vector <clsBankClient> vClients = _LoadClientsDataFromFile();
			 return vClients;
	 }
	static double GetTotalBalances() {
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient& Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	 void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	 bool  Withdraw(double Amount) {
		 if (Amount > _AccountBalance) {
			 return false;
		 }
		 else {
			 _AccountBalance -= Amount;
			 Save();
			 return true;
		 }
		
	 }
	 

	 
	  bool  Transfer( double Amount, clsBankClient &To,string UserName) {
		 

		  if (AccountBalance < Amount) {
			 return false;
		 }
		Withdraw(Amount);
		 To.Deposit(Amount);
		  _RegisterTransferLogs(Amount, To, UserName);
		 return true;

		 
	  
	  }
	  
	  

	  static vector <sLogsData> GetTransferLogs() {
		  vector <sLogsData> vLogs = _LoadLogsFromFile();

		  return vLogs;
	  }
	  
};

