#ifndef _CLEARSTATE_
#define _CLEARSTATE_

#include <cstdint>

namespace GL {
	
	class ClearState {
	public:
		
		ClearState(
			float r = 0.f,
			float g = 0.f,
			float b = 0.f,
			float a = 0.f,
			float depth = 1.f,
			std::uint8_t stencil = 0xFF
		);
		
		void enable() const;
		
	private:
		
		float r, g, b, a;
		float depth;
		std::uint8_t stencil;
		
	};
	
}

#endif
