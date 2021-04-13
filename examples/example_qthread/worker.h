#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT

    bool stop;          // при true поток останавливается
    unsigned long n;
    double result;

public:
    explicit Worker(QObject * parent = nullptr);

    void set_param(unsigned long n);

    // метод выполняющий основную работу
    void process();

    double get_result() const;

    ~Worker();

    void setStop(bool value);

signals:
    // сигнал, который будет вызыван в методе process
    // этот синал, даст знать потоку, который работает с данным объектом,
    // что вычисления завершены, поток можно остановить
    void finished();

    void progress(unsigned i);
};

#endif // WORKER_H
