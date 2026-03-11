#pragma once
#include<iostream>
#include"clsScreen.h"
class clsTransferLog:protected clsScreen
{

private:
    static void PrintLogsRecordLine(clsBankClient::sLogsData& Log)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << Log.Date;
        cout << "| " << setw(10) << left << Log.SenderAccountNumber;
        cout << "| " << setw(10) << left << Log.ReciverAccountNumber;
        cout << "| " << setw(10) << left << Log.Amount;
        cout << "| " << setw(12) << left << Log.SenderBalanceAfter;
        cout << "| " << setw(12) << left << Log.ReciverBalanceAfter;
        cout << "| " << setw(15) << left << Log.User;
    }


public:
	static void ShowTransferLogs() {
        vector <clsBankClient::sLogsData> vLogRecords = clsBankClient::GetTransferLogs();

        string Title = "\tTransfer Log Records";
        string SubTitle = "\t\t(" + to_string(vLogRecords.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acct";
        cout << "| " << left << setw(10) << "R.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "R.Balance"; 
        cout << "| " << left << setw(15) << "User"; 
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogRecords.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::sLogsData &Record : vLogRecords)
            {

                PrintLogsRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

