#pragma once

// #define NO_CAP_INTERPOLATION

class TimedInterpolation {
public:
    TimedInterpolation() {
        unsigned long beginTime = 0;
        unsigned long endTime = 1000;
        unsigned long duration = 1000;
    }

    inline void setDuration(const unsigned long ms) {
        duration = ms;
    }

    inline void begin(const unsigned long ms) {
        beginTime = millis();
        endTime = beginTime + ms;
        duration = endTime - beginTime;
    }

    inline void begin() {
        beginTime = millis();
        endTime = beginTime + duration;
    }
    
    inline float get() {
    #ifdef NO_CAP_INTERPOLATION
        return float((millis() - beginTime)) / float(duration);

    #else
        value = float((millis() - beginTime)) / float(duration);
        if (value > 1.0) {
            return 1.0;
        } else {
            return value;
        }
    #endif
    }

    inline long getElapsedTime() {
        return millis() - beginTime;
    }

    inline float getElapsedTimeSec() {
        return float(millis() - beginTime) * 0.001;
    }

private:
    unsigned long beginTime;
    unsigned long endTime;
    unsigned long duration;

#ifndef NO_CAP_INTERPOLATION
    float value;
#endif
};

