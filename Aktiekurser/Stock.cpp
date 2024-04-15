#include "Stock.h"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <limits>

Stock::Stock() {}

//fejl: redefinition
//Stock::Stock(const std::vector<TradeInfo>& tradeInfo) : mTradeInfo(tradeInfo) {}

std::vector<TradeInfo> Stock::getTrades(unsigned int interval) {

    // Creating new object of TradeInfo
    std::vector<TradeInfo> newStockInfo;

    // N/A interval
    if (interval == 0 || interval == 1) {
        std::cout << "Not applicable time interval" << std::endl;
        exit(0);
    }
    // Minute
    if (interval == 2) {
        // return original data with original time interval of minutes
        return mTradeInfo;
    }
    // Hour, 2hour, 4hour and day
    else if (interval >= 3 && interval <= 6) {
        int numOfElements = 0;
        if (interval == 3) // Number of elements per hour
            numOfElements = 60;
        if (interval == 4) // Number of elements per 2 hours
            numOfElements = 120;
        if (interval == 5) // Number of elements per 4 hours
            numOfElements = 240;
        if (interval == 6) // Number of elements per day
            numOfElements = 420; // 9 to 16. 7 hours is 420 minutes.

        // reserve memory for vector
        newStockInfo.reserve(mTradeInfo.size() / numOfElements);

        for (size_t i = 0; i < mTradeInfo.size(); i += numOfElements) {
            // initialize variables
            double volumeSum = 0.0;
            double high = std::numeric_limits<double>::min();
            double low = std::numeric_limits<double>::max();

            // for numOfElements elements
            for (size_t j = i; j < std::min(i + numOfElements, mTradeInfo.size()); ++j) {
                // calculate sum of volume, low and high for the increment of numOfElements.
                volumeSum += mTradeInfo[j].getVolume();
                high = std::max(high, mTradeInfo[j].getHigh());
                low = std::min(low, mTradeInfo[j].getLow());
            }
            // appending values to new StockInfo object
            TradeInfo newTradeInfo(mTradeInfo[i].getDateTime(), mTradeInfo[i].getOpen(), high, low, mTradeInfo[std::min(i + numOfElements - 1, mTradeInfo.size() - 1)].getClose(), volumeSum);
            newStockInfo.push_back(newTradeInfo);
        }
        return newStockInfo;
    }
    else {return mTradeInfo;};
}

std::vector<TradeInfo> Stock::getAllTradeInfo() const{
    return mTradeInfo;
}

void Stock::setAllTradeInfo(const std::vector<TradeInfo> &tradeInfo){
    mTradeInfo = tradeInfo;
}

//Tradeinfo objekt indsættes i klasse.
//Anden periode "TRADE_INTERVAL" benyttes. High, Low, Close og volumen (minut) laves om til ny periode.
//
