#ifndef DATETIME_H
#define DATETIME_H

#include <string>

class DateTime
{
public:
    DateTime();
    DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, int timezone)
        : mYear(year), mMonth(month), mDay(day), mHour(hour), mMinute(minute), mSecond(second), mTimezone(timezone) {
    }

    DateTime(const std::string& dateTime) { parse(dateTime); }

    //unsigned int getDayOfWeek() const;
    void parse(const std::string& dateTime);
    unsigned int getYear() const;
    void setYear(unsigned int year);
    unsigned int getMonth() const;
    void setMonth(unsigned int month);
    unsigned int getDay() const;
    void setDay(unsigned int day);
    unsigned int getHour() const;
    void setHour(unsigned int hour);
    unsigned int getMinute() const;
    void setMinute(unsigned int minute);
    unsigned int getSecond() const;
    void setSecond(unsigned int second);
    int getTimezone() const;
    void setTimezone(int value);
private:
    unsigned int mYear = 0, mMonth = 0, mDay = 0, mHour = 0, mMinute = 0, mSecond = 0;
    int mTimezone = 0;
};
#endif // DATETIME_H
