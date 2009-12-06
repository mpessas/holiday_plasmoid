#include "holiday.h"

#include <QDate>

#include <kholidays/holidays.h>

Holiday::Holiday(const QString& location)
        : m_location(location)
{}

QString Holiday::todaysHolidays() const 
{
    QDate today = QDate::currentDate();
    // kDebug() << "Get holidays for " << today;
    KHolidays::HolidayRegion hr(m_location);
    KHolidays::Holiday::List holidays =  hr.holidays(today);
    return holidays[0].text();
}

    
