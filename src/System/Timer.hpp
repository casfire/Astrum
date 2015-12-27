#ifndef _TIMER_
#define _TIMER_

#include <chrono>
#include <string>

namespace System {
	
	class Timer {
	public:
		
		Timer(double smooth = 0.9);
		
		void setSmoothing(double smooth);
		
		double elapsed() const;
		double restart();
		double fps() const;
		std::string fpsString(int precision = 2) const;
		
	private:
		
		std::chrono::high_resolution_clock::time_point time;
		double mFPS, mSmooth;
		
	};
	
}

#endif
