#include <math.h>
#include "worker.h"

void Worker::setStop(bool value)
{
    stop = value;
}

Worker::Worker(QObject *parent):QObject(parent)
{
    n = 0;
    result = 0;

}

void Worker::set_param(unsigned long n){
    this->n = n;
}


void Worker::process(){
    this->stop = false;
    this->result = 0;
    auto d = 1;
    if (n != 0)  d = n/100;
    else progress(100);

    for ( unsigned long i = 0; i<=n; i++){
        this->result += sin(i);
        if (i % d == 0)
            progress(i/d);

        if (stop)
            break;
    }

    finished();
}


double Worker::get_result() const{
    return this->result;
}


Worker::~Worker(){

}
