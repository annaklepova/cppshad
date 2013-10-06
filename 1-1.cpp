#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const string weekDays[ 7 ] = { "Monday",
                             "Tuesday",
                             "Wednesday",
                             "Thursday",
                             "Friday",
                             "Saturday",
                             "Sunday" };

const int monthLengths[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//  1 ÿíâàðÿ 2000 ñóááîòà
string DayOfWeekByDate( int day, int month, int year )
{
    int delta;
    int yearDelta = 0;
    if ( 2000 <= year )
    {
        yearDelta = year - 2000;
    }
    else
    {
        return "too early";
    }
    delta = day - 1;
    for ( int monthCnt = 1; monthCnt < month; ++monthCnt )
    {
        delta += monthLengths[ monthCnt - 1 ];
    }
    delta += yearDelta * 365;
    if ( ( 58 < delta ) && ( ( day != 29 ) || ( delta != 59 ) ) )
    {
        delta++;
    }
    delta += yearDelta / 4;
    delta -= yearDelta / 100;
    delta += yearDelta / 400;
    return weekDays[ ( delta + 5 ) % 7 ];
}

bool IsBissextileYear( int year )
{
    return ( ( ( 0 == year % 4 ) && ( 0 != year % 100 ) ) ||
               ( 0 == year % 400 ) ) ?
               true : false;
}

int main()
{
    int day, month, year;
    cin >> day >> month >> year;
    cout << DayOfWeekByDate( day, month, year ) << endl;
    return 0;
}
