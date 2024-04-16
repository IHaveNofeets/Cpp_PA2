#include "TradeInfo.h"

TradeInfo::TradeInfo() {

}

double TradeInfo::getOpen() const{
    return mOpen;
}
void TradeInfo::setOpen(double open){
    mOpen = open;
}
double TradeInfo::getHigh() const{
    return mHigh;
}
void TradeInfo::setHigh(double high){
    mHigh = high;
}
double TradeInfo::getLow() const{
    return mLow;
}
void TradeInfo::setLow(double low){
    mLow = low;
}
double TradeInfo::getClose() const{
    return mClose;
}
void TradeInfo::setClose(double close){
    mClose = close;
}
double TradeInfo::getVolume() const{
    return mVolume;
}
void TradeInfo::setVolume(double volume){
    mVolume = volume;
}
DateTime TradeInfo::getDateTime() const{
    return mDateTime;
}
void TradeInfo::setDateTime(const DateTime &dateTime){
    mDateTime = dateTime;
}
