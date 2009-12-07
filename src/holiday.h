#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <QString>
#include <QStringList>

#include <kholidays/holidays.h>

class Holiday
{
  public:
    Holiday(const QString& location);
    QString todaysHolidays() const;
    QString tomorrowsHolidays() const;

  private:
    KHolidays::HolidayRegion m_hr;
};


#endif
