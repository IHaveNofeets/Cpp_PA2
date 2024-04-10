#ifndef TRADELOADER_H
#define TRADELOADER_H
#include <array>
#include <string>
#include <vector>
#include "TradeInfo.h"

class TradeLoader
{
public:
    TradeLoader();
    void load(const std::string& filename);
    std::vector<std::array<std::string, 6> > getData() { return mData; }
    std::vector<TradeInfo> getTradeInfo();
private:
    std::array<std::string, 6> split(const std::string& line, char delim);
private:
    std::vector<std::array<std::string, 6> > mData;
};
#endif // TRADELOADER_
