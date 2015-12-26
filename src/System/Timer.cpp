#include "Timer.hpp"

using namespace System;

Timer::Timer(double smooth)
{
	time = std::chrono::high_resolution_clock::now();
	mSmooth = smooth;
	mFPS = 0;
}

void Timer::setSmoothing(double smooth)
{
	mSmooth = smooth;
	if (mSmooth < 0) mSmooth = 0;
	if (mSmooth > 1) mSmooth = 1;
}

double Timer::elapsed() const
{
	return std::chrono::duration<double>(
		std::chrono::high_resolution_clock::now() - time
	).count();
}

double Timer::restart()
{
	std::chrono::high_resolution_clock::time_point last = time;
	double elapsed = std::chrono::duration<double>(
		(time = std::chrono::high_resolution_clock::now()) - last
	).count();
	mFPS = mFPS * mSmooth + ((elapsed > 0) ? (1.0 / elapsed) : 0.0) * (1.0 - mSmooth);
	return elapsed;
}

double Timer::fps() const
{
	return mFPS;
}