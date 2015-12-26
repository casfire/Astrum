#ifndef _DEPTHSTATE_
#define _DEPTHSTATE_

namespace GL {
	
	class DepthState {
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
		
		DepthState(
			Compare test = LESS,
			bool write = true
		);
		
		void enable() const;
		static void disable();
		
		bool operator==(const DepthState& obj) const;
		
	private:
		
		Compare test;
		bool write;
		
	};
	
}

#endif
