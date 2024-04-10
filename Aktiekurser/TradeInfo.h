#ifndef TRADEINFO_H
#define TRADEINFO_H
#include "DateTime.h"

class TradeInfo
{
public:
    TradeInfo();
    TradeInfo(const DateTime& dateTime, double open, double high, double low, double close, double volume)
        : mDateTime(dateTime), mOpen(open), mHigh(high), mLow(low), mClose(close), mVolume(volume)
    {}
    double getOpen() const;
    void setOpen(double open);
    double getHigh() const;
    void setHigh(double high);
    double getLow() const;
    void setLow(double low);
    double getClose() const;
    void setClose(double close);
    double getVolume() const;
    void setVolume(double volume);
    DateTime getDateTime() const;
    void setDateTime(const DateTime &dateTime);
private:
    DateTime mDateTime;
    double mOpen = 0, mHigh = 0, mLow = 0, mClose = 0, mVolume = 0;
};
#endif // TRADEINFO_H
