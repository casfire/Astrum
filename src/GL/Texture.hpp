#ifndef _TEXTURE_
#define _TEXTURE_

#include <string>
#include <cstddef>

namespace GL {
	
	class Texture {
	public:
		
		enum Filter {
			NEAREST   = 0,
			BILINEAR  = 1,
			TRILINEAR = 2,
		};
		
		enum Edge {
			REPEAT = 0,
			MIRROR = 1,
			CLAMP  = 2,
		};
		
		Texture(
			const std::string& file,
			Filter filter = NEAREST,
			Edge edge = REPEAT
		);
		
		Texture(
			std::size_t width,
			std::size_t height,
			std::size_t channels,
			Filter filter = NEAREST,
			Edge edge = REPEAT
		);
		
		~Texture();
		
		void bind(unsigned unit) const;
		static unsigned MaxUnits();
		
		const unsigned int ID;
		const std::size_t width;
		const std::size_t height;
		const std::size_t channels;
		
	private:
		
		Texture(const Texture&) = delete;
		Texture& operator=(const Texture&) = delete;
		
	};
	
}

#endif
