#ifndef _STENCILSTATE_
#define _STENCILSTATE_

#include <cstdint>

namespace GL {
	
	class StencilState {
	public:
		
		enum Compare {
			ALWAYS   = 0,
			NEVER    = 1,
			LESS     = 2,
			LEQUAL   = 3,
			EQUAL    = 4,
			NOTEQUAL = 5,
			GEQUAL   = 6, 
			GREATER  = 7,
		};
		
		enum Action {
			KEEP      = 0,
			ZERO      = 1,
			REPLACE   = 2,
			INCR      = 3,
			INCR_WRAP = 4,
			DECR      = 5,
			DECR_WRAP = 6,
			INVERT    = 7,
		};
		
		enum Face {
			BOTH  = 0,
			FRONT = 1,
			BACK  = 2,
		};
		
		StencilState(
			Compare test = ALWAYS,
			Action stencilFail          = KEEP,
			Action stencilPassDepthFail = KEEP,
			Action stencilPassDepthPass = KEEP,
			std::uint8_t reference = 0xFF,
			std::uint8_t maskRead  = 0xFF,
			std::uint8_t maskWrite = 0xFF,
			Face face = BOTH
		);
		
		void enable() const;
		static void disable();
		
		bool operator==(const StencilState& obj) const;
		
	private:
		
		Face face;
		Compare test;
		Action stencilFail;
		Action stencilPassDepthFail;
		Action stencilPassDepthPass;
		std::uint8_t reference;
		std::uint8_t maskRead;
		std::uint8_t maskWrite;
		
	};
	
}

#endif
