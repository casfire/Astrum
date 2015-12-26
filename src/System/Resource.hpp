#ifndef _RESOURCE_
#define _RESOURCE_

namespace System {
	
	template <typename T>
	class Resource {
	public:
		
		Resource()
		: init(false)
		{}
		
		~Resource() {
			unload();
		}
		
		template <typename... Args>
		void load(const Args& ... args) {
			unload();
			new (&value) T(args...);
			init = true;
		}
		
		void unload() {
			if (!init) return;
			init = false;
			value.~T();
		}
		
		inline T& operator*() {
			if (!init) return *reinterpret_cast<T*>(0);
			return value;
		}
		
		inline const T& operator*() const {
			if (!init) return *reinterpret_cast<T*>(0);
			return value;
		}
		
		inline T* operator->() {
			return init ? &value : nullptr;
		}
		
		inline const T* operator->() const {
			return init ? &value : nullptr;
		}
		
		inline const T* ptr() const {
			return init ? &value : nullptr;
		}
		
		inline T* ptr() {
			return init ? &value : nullptr;
		}
		
		inline const T& get() const {
			return init ? value : *ptr();
		}
		
		inline T& get() {
			return init ? value : *ptr();
		}
		
	private:
		
		union { T value; };
		bool init;
		
	};
	
}

#endif
