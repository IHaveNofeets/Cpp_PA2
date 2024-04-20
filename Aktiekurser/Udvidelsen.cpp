#include "Udvidelsen.h"
#include <vector>
#include <iostream>
Udvidelsen::Udvidelsen()
{

}

void Udvidelsen::UdvidelsenMain(Stock& st){

    std::vector<TradeInfo> TradesHour = st.getTrades(Stock::TRADE_INTERVAL_HOUR);

    int endhour = 0;
    int days = 0;
    double stockquant = 0;
    double profit = 0;
    
    std::cout << "Hvornaar vil du starte en handel?" << std::endl;

    std::cout << "Date? format: DD.MM.YYYY" << std::endl;
    std::string date = "";
    std::cin >> date;

    std::cout << "Time? format: HH:MM:SS" << std::endl;
    std::string time = "";
    std::cin >> time;
    DateTime startTime;
    startTime.parse(date + " " + time);

    std::cout << "hvor mange timer til salg?" << std::endl;
    std::cin >> endhour;
    
    std::cout << "hvor mange aktier vil du købe?" << std::endl;
    std::cin >> stockquant;

    endhour  += startTime.getHour();
    days = endhour / 24;
    endhour  = endhour - days * 24;
    DateTime endTime{startTime};
    endTime.setHour(endhour);
    days += endTime.getDay();
    endTime.setDay(days);

    int startIndex;
    int endIndex;
    unsigned long startTimeInt = startTime.getSecond() + startTime.getMinute() * 100 +
            startTime.getHour() * 10000 + startTime.getDay() * 1000000 +
            startTime.getMonth() * 100000000 + startTime.getYear() * 10000000000;
    unsigned long endTimeInt = endTime.getSecond() + endTime.getMinute() * 100 +
            endTime.getHour() * 10000 + endTime.getDay() * 1000000 +
            endTime.getMonth() * 100000000 + endTime.getYear() * 10000000000;
    bool startSat = false;
    bool endSat = false;

    for(int i = 0; i < TradesHour.size(); ++i){
        DateTime targetTime = TradesHour[i].getDateTime();
        unsigned long targetTimeInt = targetTime.getSecond() + targetTime.getMinute() * 100 +
                targetTime.getHour() * 10000 + targetTime.getDay() * 1000000 +
                targetTime.getMonth() * 100000000 + targetTime.getYear() * 10000000000;
        if(!startSat && startTimeInt > targetTimeInt){
            startIndex = i;
            startSat = true;
        }
        if(!endSat && endTimeInt > targetTimeInt){
            endIndex = i;
            endSat = true;
        }
        if(startSat && endSat){
            break;
        }
    }

   profit = (TradesHour[endIndex].getClose() - TradesHour[startIndex].getOpen()) * stockquant;
   if(profit >= 0){
    std::cout << "din profit er: " << profit << " kr" << std::endl;
    }
   else{
    std::cout << "dit tab er: " << profit << " kr" << std::endl;
   }






}
