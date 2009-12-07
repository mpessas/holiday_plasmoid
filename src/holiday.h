#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <QString>
#include <QStringList>

class Holiday
{
  public:
    Holiday(const QString& location);
    QString todaysHolidays() const;
    QString tomorrowsHolidays() const;

  private:
    QString m_location;
};


#endif
