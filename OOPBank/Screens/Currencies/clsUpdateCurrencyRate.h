#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
class clsUpdateCurrencyRate:protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency& Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static string _ReadCurrencyCodeOrCountry(string Message) {
        cout << Message;
        string Code = clsInputValidate::ReadString();
        return clsString::toUpper(clsString::trim(Code));
    }
    static double _ReadNewRate() {
        cout << "\nUpdate Currency Rate: " << endl;
        cout << "----------------------------" << endl;
        cout << "\n Enter New Rate: ";
        double Rate = clsInputValidate::ReadDblNumber();
        return Rate;
    }

public:
	static void ShowUpdateCurrencyRate() {
        _DrawScreenHeader(" Update Currency Rate Screen ");
        string Code = _ReadCurrencyCodeOrCountry("\nEnter Currency Code: ");
        
        
        while (!clsCurrency::IsCurrencyExist(Code)) {
            Code = _ReadCurrencyCodeOrCountry("\nCurrency was  not found , Try a valid Code: ");
        }
        clsCurrency Currency = clsCurrency::FindByCode(Code);
        
        _PrintCurrency(Currency);
       
            char Answer = 'n';
            cout << "Are you sure you want to update the Rate of this Currency Y/N ? ";
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y') {
                
                Currency.UpdateRate(_ReadNewRate());

                cout << "\nCurrency Rate Updated Successfully\n " << endl;
                _PrintCurrency(Currency);
            
            }
        
        
       

        
    }
};

