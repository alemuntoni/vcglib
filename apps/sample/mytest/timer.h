#ifndef TIMER_H
#define TIMER_H

#include <chrono>

struct timer {
	std::chrono::high_resolution_clock::time_point begin, end;
	void start() {begin = std::chrono::high_resolution_clock::now();}
	void stop() {end = std::chrono::high_resolution_clock::now();}
	double delay()
	{
		return (double)(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000;
	}
};

#endif // TIMER_H
