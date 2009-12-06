#include "plasma_holiday.h"

#include <QPainter>
#include <QSize>
#include <QRect>
#include <QStringList>

#include <plasma/svg.h>
#include <plasma/theme.h>

#include "holiday.h"

K_EXPORT_PLASMA_APPLET(holiday, PlasmaHoliday)

PlasmaHoliday::PlasmaHoliday(QObject* parent, const QVariantList& args)
 : Plasma::Applet(parent, args)
{
    Holiday h("gr");
    m_holiday = h.todaysHolidays(); 
    setBackgroundHints(DefaultBackground);
    resize(50,100);
}

PlasmaHoliday::~PlasmaHoliday()
{}

void PlasmaHoliday::init()
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

