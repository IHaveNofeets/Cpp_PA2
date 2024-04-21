#include "Stock.h"
#include <limits>
#include <iostream>
#include <ostream>

Stock::Stock() {}

std::vector<TradeInfo> Stock::getTrades(unsigned int interval) {

    // Creating new object of TradeInfo
    std::vector<TradeInfo> newStockInfo;

    // N/A periode
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
        // Reserve memory for the newStockInfo vector
        newStockInfo.reserve(mTradeInfo.size()); // Will be fittet later

        // While loop for appending datetime, open, high, low, close, sumOfVolume of data segments based on period
        size_t i = 0;
        while (i < mTradeInfo.size()) {

            // Start time for segment of mTradeInfo (original data)
            int startTime = (interval == 6) ? mTradeInfo[i].getDateTime().getDay() : mTradeInfo[i].getDateTime().getHour();

            // Next element in mTradeInfo
            size_t nextElement = i + 1;
            // While loop for logic of segments of data
            while (nextElement < mTradeInfo.size()) {
                // Time of next element
                int nextElementTime = (interval == 6) ? mTradeInfo[nextElement].getDateTime().getDay() : mTradeInfo[nextElement].getDateTime().getHour();

                // Logic for segments of data based on period.
                if (interval == 3 && nextElementTime != startTime) { // 1-Hourly interval
                    break;
                } else if (interval == 4 && (nextElementTime - startTime + 24) % 24 >= 2) { // 2-hourly interval
                    break;
                } else if (interval == 5 && (nextElementTime - startTime + 24) % 24 >= 4) { // 4-hourly interval
                    break;
                } else if (interval == 6 && (nextElementTime - startTime + 7) % 7 >= 1) { // Daily interval
                    break;
                }else if (mTradeInfo[i].getDateTime().getMonth() != mTradeInfo[nextElement].getDateTime().getMonth()){
                    break;
                }else if (mTradeInfo[i].getDateTime().getYear() != mTradeInfo[nextElement].getDateTime().getYear()){
                    break;
                }

                // Move to the next data point
                ++nextElement;
            }

            // Initialize variables for volume, high, and low
            double volumeSum = 0.0;
            double high = std::numeric_limits<double>::min();
            double low = std::numeric_limits<double>::max();

            // Calculate sum of volume, high, and low for the current period
            for (size_t j = i; j < nextElement; ++j) {
                volumeSum += mTradeInfo[j].getVolume();
                high = std::max(high, mTradeInfo[j].getHigh());
                low = std::min(low, mTradeInfo[j].getLow());
            }

            // Creating a new object of tradeInfo with values of datetime, open, high, low, last close, sum of volume
            TradeInfo newTradeInfo(mTradeInfo[i].getDateTime(), mTradeInfo[i].getOpen(), high, low, mTradeInfo[nextElement - 1].getClose(), volumeSum);
            // Appending TradeInfo object to TradeInfo vector.
            newStockInfo.push_back(newTradeInfo);

            // Updating the starting index for the next period
            i = nextElement;
        }
        // Fitting allocated memory to vector
        newStockInfo.shrink_to_fit();
        // Returning vector.
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

