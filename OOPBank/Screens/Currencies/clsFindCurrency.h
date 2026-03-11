#pragma once
#include<iostream>
#include"Lib/clsInputValidation.h"
#include"Lib/clsString.h"
class clsFindCurrency:protected clsScreen
{

private:
	static void _PrintCurrency(clsCurrency &Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();

    cout << "\n_____________________________\n";

}
    enum eFindOption {
        eByCode=1,
        eByCountry=2
    };
    static int _ReadFindOption() {
        int Option=0;
        cout << "\n\t\tFind By [1] Code\t [2]Country Name " << endl;
        cout << "\n\t\tPlease Enter Your Option 1/2? ";

         Option = clsInputValidate::ReadIntNumberBetween(1, 2);
        return Option;
    }

    static void PerformFindOptions(eFindOption Option) {
        switch (Option) 
        {
        case eFindOption::eByCode: {
            FindByCode();
            break;
        }
        case eFindOption::eByCountry: {
            FindByCountry();
            break;
        }
        }
    }
    static string _ReadCurrencyCodeOrCountry(string Message) {
        cout << Message;
        string Code = clsInputValidate::ReadString();
        return clsString::toUpper(clsString::trim(Code));
    }

public:
    static void FindByCode() {
        string Code = _ReadCurrencyCodeOrCountry("Enter Currency Code: ");
        clsCurrency Currency = clsCurrency::FindByCode(Code);
        while (Currency.IsEmpty()) {
            cout << "\nCan Not Find Currency!, Try another code\n ";
            Code = _ReadCurrencyCodeOrCountry("\nEnter Currency Code: ");
            Currency = clsCurrency::FindByCode(Code);
        }
        _PrintCurrency(Currency);
    }

    static void FindByCountry() {
        string Country = _ReadCurrencyCodeOrCountry("Enter Country Name: ");
        clsCurrency Currency = clsCurrency::FindByCountry(Country);
        while (Currency.IsEmpty()) {
            cout << "\nCan Not Find Currency!, Try another Country Name\n ";
            Country = _ReadCurrencyCodeOrCountry("\nEnter Country Name: ");
             Currency = clsCurrency::FindByCountry(Country);

        }
        _PrintCurrency(Currency);
    }
    static void ShowFindCurrency() {
     
        _DrawScreenHeader("Find Currency Screen");
        char Answer = 'y';
        do
        {
        PerformFindOptions((eFindOption)_ReadFindOption());
        
        cout << "Do You Want to find Another Currency Y/N?  ";
        cin >> Answer;
        } while (Answer == 'Y' || Answer == 'y');
    }
};

