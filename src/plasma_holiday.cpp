#include "plasma_holiday.h"

#include <QPainter>
#include <QSize>
#include <QRect>
#include <QStringList>

#include <klocale.h>
#include <plasma/svg.h>
#include <plasma/theme.h>

#include "holiday.h"

K_EXPORT_PLASMA_APPLET(holiday, PlasmaHoliday)

PlasmaHoliday::PlasmaHoliday(QObject* parent, const QVariantList& args)
: Plasma::Applet(parent, args), m_holiday("Today:\t")
{
    KLocale* locale = KGlobal::locale();
    Holiday h(locale->country());
    m_holiday.append(h.todaysHolidays());
    m_holiday.append("\nTomorrow:\t");
    m_holiday.append(h.tomorrowsHolidays());
    setBackgroundHints(DefaultBackground);
    resize(200,100);
}

PlasmaHoliday::~PlasmaHoliday()
{}

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

