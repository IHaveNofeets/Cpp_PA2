#include <iomanip>
#include <iostream>
#include "DateTime.h"
#include "TradeLoader.h"
#include "Stock.h"
#include "Udvidelsen.h"

void printTrade(const TradeInfo& ti) {
    char oldFill = std::cout.fill();
    std::cout.fill('0');
    std::cout << std::setw(2) << ti.getDateTime().getYear()
              << "-" << std::setw(2) << ti.getDateTime().getMonth()
              << "-" << std::setw(2) << ti.getDateTime().getDay()
              << " " << std::setw(2) << ti.getDateTime().getHour()
              << ":" << std::setw(2) << ti.getDateTime().getMinute()
              << " ";
    std::cout.fill(oldFill);
    std::cout << std::setw(10) << ti.getOpen()
              << std::setw(10) << ti.getHigh()
              << std::setw(10) << ti.getLow()
              << std::setw(10) << ti.getClose()
              << std::setw(10) << ti.getVolume() << "\n";
}

void printTrades(const std::vector<TradeInfo>& ti) {
    for (unsigned int i = 0; i < 24; ++i) {
        printTrade(ti[i]);
    }
    printTrade(ti.back());
}

int main() {
    TradeLoader sl;

    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2017-31.12.2017.csv");
    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2018-31.12.2018.csv");
    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2019-31.12.2019.csv");
    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2020-31.12.2020.csv");
    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2021-31.12.2021.csv");
    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2022-31.12.2022.csv");
    sl.load("../StockTrading/COLOB.DKDKK_Candlestick_1_M_BID_01.01.2023-21.03.2023.csv");

    //sl.load("../StockTrading/ColoTest.csv");
    std::vector<TradeInfo> tinfo = sl.getTradeInfo();

    Stock coloplast;

    coloplast.setAllTradeInfo(tinfo);

    std::vector<TradeInfo> openHour = coloplast.getTrades(Stock::TRADE_INTERVAL_HOUR);
    std::vector<TradeInfo> open2Hour = coloplast.getTrades(Stock::TRADE_INTERVAL_2HOUR);
    std::vector<TradeInfo> open4Hour = coloplast.getTrades(Stock::TRADE_INTERVAL_4HOUR);
    std::vector<TradeInfo> openDay = coloplast.getTrades(Stock::TRADE_INTERVAL_DAY);


    std::cout << "-----------------------" << std::endl;
    std::cout << "-- Open (hour) --" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printTrades(openHour);
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "-- Open (2 hours) --" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printTrades(open2Hour);
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "-- Open (4 hours) --" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printTrades(open4Hour);
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "-- Open (day) --" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printTrades(openDay);
    std::cout << std::endl;

    //udvidelsen kaldes
    Udvidelsen ud;
    ud.UdvidelsenMain(coloplast);

    return 0;

}
