#include "holiday.h"

#include <QDate>

#include <kholidays/holidays.h>

Holiday::Holiday(const QString& location)
        : m_location(location)
{}

QString Holiday::todaysHolidays() const 
{
    QDate today = QDate::currentDate();
    KHolidays::HolidayRegion hr(m_location);
    KHolidays::Holiday::List holidays =  hr.holidays(today);
    return holidays[0].text();
}

QString Holiday::tomorrowsHolidays() const 
{
    QDate tomorrow = QDate::currentDate().addDays(1);
    KHolidays::HolidayRegion hr(m_location);
    KHolidays::Holiday::List holidays =  hr.holidays(tomorrow);
    if (holidays.size())
        return holidays[0].text();
    else
        return QString("No one");
}

    
