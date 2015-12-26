#ifndef _CULLSTATE_
#define _CULLSTATE_

namespace GL {
	
	class CullState {
	public:
		
		enum Face {
			CW  = 0,
			CCW = 1,
		};
		
		enum Cull {
			BOTH  = 0,
			FRONT = 1,
			BACK  = 2,
		};
		
		CullState(Face front, Cull which);
		
		void enable() const;
		static void disable();
		
		bool operator==(const CullState& obj) const;
		
	private:
		
		Face front;
		Cull which;
		
	};
	
}

#endif
