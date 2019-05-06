#include "airlines.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using std::endl;
using std::string;
using std::ofstream;
using std::fstream;

airlines::airlines()
{

}
airlines::airlines(std::string from, std::string to, std::string id, int price, Time leave, Time arrive)
{
    _from = from;
    _to = to;
    _id = id;
    _price = price;
    _leave = leave;
    _arrive = arrive;
}

int airlines::storeToMemory(string des)
{

    ofstream dest(des);
    if(!dest.is_open())
        return 1;
    else
    {
        dest << _from << endl;
        dest << _to << endl;
        dest << _id << endl;
        dest << _price << endl;
        dest << _leave.day << " " << _leave.hour << " " << _leave.minute << endl;
        dest << _arrive.day << " " << _arrive.hour << " " << _arrive.minute << endl;
    }
    dest.close();
    return 0;
}

void airlines::setPrice(int newprice)
{
    _price = newprice;
}

string airlines::getFromCity()
{
    return _from;
}

string airlines::getToCity()
{
    return _to;
}

string airlines::getId()
{
    return _id;
}

int airlines::getPrice()
{
    return _price;
}

Time airlines::getLeaveTime()
{
    return _leave;
}

Time airlines::getArriveTime()
{
    return _arrive;
}

string airlines::getArriveTimeFormat()
{
    char tmp[6];
    sprintf(tmp,"%02d:%02d\n",_arrive.hour,_arrive.minute);
    return string(tmp);
}

string airlines::getLeaveTimeFormat()
{
    char tmp[6];
    sprintf(tmp,"%02d:%02d\n",_leave.hour,_leave.minute);
    return string(tmp);
}

void readAirlines(string resoure, airlines* lis,int count)
{
    int number = 0;
    fstream inStream(resoure);
    if (!inStream.is_open())
        printf("Not found");
    else
    {
        while((!inStream.eof()) && number<count)
        {
            string from,to,id;
            int price;
            Time start, end;
            inStream >> from;
            inStream >> to;
            inStream >> id;
            inStream >> price;
            inStream >> start.day;
            inStream >> start.hour;
            inStream >> start.minute;
            inStream >> end.day;
            inStream >> end.hour;
            inStream >> end.minute;
            lis[number] = airlines(from,to,id,price,start,end);

            number++;
        }

    }
}
