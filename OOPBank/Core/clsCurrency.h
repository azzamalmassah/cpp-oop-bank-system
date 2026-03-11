#pragma once
#include<iostream>
#include<string>
#include "Lib/clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{
private:
	enum enMode {
		EmptyMode=0,
		UpdateMode=1
	};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#") {

		vector<string>vCurrencyData = clsString::split(Line, Separator);
		
		return clsCurrency(enMode::UpdateMode, clsString::toUpper(clsString::trim(vCurrencyData[0])), clsString::toUpper(clsString::trim(vCurrencyData[1])), clsString::toUpper(clsString::trim(vCurrencyData[2])), stod(vCurrencyData[3]));

	}

	static string _ConverCurrencyObjectToLine(clsCurrency &Currency,string Separator ="#//#") {
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Separator;
		stCurrencyRecord += Currency.CurrencyCode() + Separator;
		stCurrencyRecord += Currency.CurrencyName() + Separator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}
	
	static vector <clsCurrency>   _LoadCurrenciesDataFromFile() {
		vector <clsCurrency> vCurrenciesData;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";

			while (getline(MyFile, Line)) {
				vCurrenciesData.push_back(_ConvertLineToCurrencyObject(Line));

			
			}
			MyFile.close();
		}
		return vCurrenciesData;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies) {
		

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open()) {
			for (clsCurrency& C : vCurrencies) 
			{
				string DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}

	}

	void _Update() {
		vector<clsCurrency>_vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : _vCurrencies) {
			if (C.CurrencyCode() == CurrencyCode()) {
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencies);
	}
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	static clsCurrency _GetEmptyCurrncyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	float Rate()
	{
		return _Rate;
	}
	
	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::toUpper(clsString::trim(CurrencyCode));
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) 
		{
			string Line;
			while (getline(MyFile, Line)) 
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;

				}
			}
			MyFile.close();

		}
		return _GetEmptyCurrncyObject();
	}
	
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::toUpper(clsString::trim(Country));
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				
				if (Currency.Country() == Country)
				{
					MyFile.close();
					return Currency;

				}
			}
			MyFile.close();

		}
		return _GetEmptyCurrncyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static  vector< clsCurrency> _GetCurrenciesList() {
		return _LoadCurrenciesDataFromFile();
	}

	float ConvertToUSD(float Amount) {
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount,clsCurrency &Currency2) {
		
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD") {
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Currency2.Rate());
	}

};

