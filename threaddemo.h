#ifndef THREADDEMO_H
#define THREADDEMO_H
#include <QObject>
#include <QMutex>
class ThreadDemo : public QObject
{
    Q_OBJECT
public:
    ThreadDemo(QObject* parent = NULL);
    ~ThreadDemo();
signals:
    void valueChange();
    void Message(const QString& info);
public slots:
    void doWork1();
    void doWork2();
private:
    int m_iCount;
QMutex m_stopMutex;
};

#endif // THREADDEMO_H
