#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Core/clsCurrency.h"
#include"Lib/clsInputValidation.h"
class clsCurrencyCalculatorScreen:protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency& Currency, string Message = "")
    {
        cout << Message << endl;
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
        
    }

    static string _ReadCurrencyCodeOrCountry(string Message="") {
        cout << Message;
        string Code = clsInputValidate::ReadString();
        return clsString::toUpper(clsString::trim(Code));
    }
    
    static clsCurrency _GetCurrency(string Message) {
        clsCurrency Currency = clsCurrency::_GetEmptyCurrncyObject();
        string CurrencyCode = _ReadCurrencyCodeOrCountry(Message);
        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            _ReadCurrencyCodeOrCountry("\nInvalid Currency code Try Again: ");
            CurrencyCode = _ReadCurrencyCodeOrCountry();
        }
        Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }
    static float _ReadAmount() {
        cout << "Enter Amount to Exchange: ";
        float Amount = clsInputValidate::ReadFloatNumber();

        return Amount;
    }

    static float ExchangeToDollar(float Amount,float CurrencyRate) {
        float  ExchangeAmount = Amount / CurrencyRate;

        return ExchangeAmount;
    }
    
    static float ExchangeFromDollarToLocal(float Amount, float SndCurrencyRate) {
        float ExchangeAmount = Amount * SndCurrencyRate;

        return ExchangeAmount;
    }

   
   static void _PrintCalculationResult(float Amount, clsCurrency& From, clsCurrency& To) 
   {

       _PrintCurrency(From, "Convert From");
       float ExchangeAmount = From.ConvertToUSD(Amount);
       cout << Amount << " " << From.CurrencyCode()
           << " = " << ExchangeAmount << " USD" << endl;
       if (To.CurrencyCode() == "USD") {
          
           return;
           
       }
       cout << "\nConverting From USD TO:\n\n\n";
         
       _PrintCurrency(To, " To");
       float ExchangeAmount2=From.ConvertToOtherCurrency(Amount, To);
       
       cout << Amount << " " << From.CurrencyCode()
           << " = " << ExchangeAmount2 <<""<< To.CurrencyCode() << endl;
   }
public:

    

    static void ShowCurrencyCalculator()
    {
     
        char Answer = 'y';
        while(Answer=='y'||Answer=='Y')
        {
        system("cls");
        _DrawScreenHeader("Currency Calculator");
        clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency 1 Code: ");
        clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency 2 Code: ");
               

                float Amount = _ReadAmount();
                
                _PrintCalculationResult(Amount, Currency1, Currency2);
                
                cout << "Do You Want to Do Another Calculation ?Y/N ";
                cin >> Answer;
               
     }
    
    
    }
};

