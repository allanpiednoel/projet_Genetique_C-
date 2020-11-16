#include "myrandom.h"
#include <QDateTime>

MyRandom::MyRandom(int seed)
{
    if(seed==-1)
        seed=QTime::currentTime().msec();
    qsrand(seed);
}

int MyRandom::get(int max)
{
    return qrand()%max;
}

double MyRandom::getFloat()
{
    return (qrand()%1001)/1000.0;
}
