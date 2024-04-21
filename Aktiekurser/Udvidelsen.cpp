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
    //parse string to DateTime from a user from Danmark
    startTime.parse(date + " " + time + " GMT+0100");

    std::cout << "hvor mange timer til salg?" << std::endl;
    std::cin >> endhour;
    
    std::cout << "hvor mange aktier vil du købe?" << std::endl;
    std::cin >> stockquant;

    //calc end DateTime
    endhour  += startTime.getHour();
    days = endhour / 24;
    endhour  = endhour - days * 24;
    DateTime endTime{startTime};
    endTime.setHour(endhour);
    days += endTime.getDay();
    endTime.setDay(days);


    int startIndex;
    int endIndex;
    //saves DateTime as a long
    unsigned long startTimeInt = startTime.toLong();
    unsigned long endTimeInt = endTime.toLong();
    bool startSat = false;
    bool endSat = false;

    //get the index of the first TradeInfo with DateTime eq. or smaller then start and/or end of trade-window
    for(int i = 0; i < TradesHour.size(); ++i){
        DateTime targetTime = TradesHour[i].getDateTime();
        //saves DateTime as a long
        unsigned long targetTimeInt = targetTime.toLong();
        if(!startSat && startTimeInt >= targetTimeInt){
            startIndex = i;
            startSat = true;
        }
        if(!endSat && endTimeInt >= targetTimeInt){
            endIndex = i;
            endSat = true;
        }
        if(startSat && endSat){//both is sat, so no need to check the reset
            break;
        }
    }
    //not TradeInfo found
    if(!startSat || !endSat){
        std::cout << "Tids interval ikke rigtigt" << std::endl;
        return;
    }

    profit = (TradesHour[endIndex].getClose() - TradesHour[startIndex].getOpen()) * stockquant;
    if(profit >= 0){
        std::cout << "din profit er: " << profit << " kr" << std::endl;
    }
    else{
        std::cout << "dit tab er: " << profit << " kr" << std::endl;
    }






}
