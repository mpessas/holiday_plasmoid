#include "plasma_holiday.h"

#include <QPainter>
#include <QSize>
#include <QRect>
#include <QStringList>
#include <QTimer>

#include <klocale.h>
#include <plasma/svg.h>
#include <plasma/theme.h>

#include "holiday.h"

K_EXPORT_PLASMA_APPLET(holiday, PlasmaHoliday)

PlasmaHoliday::PlasmaHoliday(QObject* parent, const QVariantList& args)
: Plasma::Applet(parent, args), m_holiday("")
{
    setBackgroundHints(DefaultBackground);
    resize(200,100);
}

PlasmaHoliday::~PlasmaHoliday()
{}

void PlasmaHoliday::init()
{
    updateMsg();
    // set the timer to midnight so as to update the text
    QDateTime now = QDateTime::currentDateTime();
    QDateTime midnight(QDate(now.date().addDays(1)), QTime(0, 0));
    QTimer::singleShot(now.secsTo(midnight) * 1000, this, SLOT(updateMsg()));
}

void PlasmaHoliday::updateMsg()
{
    KLocale* locale = KGlobal::locale();
    Holiday h(locale->country());
    m_holiday = "";
    m_holiday.append("Today:\t");
    m_holiday.append(h.todaysHolidays());
    m_holiday.append("\nTomorrow:\t");
    m_holiday.append(h.tomorrowsHolidays());
}

void PlasmaHoliday::paintInterface(QPainter* p,
                             const QStyleOptionGraphicsItem* option,
                             const QRect& contentsRect)
{
    p->setRenderHint(QPainter::SmoothPixmapTransform);
    p->setRenderHint(QPainter::Antialiasing);
 
    p->save();
    p->drawText(contentsRect,
                Qt::AlignVCenter | Qt::AlignHCenter,
                m_holiday);
    p->restore();
}

#include "plasma_holiday.moc"

