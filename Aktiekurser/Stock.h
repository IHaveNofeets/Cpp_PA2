#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <vector>
#include "DateTime.h"
#include "TradeInfo.h"

class Stock
{
public:
    Stock();
    Stock(const std::vector<TradeInfo>& tradeInfo) : mTradeInfo(tradeInfo) {}

    std::vector<TradeInfo> getTrades(unsigned int interval = TRADE_INTERVAL_DAY);

    std::vector<TradeInfo> getAllTradeInfo() const;
    void setAllTradeInfo(const std::vector<TradeInfo> &tradeInfo);

    static const unsigned int TRADE_INTERVAL_SECOND = 1; // Do not implement
    static const unsigned int TRADE_INTERVAL_MINUTE = 2;
    static const unsigned int TRADE_INTERVAL_HOUR = 3;
    static const unsigned int TRADE_INTERVAL_2HOUR = 4;
    static const unsigned int TRADE_INTERVAL_4HOUR = 5;
    static const unsigned int TRADE_INTERVAL_DAY = 6;
private:
    std::vector<TradeInfo> mTradeInfo;

};
#endif // STOCK_H
