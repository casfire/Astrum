#ifndef _SCISSORSTATE_
#define _SCISSORSTATE_

#include <cstddef>

namespace GL {
	
	class ScissorState {
	public:
		
		ScissorState(
			std::size_t width,
			std::size_t height,
			std::size_t x = 0,
			std::size_t y = 0
		);
		
		void enable() const;
		static void disable();
		
		bool operator==(const ScissorState& obj) const;
		
	private:
		
		int x, y, width, height;
		
	};
	
}

#endif
