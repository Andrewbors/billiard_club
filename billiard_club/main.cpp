#include <iostream>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
//printf( "%d-%02d-%02d %02d:%02d:%02d", finish.wYear, finish.wMonth, finish.wDay, finish.wHour, finish.wMinute, finish.wSecond);
using namespace std;

int main()
{
//price
    int price;
    cout << "Enter the price for 1 table(per hour) in UAH: ";
    cin >> price;

//starttime
    bool tableOn;
    int timeSecOn;
    cout << "\nDo you want to ON the table?(press '1' if YES, '0' if NO) ";
    cin >> tableOn;
    if(tableOn == true)
    {
        cout << "\nTime of the start of playing: ";
        SYSTEMTIME start; GetLocalTime(&start);
        printf("%02d:%02d:%02d", start.wHour, start.wMinute, start.wSecond); cout << "\n";
        timeSecOn = (start.wHour*3600 + start.wMinute*60 + start.wSecond);
    }

//finishtime
    int timeSecOff;
    cout << "\nDo you want to OFF the table?(press '0' if YES, '1' if NO) ";
    cin >> tableOn;
    if(tableOn == false)
    {
        cout << "\nTime of the finish of playing: ";
        SYSTEMTIME finish; GetLocalTime(&finish);
        printf("%02d:%02d:%02d", finish.wHour, finish.wMinute, finish.wSecond); cout << "\n";
        timeSecOff = (finish.wHour*3600 + finish.wMinute*60 + finish.wSecond);
    }

//totalprice
    double totalPrice;
    int h, m, s;
    int totalTimeSec = timeSecOff - timeSecOn;
    double timeForPrice = totalTimeSec/3600;

    totalPrice = price*timeForPrice;
    cout << timeForPrice;
    h = totalTimeSec/3600;   m = (totalTimeSec - h*3600)/60;   s = totalTimeSec - h*3600 - m*60;

    cout.precision(2);
    cout << "\n\nThe table was used for " << h << " h, " << m << " m, " << s << " s, it costs " << fixed << totalPrice << " UAH";

    return 0;
}
