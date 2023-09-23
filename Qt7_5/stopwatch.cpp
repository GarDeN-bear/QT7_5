#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    isStart_ = false;
    currentTime_ = 0;
    currentLap_ = 1;
}

void Stopwatch::Start()
{
    isStart_ = true;
    emit sig_Start();
}

void Stopwatch::Stop()
{
    isStart_ = false;
    currentTime_ = 0;
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

void Stopwatch::setTime(int time)
{
    currentTime_ = time;
}

void Stopwatch::setLap(int lap)
{
    currentLap_ = lap;
}

int Stopwatch::getCurrentTime()
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

