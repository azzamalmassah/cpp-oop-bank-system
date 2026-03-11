#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class clsDate
{
	int _day = 1;
	int _month = 1;
	int _year = 1900;



public:
	clsDate()
	{
		
		// system date
		time_t t = time(nullptr);

		tm now;                   
		localtime_s(&now, &t);


		_year = now.tm_year+ 1900;
		_month = now.tm_mon + 1;
		_day = now.tm_mday;
		
	}
	clsDate(int day, int month, int year)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	
	clsDate(string date) 
	{
	
		stringDate(date);
	}
	clsDate(int numberOfDays, int year) {
		clsDate Date1 = getDateFromDayOrderInYear(numberOfDays, year);
		_day = Date1.day;
		_month = Date1.month;
		_year = Date1.year;

		
	}
	
	
	void setDay(int day)
	{
		_day = day;
		
	}
	void setMonth(int month)
	{
		_month = month;

	}	void setYear(int year)
	{
		_year = year;

	}


	int getDay() {
		return _day;
	}
	int getMonth() {
		return _month;
	}
	int getYear() {
		return _year;
	}

	__declspec(property(get = getDay, put = setDay)) int day;
	__declspec(property(get = getMonth, put = setMonth)) int month;
	__declspec(property(get = getYear, put = setYear)) int year;

	void stringDate(string date) 
	{
		vector <string> date1;
		date1=split(date,"/");
		_year = stoi(date1[2]);
		_month = stoi(date1[1]);
		_day = stoi(date1[0]);
	
	}

	static clsDate getSystemDate()
	{
		//system date
		time_t t = time(nullptr);

		tm now;
		localtime_s(&now, &t);
	
		

		short day, month, year;

		year = now.tm_year + 1900;
		month = now.tm_mon + 1;
		day = now.tm_mday;

		return clsDate(day, month, year);
	}

	static bool isValid(clsDate date) {
		int maxDay = 0;
		if (date.month > 12 || date.month < 1) {

			return false;
		}
		maxDay = numberOfDaysInMonth(date.year, date.month);


		if (date.day > maxDay || date.day < 1) {
			return false;
		}
		return true;
	}

	bool isValid() {
		return isValid(*this);
	}

	static string getSystemDateTimeString() {
		// system date
		time_t t = time(nullptr);

		tm now;
		localtime_s(&now, &t);
		short day, month, year;

		year = now.tm_year + 1900;
		month = now.tm_mon + 1;
		day = now.tm_mday;

		string time = to_string(now.tm_hour)+":" + to_string(now.tm_min) + ":" + to_string(now.tm_sec);
		
		return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + "/" + "-" + time;
	}
	
	vector <string> split(string str, string delim) 
	{

		size_t pos = 0;
		string word = "";
		vector<string> result;
		while ((pos = str.find(delim)) != std::string::npos) 
		{

			result.push_back(str.substr(0, pos));
			str.erase(0, pos + delim.length());
		}
		result.push_back(str);

		return result;
	}
	static string dateToString(clsDate date)
	{
		return  to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
	}

	string dateToString()
	{
		return  dateToString(*this);
	}
	static short numberOfDaysInAYear(short year)
	{
		return  isLeapYear(year) ? 365 : 364;
	}

	short numberOfDaysInAYear() {
		return numberOfDaysInAYear(_year);
	}

	static short numberOfHoursInAYear(short year)
	{
		return  numberOfDaysInAYear(year) * 24;
	}

	short numberOfHoursInAYear()
	{
		return  numberOfHoursInAYear(_year);
	}

	static int numberOfMinutesInAYear(short year)
	{
		return  numberOfHoursInAYear(year) * 60;
	}

	int numberOfMinutesInAYear()
	{
		return  numberOfMinutesInAYear(_year);
	}

	static int numberOfSecondsInAYear(short year)
	{
		return  numberOfMinutesInAYear(year) * 60;
	}

	int numberOfSecondsInAYear()
	{
		return  numberOfSecondsInAYear();
	}
	//
	
	static short numberOfHoursInAMonth(short month, short year)
	{
		return  numberOfDaysInMonth(month, year) * 24;
	}

	short numberOfHoursInAMonth()
	{
		return  numberOfDaysInMonth(_month, _year) * 24;
	}

	static int numberOfMinutesInAMonth(short month, short year)
	{
		return  numberOfHoursInAMonth(month, year) * 60;
	}

	int numberOfMinutesInAMonth()
	{
		return  numberOfHoursInAMonth(_month, _year) * 60;
	}

	static int numberOfSecondsInAMonth(short month, short year)
	{
		return  numberOfMinutesInAMonth(month, year) * 60;
	}

	int numberOfSecondsInAMonth()
	{
		return  numberOfMinutesInAMonth(_month, _year) * 60;
	}

	static string dayShortName(short dayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder];

	}

	static string dayShortName(short day, short month, short year)
	{

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder(day, month, year)];

	}

	string DayShortName()
	{

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[dayOfWeekOrder(_day, _month, _year)];

	}
	//

	static clsDate getDateFromDayOrderInYear(short dateOrderInYear, short year)
	{

		clsDate date;
		short remainingDays = dateOrderInYear;
		short monthDays = 0;
		date.year = year;
		date.month = 1;

		while (true)
		{
			monthDays = numberOfDaysInMonth(date.month, year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				date.month++;
			}
			else
			{
				date.day = remainingDays;
				break;
			}

		}

		return date;
	}




	void printDate() {
		cout << _day << "/" << _month << "/" << _year;
	}

	static bool isLeapYear(int year) {
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	bool isLeapYear() {
		return isLeapYear(_year);
	}
	
	static short numberOfDaysInMonth( short month,short year ) {
		if (month < 1 || month >12) {
			return 0;
		}
		int numberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return month == 2 ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
	}
	short numberOfDaysInMonth() {
		return numberOfDaysInMonth(_month, _year);
	}




	static bool isLastDayInMonth(clsDate date) {
		return date._day == numberOfDaysInMonth(date._month, date._year);
	}
	

	static bool isLastMonthInYear(clsDate date) {

		return date._month == 12;
	}
	bool isLastMonthInYear() {
		return isLastMonthInYear(*this);
	}



	static clsDate addOneDay(clsDate date) {

		if (isLastDayInMonth(date)) {
			if (isLastMonthInYear(date)) {
				
				date._year++;
				date._day = 1;
				date._month = 1;
				return date;
			}
			date._day = 1;
			date._month++;
			
			return date;
		}
		date._day++;
		
		return date;
	}
	
	void increaseDateByOneDay() 
	{
		
		  *this = addOneDay(*this);
		

}
	
	static void increaseDateByXDay(clsDate  date, int daysToAdd) {
		for (int i = 0; i < daysToAdd; i++) {
			date = addOneDay(date);
		}

	}
	static int dayOfWeekOrder(int day, int month, int year) {
		short a, y, m;
		a = (14 - month) / 12;
		y = year - a;
		m = month + 12 * a - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	int dayOfWeekOrder() {
		return  dayOfWeekOrder( _day,  _month, _year);
	}
	static string monthShortName(short monthNumber)
	{
		string months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (months[monthNumber - 1]);
	}
	string monthShortName() {
		return monthShortName(_month);
	}
	
	static void printMonthCalendar(short month, short year)
	{
		int numberOfDays;

		// Index of the day from 0 to 6
		int current = dayOfWeekOrder(1, month, year);

		numberOfDays = numberOfDaysInMonth( month, year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			monthShortName(month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= numberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}


	void  printMonthCalendar() {
		return  printMonthCalendar(_month, _year);
	}

	static string dayName(short index) {
		static string days[7] = {
			"Sunday", "Monday", "Tuesday",
			"Wednesday", "Thursday", "Friday", "Saturday"
		};
		return days[index];
	}

	static void printYearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, Year);
		}

		return;
	}

	void printYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			printMonthCalendar(i, _year);
		}

		return;
	}
	//
	static short daysFromTheBeginingOfTheYear(short day, short month, short year)
	{


		short totalDays = 0;

		for (int i = 1; i <= month - 1; i++)
		{
			totalDays += numberOfDaysInMonth(i, year);
		}

		totalDays += day;

		return totalDays;
	}


	short daysFromTheBeginingOfTheYear()
	{


		short totalDays = 0;

		for (int i = 1; i <= _month - 1; i++)
		{
			totalDays += numberOfDaysInMonth(i, _year);
		}

		totalDays += _day;

		return totalDays;
	}
	//

	void AddDays(short days)
	{


		short remainingDays = days + daysFromTheBeginingOfTheYear(_day, _month, _year);
		short monthDays = 0;

		_month = 1;

		while (true)
		{
			monthDays = numberOfDaysInMonth(_month, _year);

			if (remainingDays > monthDays)
			{
				remainingDays -= monthDays;
				_month++;

				if (_month > 12)
				{
					_month = 1;
					_year++;

				}
			}
			else
			{
				_day = remainingDays;
				break;
			}

		}


	}

	static bool isDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		return  (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
	}
	static bool IsDate1BeforeDate2(clsDate date1, clsDate date2)
	{
		return  (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
	}


	bool isDateBeforeDate2(clsDate date2)
	{
		//note: *this sends the current object :-) 
		return  isDate1BeforeDate2(*this, date2);

	}

	static bool isDate1EqualDate2(clsDate date1, clsDate date2)
	{
		return  (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
	}
	static bool IsDate1EqualDate2(clsDate date1, clsDate date2)
	{
		return  (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
	}


	bool isDateEqualDate2(clsDate date2)
	{
		return  isDate1EqualDate2(*this, date2);
	}


	bool isLastDayInMonth()
	{

		return isLastDayInMonth(*this);

	}

	static bool isLastMonthInYear(short month)
	{
		return (month == 12);
	}



	void addOneDay()

	{
		*this = addOneDay(*this);
	}

	static void  Swap(clsDate& Date1, clsDate& Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static int getDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
	{
		//this will take care of negative diff
		int days = 0;
		short sawpFlagValue = 1;

		if (!isDate1BeforeDate2(date1, date2))
		{
			//Swap Dates 
			Swap(date1, date2);
			sawpFlagValue = -1;

		}

		while (isDate1BeforeDate2(date1, date2))
		{
			days++;
			date1 = addOneDay(date1);
		}

		return includeEndDay ? ++days * sawpFlagValue : days * sawpFlagValue;
	}

	int getDifferenceInDays(clsDate date2, bool includeEndDay = false)
	{
		return getDifferenceInDays(*this, date2, includeEndDay);
	}

	static short calculateMyAgeInDays(clsDate dateOfBirth)
	{
		return getDifferenceInDays(dateOfBirth, clsDate::getSystemDate(), true);
	}
	//above no need to have nonstatic function for the object because it does not depend on any data from it.

	static clsDate increaseDateByOneWeek(clsDate& date)
	{

		for (int i = 1; i <= 7; i++)
		{
			date = addOneDay(date);
		}

		return date;
	}

	void increaseDateByOneWeek()
	{
		increaseDateByOneWeek(*this);
	}

	clsDate increaseDateByXWeeks(short weeks, clsDate& date)
	{

		for (short i = 1; i <= weeks; i++)
		{
			date = increaseDateByOneWeek(date);
		}
		return date;
	}

	void increaseDateByXWeeks(short weeks)
	{
		increaseDateByXWeeks(weeks, *this);
	}

	clsDate increaseDateByOneMonth(clsDate& date)
	{

		if (date.month == 12)
		{
			date.month = 1;
			date.year++;
		}
		else
		{
			date.month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}

		return date;
	}

	void increaseDateByOneMonth()
	{

		increaseDateByOneMonth(*this);

	}

	clsDate increaseDateByXDays(short days, clsDate& date)
	{

		for (short i = 1; i <= days; i++)
		{
			date = addOneDay(date);
		}
		return date;
	}

	void increaseDateByXDays(short days)
	{

		increaseDateByXDays(days, *this);
	}

	clsDate increaseDateByXMonths(short months, clsDate& date)
	{

		for (short i = 1; i <= months; i++)
		{
			date = increaseDateByOneMonth(date);
		}
		return date;
	}

	void increaseDateByXMonths(short months)
	{
		increaseDateByXMonths(months, *this);
	}

	static clsDate increaseDateByOneYear(clsDate& date)
	{
		date.year++;
		return date;
	}

	void increaseDateByOneYear()
	{
		increaseDateByOneYear(*this);
	}

	clsDate increaseDateByXYears(short years, clsDate& date)
	{
		date.year += years;
		return date;

	}

	void increaseDateByXYears(short years)
	{
		increaseDateByXYears(years);
	}

	clsDate increaseDateByOneDecade(clsDate& date)
	{
		//Period of 10 years
		date.year += 10;
		return date;
	}

	void increaseDateByOneDecade()
	{
		increaseDateByOneDecade(*this);
	}

	clsDate increaseDateByXDecades(short decade, clsDate& date)
	{
		date.year += decade * 10;
		return date;
	}

	void increaseDateByXDecades(short decade)
	{
		increaseDateByXDecades(decade, *this);
	}

	clsDate increaseDateByOneCentury(clsDate& date)
	{
		//Period of 100 years
		date.year += 100;
		return date;
	}

	void increaseDateByOneCentury()
	{
		increaseDateByOneCentury(*this);
	}

	clsDate increaseDateByOneMillennium(clsDate& date)
	{
		//Period of 1000 years
		date.year += 1000;
		return date;
	}

	clsDate increaseDateByOneMillennium()
	{
		increaseDateByOneMillennium(*this);
	}

	static clsDate decreaseDateByOneDay(clsDate date)
	{
		if (date.day == 1)
		{
			if (date.month == 1)
			{
				date.month = 12;
				date.day = 31;
				date.year--;
			}
			else
			{

				date.month--;
				date.day = numberOfDaysInMonth(date.month, date.year);
			}
		}
		else
		{
			date.day--;
		}

		return date;
	}

	void decreaseDateByOneDay()
	{
		decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByOneWeek(clsDate& date)
	{

		for (int i = 1; i <= 7; i++)
		{
			date = decreaseDateByOneDay(date);
		}

		return date;
	}

	void decreaseDateByOneWeek()
	{
		decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(short weeks, clsDate& date)
	{

		for (short i = 1; i <= weeks; i++)
		{
			date = decreaseDateByOneWeek(date);
		}
		return date;
	}

	void decreaseDateByXWeeks(short weeks)
	{
		decreaseDateByXWeeks(weeks, *this);
	}

	static clsDate decreaseDateByOneMonth(clsDate& date)
	{

		if (date.month == 1)
		{
			date.month = 12;
			date.year--;
		}
		else
			date.month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);
		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}


		return date;
	}

	void decreaseDateByOneMonth()
	{
		decreaseDateByOneMonth(*this);
	}

	static clsDate decreaseDateByXDays(short days, clsDate& date)
	{

		for (short i = 1; i <= days; i++)
		{
			date = decreaseDateByOneDay(date);
		}
		return date;
	}

	void decreaseDateByXDays(short days)
	{
		decreaseDateByXDays(days, *this);
	}

	static clsDate decreaseDateByXMonths(short months, clsDate& date)
	{

		for (short i = 1; i <= months; i++)
		{
			date = decreaseDateByOneMonth(date);
		}
		return date;
	}

	void decreaseDateByXMonths(short months)
	{
		decreaseDateByXMonths(months, *this);
	}

	static clsDate decreaseDateByOneYear(clsDate& date)
	{

		date.year--;
		return date;
	}

	void decreaseDateByOneYear()
	{
		decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByXYears(short years, clsDate& date)
	{

		date.year -= years;
		return date;
	}

	void decreaseDateByXYears(short years)
	{
		decreaseDateByXYears(years, *this);
	}

	static clsDate decreaseDateByOneDecade(clsDate& date)
	{
		//Period of 10 years
		date.year -= 10;
		return date;
	}

	void decreaseDateByOneDecade()
	{
		decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecades(short decades, clsDate& date)
	{

		date.year -= decades * 10;
		return date;
	}

	void decreaseDateByXDecades(short decades)
	{
		decreaseDateByXDecades(decades, *this);
	}

	static clsDate decreaseDateByOneCentury(clsDate& date)
	{
		//Period of 100 years
		date.year -= 100;
		return date;
	}

	void decreaseDateByOneCentury()
	{
		decreaseDateByOneCentury(*this);
	}

	static clsDate decreaseDateByOneMillennium(clsDate& date)
	{
		//Period of 1000 years
		date.year -= 1000;
		return date;
	}

	void decreaseDateByOneMillennium()
	{
		decreaseDateByOneMillennium(*this);
	}


	static short isEndOfWeek(clsDate date)
	{
		return  dayOfWeekOrder(date.day, date.month, date.year) == 6;
	}

	short isEndOfWeek()
	{
		return isEndOfWeek(*this);
	}

	static bool isWeekEnd(clsDate date)
	{
		//Weekends are Fri and Sat
		short dayIndex = dayOfWeekOrder(date.day, date.month, date.year);
		return  (dayIndex == 5 || dayIndex == 6);
	}

	bool isWeekEnd()
	{
		return  isWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date)
	{
		
		return !isWeekEnd(date);

	}

	bool isBusinessDay()
	{
		return  isBusinessDay(*this);
	}

	static short daysUntilTheEndOfWeek(clsDate date)
	{
		return 6 - dayOfWeekOrder(date.day, date.month, date.year);
	}

	short daysUntilTheEndOfWeek()
	{
		return  daysUntilTheEndOfWeek(*this);
	}

	static short daysUntilTheEndOfMonth(clsDate date1)
	{

		clsDate endOfMontDate;
		endOfMontDate.day = numberOfDaysInMonth(date1.month, date1.year);
		endOfMontDate.month = date1.month;
		endOfMontDate.year = date1.year;

		return getDifferenceInDays(date1, endOfMontDate, true);

	}

	short daysUntilTheEndOfMonth()
	{
		return daysUntilTheEndOfMonth(*this);
	}

	static short daysUntilTheEndOfYear(clsDate date1)
	{

		clsDate endOfYearDate;
		endOfYearDate.day = 31;
		endOfYearDate.month = 12;
		endOfYearDate.year = date1.year;

		return getDifferenceInDays(date1, endOfYearDate, true);

	}

	short daysUntilTheEndOfYear()
	{
		return  daysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short calculateBusinessDays(clsDate dateFrom, clsDate dateTo)
	{

		short days = 0;
		while (isDate1BeforeDate2(dateFrom, dateTo))
		{
			if (isBusinessDay(dateFrom))
				days++;

			dateFrom = addOneDay(dateFrom);
		}

		return days;

	}

	static short calculateVacationDays(clsDate dateFrom, clsDate dateTo)
	{
		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		return calculateBusinessDays(dateFrom, dateTo);

	}
	//above method is eough , no need to have method for the object

	static clsDate calculateVacationReturnDate(clsDate dateFrom, short vacationDays)
	{

		short weekEndCounter = 0;

		for (short i = 1; i <= vacationDays; i++)
		{

			if (isWeekEnd(dateFrom))
				weekEndCounter++;

			dateFrom = addOneDay(dateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= weekEndCounter; i++)
			dateFrom = addOneDay(dateFrom);

		return dateFrom;
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualDate2(date1, date2));

	}
	static bool IsDate1AfterDate2(clsDate date1, clsDate date2)
	{
		return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualDate2(date1, date2));

	}

	bool IsDateAfterDate2(clsDate date2)
	{
		return isDate1AfterDate2(*this, date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate date1, clsDate date2)
	{
		if (isDate1BeforeDate2(date1, date2))
			return enDateCompare::Before;

		if (isDate1EqualDate2(date1, date2))
			return enDateCompare::Equal;

		
		return enDateCompare::After;

	}

	enDateCompare compareDates(clsDate date2)
	{
		return CompareDates(*this, date2);
	}

	//


};

