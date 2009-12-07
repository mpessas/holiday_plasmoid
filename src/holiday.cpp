#include "holiday.h"

#include <QDate>


Holiday::Holiday(const QString& location)
        : m_hr(location)
{}

QString Holiday::todaysHolidays() const 
{
    QDate today = QDate::currentDate();
    KHolidays::Holiday::List holidays =  m_hr.holidays(today);
    if (holidays.size())
        return holidays[0].text();
    else
        return QString("None");
}

QString Holiday::tomorrowsHolidays() const 
{
    QDate tomorrow = QDate::currentDate().addDays(1);
    KHolidays::Holiday::List holidays =  m_hr.holidays(tomorrow);
    if (holidays.size())
        return holidays[0].text();
    else
        return QString("None");
}

    
