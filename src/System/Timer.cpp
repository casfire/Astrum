#include "Timer.hpp"
#include <sstream>
#include <iomanip>

using namespace System;

Timer::Timer(double smooth)
{
	time = std::chrono::high_resolution_clock::now();
	mSmooth = smooth;
	mFPS = 0;
	mCount = 1;
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
	if (elapsed > 0) {
		mFPS = mFPS * mSmooth + (mCount / elapsed) * (1.0 - mSmooth);
		mCount = 1.0;
	} else {
		mCount++;
	}
	return elapsed;
}

double Timer::fps() const
{
	return mFPS;
}

std::string Timer::fpsString(int precision) const
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(precision) << mFPS;
	return ss.str();
}
