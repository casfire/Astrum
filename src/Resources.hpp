#ifndef _RESOURCES_
#define _RESOURCES_

#include "GL/GL.hpp"
#include "Render/Render.hpp"
#include "System/System.hpp"

struct Resources {
	
	// Basic resources
	Resource<Quad>          quad;
	Resource<AmbientRender> ambient;
	Resource<Texture>       white;
	
	// Textures
	Resource<Texture> font;
	Resource<Texture> gui;
	Resource<Texture> planets;
	Resource<Texture> thrust;
	Resource<Texture> ship;
	Resource<Texture> sat;
	Resource<Texture> space_back1;
	Resource<Texture> space_back2;
	Resource<Texture> space_dust1;
	Resource<Texture> space_dust2;
	Resource<Texture> space_dust3;
	Resource<Texture> space_dust4;
	Resource<Texture> space_dust5;
	
};

#endif
