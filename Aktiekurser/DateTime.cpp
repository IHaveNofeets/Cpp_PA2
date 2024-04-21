#include "DateTime.h"
#include <iostream>

DateTime::DateTime() {}

void DateTime::parse(const std::string& dateTime){
    //data ex: 29.12.2017 16:18:00.000 GMT+0100
    //split data
    std::vector<std::string> data = split(dateTime,' ');

    //return if the format is not right
    if(data.size() < 3){
        std::cout << "Invalued dateTime to parse: " << dateTime << std::endl;
        return;
    }

    std::string date = data[0];
    std::string time = data[1];
    std::string timeZone = data[2];

    //split data more
    std::vector<std::string> datedata = split(date,'.');
    std::vector<std::string> timedata = split(time,':');

    //return if the format is not right
    if(datedata.size() < 3 || timedata.size() < 3){
        std::cout << "Invalued dateTime to parse: " << dateTime << std::endl;
        return;
    }

    //handel day:
    mDay = std::stoi(datedata[0]);
    //handel mouth:
    mMonth = std::stoi(datedata[1]);
    //handel year:
    mYear = std::stoi(datedata[2]);
    //handel hour:
    mHour = std::stoi(timedata[0]);
    //handel minute:
    mMinute = std::stoi(timedata[1]);
    //handel second:
    mSecond = static_cast<unsigned int>(std::stof(timedata[2]));

    //handel timezone:
    if(timeZone.substr(0,3) == "GMT"){
        mTimezone = std::stoi(timeZone.substr(3));

    }

}
unsigned int DateTime::getYear() const{
    return mYear;
}
void DateTime::setYear(unsigned int year){
    if(year >= 1700){//only valid values saved
        mYear = year;
    }
}
unsigned int DateTime::getMonth() const{
    return mMonth;
}
void DateTime::setMonth(unsigned int month){
    if(month < 12){//only valid values saved
        mMonth = month;
    }
}
unsigned int DateTime::getDay() const{
    return mDay;
}
void DateTime::setDay(unsigned int day){
    if(day < 32){//only valid values saved
        mDay = day;
    }
}
unsigned int DateTime::getHour() const{
    return mHour;
}
void DateTime::setHour(unsigned int hour){
    if(hour < 24){//only valid values saved
        mHour = hour;
    }
}
unsigned int DateTime::getMinute() const{
    return mMinute;
}
void DateTime::setMinute(unsigned int minute){
    if(minute < 60){//only valid values saved
        mMinute = minute;
    }
}
unsigned int DateTime::getSecond() const{
    return mSecond;
}
void DateTime::setSecond(unsigned int second){
    if(second < 60){//only valid values saved
        mSecond = second;
    }
}
int DateTime::getTimezone() const{
    return mTimezone;
}
void DateTime::setTimezone(int value){
    mTimezone = value;
}

//small change from the version in TradeLoader
std::vector<std::string> DateTime::split(const std::string& line, char delim){
    //have a vaible that is not const
    std::string line_remender = line;
    //output to save to
    std::vector<std::string> out;

    while(line_remender.size() != 0) {
        //finds the next time delim and gets from pos 0 to that pos and then removes the copyed part + 1 (for ',')
        int pos = line_remender.find(delim);
        if(pos == std::string::npos){pos = line_remender.size();} //end of line
        std::string part = line_remender.substr(0,pos);
        out.push_back(part);
        line_remender.erase(0,pos+1);
    }
    return out;
}

//get out in format YYYYMMDDHHmmSS (M is month and m is minute)
unsigned long DateTime::toLong() const{
    return getSecond() +
           getMinute() *    100 +
           getHour() *      10000 +
           getDay() *       1000000 +
           getMonth() *     100000000 +
           getYear() *      10000000000;
}
