#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    isStart_ = false;
    currentTime_ = 0;
    currentLap_ = 1;
    qTimer = new QTimer(this);
}

void Stopwatch::Start()
{
    isStart_ = true;
    qTimer->start(100);
    emit sig_Start();
}

void Stopwatch::Stop()
{
    isStart_ = false;
    currentTime_ = 0;
    qTimer->stop();
    emit sig_Stop();
}

void Stopwatch::Clear()
{
    currentTime_ = 0;
    currentLap_ = 1;
    emit sig_Clear();
}

void Stopwatch::Lap()
{
    emit sig_Lap();
}

void Stopwatch::setTime(float time)
{
    currentTime_ = time;
}

void Stopwatch::setLap(int lap)
{
    currentLap_ = lap;
}

float Stopwatch::getCurrentTime()
{
    return currentTime_;
}

int Stopwatch::getCurrentLap()
{
    return currentLap_;
}

bool Stopwatch::isStart()
{
    return isStart_;
}

QTimer *Stopwatch::getQTimer()
{
    return qTimer;
}

