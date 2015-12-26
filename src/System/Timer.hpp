#ifndef _TIMER_
#define _TIMER_

#include <chrono>

namespace System {
	
	class Timer {
	public:
		
		Timer(double smooth = 0.9);
		
		void setSmoothing(double smooth);
		
		double elapsed() const;
		double restart();
		double fps() const;
		
	private:
		
		std::chrono::high_resolution_clock::time_point time;
		double mFPS, mSmooth;
		
	};
	
}

#endif
