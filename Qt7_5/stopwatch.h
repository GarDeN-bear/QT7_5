#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    // Запустить секундомер
    void Start();
    // Остановить секундомер
    void Stop();
    // Очистить секундомер
    void Clear();
    // Количество кругов
    void Lap();
    // Установить время
    void setTime(int time);
    // Установить круг
    void setLap(int lap);
    // Получить текущее время
    int getCurrentTime();
    // Получить текущий круг
    int getCurrentLap();
    // Проверить, запущен ли секундомер
    bool isStart();

signals:
    void sig_Start();
    void sig_Stop();
    void sig_Clear();
    void sig_Lap();

private:
    bool isStart_; // флаг работы секундомера
    int currentTime_; // текущее время
    int currentLap_; // текущий круг
};

#endif // STOPWATCH_H
