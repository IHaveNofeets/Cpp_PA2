#include "TradeLoader.h"
#include <fstream>

TradeLoader::TradeLoader() {}
void TradeLoader::load(const std::string& filename){
    //load file
    std::ifstream file;
    file.open(filename);
    //read file
    if(file.is_open()){
        std::string headers;
        //jump over header
        std::getline(file, headers);
        //read and save each line
        std::string line;
        while(file.good()){
            std::getline(file, line);
            std::array<std::string, 6> lineData = split(line, ',');
            mData.push_back(lineData);
            if(file.eof()){
                break;
            }
        }
    }
}
std::vector<TradeInfo> TradeLoader::getTradeInfo(){
    std::vector<TradeInfo> out;
    //convert from string to the right data type
    for (std::array<std::string, 6> trade : mData) {
        TradeInfo newTrade{DateTime(trade[0]), std::stod(trade[1]), std::stod(trade[2]),
                           std::stod(trade[3]), std::stod(trade[4]), std::stod(trade[5])};
        out.push_back(newTrade);
    }
    return out;
}
std::array<std::string, 6> TradeLoader::split(const std::string& line, char delim){
    //have a vaible that is not const
    std::string line_remender = line;
    //output to save to
    std::array<std::string, 6> out;

    for (int i = 0; i < 6; ++i) {
        //finds the next time delim and gets from pos 0 to that pos and then removes the copyed part + 1 (for ',')
        int pos = line_remender.find(delim);
        if(pos == std::string::npos){pos = line_remender.size();} //end of line
        std::string part = line_remender.substr(0,pos);
        out[i] = part;
        line_remender.erase(0,pos+1);
    }
    return out;
}
