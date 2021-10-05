/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the Date class.
*/
#include "Date.h"
using namespace std;

//Do not change this initialization
const unsigned Date::DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Do not change this function
Date::Date() : days_(0) {

}
ostream &operator<<(ostream &output, const Date &c2)
{
    int number = (int)c2.days_;
    string month;
    int day;
if(number<=364)
    {
        if (number >= 0 && number <31)
        {
            month = "January";
            day = number+1;
        }
        else if(number>=31 && number < 59)
        {
            month = "February";
            day = -31+number+1;
        }
        else if(number>=59 && number < 90)
        {
            month = "March";
            day = -59+number+1;
        }
        else if(number>=90 && number < 120)
        {
            month = "April";
            day = -90+number+1;
        }
        else if(number>=120 && number < 151)
        {
            month = "May";
            day = -120 + number+1;
        }
        else if(number>=151 && number < 181)
        {
            month = "June";
            day = -151 + number + 1;
        }
        else if(number>=181 && number < 212)
        {
            month = "July";
            day = -181 + number + 1;
        }
        else if(number>=212 && number < 243)
        {
            month = "August";
            day = -212+number+1;

        }
        else if(number>=243 && number < 273)
        {
            month = "September";
            day = -243+number+1;
        }
        else if(number>=273 && number < 304)
        {
            month = "October";
            day = -273+number+1;
        }
        else if(number>=304 && number < 334)
        {
            month = "Novermber";
            day = -304+number+1;
        }
        else if(number>=334 && number < 365)
        {
            month = "December";
            day = -334+number+1;
        }



    }
    else
    {
        cout << "Re-Enter a number between 0 and 364: ";
        //cin >> number;
    }
    output<<month<< " "<<day;
    return output;
}

bool Date::operator< (const Date& d) const{

    if(this->days_ < d.days_)
    { return true; }
    //else if ((this->month_ == d.month_) && (this->day_ < d.day_))
    //{ return true; }
    else
        return false;
}



Date &Date::operator=(const string &str) {
//    Date::days_ = str;
    std::string s = str;
    std::string delimiter = "/";
    int day;
    int month;
    int days_of_year_elapsed = 0;
    int previous_month_days_elapsed;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        month = std::stoi(token);
        s.erase(0, pos + delimiter.length());
    }
    day = std::stoi(s);
    // Get the number of days in each month

    if (month == 1) {
        days_ = (unsigned int) (days_of_year_elapsed + day - 1);
        //unsigned result = (unsigned int) days_of_year_elapsed;
    }
    else if (month == 2) {
	    days_ = Date::DAYS[month-2]+day-1;


    }

    else if (month == 3) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 4) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 4) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 5) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;


    }
    else if (month == 6) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;


    }
    else if (month == 7) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 8) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 9) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 10) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else if (month == 11) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;
    }
    else if (month == 12) {
        int summation = 0;
        for (int i=0; i < month-1; i++){
            summation += DAYS[i];
        }
	unsigned int hello = summation+day-1;
	days_ = hello;

    }
    else {
        cout<<"invalid month";


    }
    return (Date &) "";
}
