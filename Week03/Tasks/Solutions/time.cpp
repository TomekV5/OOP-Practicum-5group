#include <iostream>
#include <format>
#include <print>

const int MAX_HOURS = 23;
const int MIN_TIME_ENTITY = 0;
const int MAX_MINUTES = 59;
const int MAX_SECONDS = 59;
const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_MINUTE = 60;
const int TOTAL_SECONDS_IN_DAY = 24 * SECONDS_IN_HOUR;

using std::cin;
using std::cout;

class Time
{
private:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s)
    {
        setTime(h, m, s);
    }

    void setTime(int h, int m, int s)
    {
        if (h >= MIN_TIME_ENTITY && h <= MAX_HOURS && m >= MIN_TIME_ENTITY && m <= MAX_MINUTES && s >= MIN_TIME_ENTITY && s <= MAX_SECONDS)
        {

            hours = h;
            minutes = m;
            seconds = s;
        }
    }

    int toSeconds() const
    {
        return seconds + minutes * SECONDS_IN_MINUTE + hours * SECONDS_IN_HOUR;
    }

    Time secondsToTime(int totalSeconds) const
    {
        int hours = (totalSeconds / SECONDS_IN_HOUR) % 24;
        int minutes = (totalSeconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
        int seconds = (totalSeconds % SECONDS_IN_HOUR) % SECONDS_IN_MINUTE;

        Time t = {hours, minutes, seconds};
        return t;
    }

    Time timeTillMidnight() const
    {
        return secondsToTime(TOTAL_SECONDS_IN_DAY - toSeconds());
    }

    void addOneSecond() const
    {
        seconds++;
        if (seconds > MAX_SECONDS)
        {
            seconds = 0;
            minutes++;
        }
        if (minutes > MAX_MINUTES)
        {
            minutes = 0;
            hours++;
        }
        if (hours > MAX_HOURS)
        {
            hours = 0;
        }
    }

    bool isDinnerTime() const
    {

        Time start = {20, 30, 00};
        Time end = {22, 00, 00};

        return (toSeconds() >= start.toSeconds() && toSeconds() <= end.toSeconds());
    }

    bool isPartyTime() const
    {
        Time start = {23, 00, 00};
        Time end = {06, 00, 00};

        return (toSeconds() >= start.toSeconds() || toSeconds() <= end.toSeconds());
    }

    Time diff(const Time &other) const
    {
        return secondsToTime(abs(toSeconds() - other.toSeconds()));
    }

    bool isBefore(const Time &other) const
    {
        return toSeconds() < other.toSeconds();
    }

    bool isAfter(const Time &other) const
    {
        return toSeconds() > other.toSeconds();
    }

    void printTime() const
    {
        std::println("{:02}:{:02}:{:02}", hours, minutes, seconds);
    }
};

void sortTimes(Time *times, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (times[j].isAfter(times[j + 1]))
            {
                std::swap(times[j], times[j + 1]);
            }
        }
    }
}
