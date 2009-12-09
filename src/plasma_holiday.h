#ifndef PLASMA_HOLIDAY_H
#define PLASMA_HOLIDAY_H

#include <QString>
#include <QTimer>

#include <Plasma/Applet>
#include <Plasma/Svg>

class QRect;

class PlasmaHoliday : public Plasma::Applet
{
    Q_OBJECT
  public:
    PlasmaHoliday(QObject* parent, const QVariantList& args);
    ~PlasmaHoliday();
    void paintInterface(QPainter* painter,
                        const QStyleOptionGraphicsItem* option,
                        const QRect& contentsRect);
    void init();

  private slots:
    void updateMsg();
    
  private:
    void setMidnightTimer();
    
    QString m_holiday;
    QTimer midnightTimer;
    bool firstTime;
};

#endif
