#ifndef AIRLINES_H
#define AIRLINES_H
#include <iostream>

using std::string;
using std::ofstream;

typedef struct time
    {
        int month;
        int day;
        int hour;
        int minute;
    }Time;
class airlines
{
public:
    airlines(string from, string to, string id ,int price ,Time leave, Time arrive);
    airlines();
    int storeToMemory(string des); // destination;
    void setPrice(int newprice);
    string getFromCity();
    string getToCity();
    string getId();
    int getPrice();
    Time getLeaveTime();
    Time getArriveTime();
    string getLeaveTimeFormat();
    string getArriveTimeFormat();


private:
    string _from;
    string _to;
    string _id;
    int _price;
    Time _leave;
    Time _arrive;

};

void readAirlines(string, airlines*,int);
#endif // AIRLINES_H
