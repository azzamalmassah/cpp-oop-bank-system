#pragma once
#include<iostream>
#include<string>
using namespace std;
class clsUtil
{

	

public:
	

	static void  Srand()
	{
		srand((unsigned)time(NULL));
	}

	static float calcuAverage(int mark1, int mark2, int mark3) {
		return (float)(mark1 + mark2 + mark3) / 3;
	}

	
	static void Swap(int& A, int& B) {
		int Temp = 0;
		Temp = A;
		A = B;
		B = Temp;

	}
	static void Swap(double& A, double& B) {
		double Temp = 0;
		Temp = A;
		A = B;
		B = Temp;

	}
	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	

	static int readAge() {
		int age;
		cout << "pleas enter age between 18 and 45  : ";
		cin >> age;
		return age;
	}
	static bool validateAgeInRange(int age, int from, int to) {
		return (age >= from && age <= to);
	}

	static int readUntilAgeBetween(int from, int to) {
		int age = 0;
		do {
			age = readAge();
		} while (!validateAgeInRange(age, from, to));

		return age;
	}


	static int readNumberInRange(string message, int from, int to) {
		int num;
		do {
			cout << message;
			cin >> num;

		} while (num<from || num>to);
		return num;
	}

	static int Reverse(int number) {
		int remainder = 0;
		int number2 = 0;
		while (number > 0) {
			remainder = number % 10;
			number = number / 10;
			number2 = number2 * 10 + remainder;
		}
		return number2;
	}

	static int Frequency(int Selected, int Number) {

		int Remainder = 0;
		int Counter = 0;
		while (Number > 0) {
			Remainder = Number % 10;
			Number = Number / 10;
			if (Selected == Remainder) {
				Counter++;
			}
		}



		return Counter;
	}

	static int Random(int from, int to) {
		return rand() % (to - from + 1) + from;
	}
	static enum enCharType { CapitalLetter = 1, SmallLetter = 2, SpecialChar = 3, Digit = 4 };
	

	static char GetRandomChar(enCharType Type) {
		switch (Type) {
		case enCharType::CapitalLetter:
			return Random(65, 90);
			break;
		case enCharType::SmallLetter:
			return Random(97, 122);
			break;
		case enCharType::SpecialChar:
			return char(Random(33, 47));
			break;
		case enCharType::Digit:
			return char(Random(40, 57));

		defualt:

			return char(Random(65, 90));
			break;
		}
		return 0;
	}

	static string GenerateWord(enCharType CharType, short Length) {
		string Word = "";
		for (int i = 1; i <= Length; i++) {
			Word = Word + GetRandomChar(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter) {
		string Key = "";
		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-" + GenerateWord(enCharType::CapitalLetter, 4) + "-" + GenerateWord(enCharType::CapitalLetter, 4) + "-" + GenerateWord(enCharType::CapitalLetter, 4);
		return Key;
	}

	static void GenerateKeys(int KeysNumber) {
		for (int i = 1; i <= KeysNumber; i++) {
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}
	static void ShuffleArray(int Arr[100], int ArrLength) {
		for (int i = 0; i < ArrLength; i++) {
			int RandIndex = Random(i, ArrLength) - 1;
			Swap(Arr[i], Arr[RandIndex]);
		}
	}
	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[Random(1, arrLength) - 1], arr[Random(1, arrLength) - 1]);
		}

	}
	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static void DynamicArray(int arr2[100], int& arrLength, int number) {

		arr2[arrLength] = number;
		arrLength++;
	}

	static bool IsNumberInArray(int Number, int Arr[100], int& ArrLength) {
		for (int i = 0; i < ArrLength; i++) {
			if (Arr[i] == Number) {
				return 0;
			}
		}
		return 1;
	}
	static void FillArrWithRandomNUmbers(int Arr[100], int ArrLength) {
		for (int i = 0; i < ArrLength; i++) {
			Arr[i] = Random(-100, 100);
		}
	}
	static int Abs(int Number) {
		return  -(Number);
	}
	static float GetFraction(float Number) {
		return  Number - (int)Number;
	}
	static float Round(float Number) {
		float Fraction = GetFraction(Number);
		if (Number > 0) {
			if (Fraction >= .5) {
				return (int)Number + 1;
			}
			else if (Fraction < .5) {
				return (int)Number;
			}
		}
		else {
			if (Fraction <= -0.5) {
				return (int)Number - 1;
			}
			else {
				(int)Number;
			}
		}
	}
	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}
	static int Floor(float Number) {
		if (Number > 0) {
			return (int)Number;
		}
		else {
			return Number - 1;
		}
	}
	static int Ceil(float Number) {
		if (Abs(GetFraction(Number)) == .0) {
			return (int)Number;
		}
		if (Number > 0) {
			return Number + 1;
		}
		else {
			return (int)Number;
		}
	}

	static int Sqrt(float Number) {
		return pow(Number, 0.5);
	}
	static string  EncryptText(string Text, short EncryptionKey=2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey=2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}


	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}


};

