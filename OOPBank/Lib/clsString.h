#pragma once
#include <iostream>
#include<vector>
using namespace std;


class clsString {
    string _value;
    char _char;
  


    

public:
    clsString() {
        _value = " ";
       
       
    }
    clsString(const string value ) {
        _value = value;
      
    }

    void setValue(string value) {
        _value = value;
    }

    string getValue() {
        return _value;
    }

    __declspec(property(get = getValue, put = setValue))string value;

  
 
    
    static int length(string str) {
        return str.length();
    }

    int length() {
        return  _value.length();
    }
    //Print first Letter of each word

    static void firstLetter(string word) {

        bool isFirstLetter = true;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != ' ' && isFirstLetter) {
                cout << word[i] << endl;
            }
            isFirstLetter = (word[i] == ' ' ? true : false);
        }
    }
    void firstLetter() {
        return firstLetter(_value);
    }

    static string firstLetterToUpper(string str) {
        bool isLetter = true;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ' && isLetter) {
                str[i] = toupper(str[i]);
            }
            isLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }

    void firstLetterToUpper() {
        _value = firstLetterToUpper(_value);
    }


    static string firstLetterToLower(string str)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = tolower(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }
    void firstLetterToLower() {
        _value= firstLetterToLower(_value);


    }

    //string to lowercase
    static string toLower(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                str[i] = tolower(str[i]);
            }
        }
        return str;
    }

    void toLower() {
        _value= toLower(_value);
    }

    //string to Uppercase
    static string toUpper(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                str[i] = toupper(str[i]);
            }
        }
        return str;
    }

    string toUpper() {
        _value= toUpper(_value);
    }

    static char invertChar(char letter) {

        return isupper(letter) ? tolower(letter) : toupper(letter);
    }

    

   static string InvertAllStringLetterCase(string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            str[i] = invertChar(str[i]);
        }
        return str;
    }
    
   void InvertAllStringLetterCase( ) {
       _value = InvertAllStringLetterCase(_value);
    }

   // count letters 
   enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

   static short countLetters(string s1, enWhatToCount whatToCount = enWhatToCount::All)
   {
       if (whatToCount == enWhatToCount::All)
       {
           return s1.length();
       }
        short Counter = 0;
       for (short i = 0; i < s1.length(); i++)
       {
           if (whatToCount == enWhatToCount::CapitalLetters && isupper(s1[i])) 
           {
               Counter++;

           }
           if (whatToCount == enWhatToCount::SmallLetters && islower(s1[i]))
           {
               Counter++;
           }
               
       }
       return Counter;
   }


   short countLetters() {
       return countLetters(_value);
   }

   // count small letters

   static short countSmallLetters(string str) {
       short smallLetters = 0;

       for (int i = 0; i < str.length(); i++)
       {
           if (islower(str[i])) {
               smallLetters++;
           }

       }
       return smallLetters;
   }
   short countSmallLetters() {
       return countSmallLetters(_value);
   }
   // count capital letters
  static short countcapitalLetters(string str)
   {
       short capitalLetters = 0;

       for (int i = 0; i < str.length(); i++)
       {
           if (isupper(str[i])) {
               capitalLetters++;
           }

       }
       return capitalLetters;
   }

   short countcapitalLetters() {
       return countcapitalLetters(_value);
   }

   // count a letter in a string on same case
  

   static int countSpecificLetter(string str, char char1, bool matchedCase = true) {
       short counter = 0;
       for (int i = 0; i < str.length(); i++) {
           if (matchedCase)
           {
               if (str[i] == char1)
               {
                   counter++;
               }

           }
           else
           {
               if (tolower(str[i]) == tolower(char1)) {
                   counter++;
               }
           }
       }
       return counter;
   }

  
   short  countSpecificLetter(char letter, bool matchCase = true)
   {
       return countSpecificLetter(_value,letter, matchCase);
   }

  static  bool isVowel(char char1) {
       char1 = tolower(char1);
       return(char1 == 'a' || char1 == 'e' || char1 == 'o' || char1 == 'u' || char1 == 'i');
   }

  

  static int countVowels(string str) {
       short counter = 0;
       for (int i = 0; i < str.length(); i++) {
           if (isVowel(str[i])) {
               counter++;
           }
       }
       return counter;
   }

   int countVowels() {
       return countVowels(_value);
   }

  static void printVowels(string str) {
       for (int i = 0; i < str.length(); i++) {
           if (isVowel(str[i])) {
               cout << str[i] << " ";
           }
       }
   }
  void printVowels() {
      return printVowels(_value);
  }

  static vector <string> printEachWordInString(string str) {
      vector <string> word;
      bool isLetter = true;
      string oneWord = "";

      for (int i = 0; i < str.length(); i++) {
          if (str[i] != ' ' && isLetter)
          {
              oneWord = oneWord + (str[i]);
          }
          if (str[i] == ' ') {
              isLetter = (str[i] == ' ' ? true : false);

              word.push_back(oneWord);
              oneWord = "";

          }



      }
      word.push_back(oneWord);
      return word;

  }
  vector <string>  printEachWordInString() {
      return  printEachWordInString(_value);
  }


  static short countWordsInString(string str) {
      short counter = 0;
      string sWord = "";
      string dilm = " ";
      short pos = 0;
      while ((pos = str.find(dilm)) != std::string::npos)
      {
          sWord = str.substr(0, pos);
          if (sWord != "") {
              counter++;
          }
          str.erase(0, pos + dilm.length());
      }
      if (str != "") {
          counter++;
      }
      return counter;
  }
  short countWordsInString() {
      return  countWordsInString(_value);
  }
  
  static vector <string> split(string str, string  dilm) {
      vector <string> vString;

      string sWord = "";
      short pos = 0;

      while ((pos = str.find(dilm)) != std::string::npos) {
          sWord = str.substr(0, pos);
          
              vString.push_back(sWord);
          
          str.erase(0, pos + dilm.length());


      }
      if (str != "") {
          vString.push_back(str);
      }
      return vString;
  }
  vector <string> split(string delim) {
      return   split(_value, delim);
  }

  static string trimLeft(string str) {
      for (int i = 0; i < str.length(); i++)
      {
          if (str[i] != ' ') {
              return str.substr(i, str.length() - i);
          }
      }
      return"";
  }
  string trimLeft( ) {
      return  trimLeft(_value);
  }
 static string trimRight(string str) {
      for (int i = str.length() - 1; i >= 0; i--)
      {
          if (str[i] != ' ') {
              return str.substr(0, i + 1);
          }
      }
      return"";
  }
 string trimRight( ) {
     return  trimRight( _value);
 }
  
  static string trim(string str) {
      return trimLeft(trimRight(str));
  }
  string trim() {
      return trim(_value);
  }

  static string joinString(vector<string>& vString, string delim) {
      string str = "";

      for (string& word : vString) {
          str = str + word + delim;
      }
      if (str.empty()) return "";
      return str.substr(0, str.length() - delim.length());
  }

  static string joinString(string arrString[], short length, string delim)
  {

      string s1 = "";

      for (short i = 0; i < length; i++)
      {
          s1 = s1 + arrString[i] + delim;
      }

      return s1.substr(0, s1.length() - delim.length());

  }


  static string reverseWordsInString(string s1)
  {

      vector<string> vString;
      string s2 = "";

      vString = split(s1, " ");

      // declare iterator
      vector<string>::iterator iter = vString.end();

      while (iter != vString.begin())
      {

          --iter;

          s2 += *iter + " ";

      }

      s2 = s2.substr(0, s2.length() - 1); //remove last space.

      return s2;
  }

  void reverseWordsInString()
  {
      _value = reverseWordsInString(_value);
  }

  static string replaceWord(string s1, string stringToReplace, string sRepalceTo, bool matchCase = true)
  {

      vector<string> vString = split(s1, " ");

      for (string& s : vString)
      {

          if (matchCase)
          {
              if (s == stringToReplace)
              {
                  s = sRepalceTo;
              }

          }
          else
          {
              if (toLower(s) == toLower(stringToReplace))
              {
                  s = sRepalceTo;
              }

          }

      }

      return joinString(vString, " ");
  }

  string replaceWord(string stringToReplace, string sRepalceTo)
  {
      return replaceWord(_value, stringToReplace, sRepalceTo);
  }

  static string removePunctuations(string s1)
  {

      string s2 = "";

      for (short i = 0; i < s1.length(); i++)
      {
          if (!ispunct(s1[i]))
          {
              s2 += s1[i];
          }
      }

      return s2;

  }

  void removePunctuations()
  {
      _value = removePunctuations(_value);
  }



 
 
  
 
};