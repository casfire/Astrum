#include "AmbientRender.hpp"
#include "../GL/gles2.hpp"
#include "../glm/gtc/type_ptr.hpp"

using namespace GL;
using namespace Render;

AmbientRender::AmbientRender()
: program("assets/ambient")
{
	aPosition       = program.getAttribute("aPosition");
	aTexCoord       = program.getAttribute("aTexCoord");
	uTextureDiffuse = program.getUniform("uTextureDiffuse");
	uAmbientColor   = program.getUniform("uAmbientColor");
	uTextureRect    = program.getUniform("uTextureRect");
	uMatrix         = program.getUniform("uMatrix");
}

void AmbientRender::render(
	const Camera2D&  camera,
	const Mesh&      mesh,
	const Attribute& position,
	const Attribute& texcoord,
	const unsigned&  texture,
	const glm::mat3& matrix,
	const glm::vec4& color,
	const glm::vec4& rect
) const {
	
	glUseProgram(program.ID);
	
	glm::mat3 mat = camera.getMatrix() * matrix;
	
	glUniform1i(
		uTextureDiffuse,
		texture
	);
	
	glUniform4fv(
		uAmbientColor,
		1,
		glm::value_ptr(color)
	);
	
	glUniform4fv(
		uTextureRect,
		1,
		glm::value_ptr(rect)
	);
	
	glUniformMatrix3fv(
		uMatrix,
		1,
		GL_FALSE,
		glm::value_ptr(mat)
	);
	
	glBindBuffer(GL_ARRAY_BUFFER, position.buffer);
	glEnableVertexAttribArray(aPosition);
	glVertexAttribPointer(
		aPosition,
		position.size,
		GL_FLOAT,
		GL_FALSE,
		position.stride,
		position.pointer
	);
	
	glBindBuffer(GL_ARRAY_BUFFER, texcoord.buffer);
	glEnableVertexAttribArray(aTexCoord);
	glVertexAttribPointer(
		aTexCoord,
		texcoord.size,
		GL_FLOAT,
		GL_FALSE,
		texcoord.stride,
		texcoord.pointer
	);
	
	glDrawArrays(mesh.type, mesh.start, mesh.count);
	
}

void AmbientRender::render(
	const Camera2D&  camera,
	const Quad&      quad,
	const unsigned&  texture,
	const glm::mat3& matrix,
	const glm::vec4& color,
	const glm::vec4& rect
) const {
	render(
		camera,
		quad.mesh,
		quad.position,
		quad.texcoord,
		texture,
		matrix,
		color,
		rect
	);
}

void AmbientRender::render(
	const Camera2D&      camera,
	const AmbientObject& object
) const {
	render(
		camera,
		object.mesh,
		object.position,
		object.texcoord,
		object.texture,
		object.matrix,
		object.color,
		object.rect
	);
}
