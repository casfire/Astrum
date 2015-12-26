#include "BlendState.hpp"
#include "../gles2.hpp"
#include <cstddef>

using namespace GL;

static GLenum equation[] = {
	GL_FUNC_ADD,
	GL_FUNC_SUBTRACT,
	GL_FUNC_REVERSE_SUBTRACT,
};

static GLenum factor[] = {
	GL_ZERO,
	GL_ONE,
	GL_SRC_COLOR,
	GL_DST_COLOR,
	GL_CONSTANT_COLOR,
	GL_SRC_ALPHA,
	GL_DST_ALPHA,
	GL_CONSTANT_ALPHA,
	GL_ONE_MINUS_SRC_COLOR,
	GL_ONE_MINUS_DST_COLOR,
	GL_ONE_MINUS_CONSTANT_COLOR,
	GL_ONE_MINUS_SRC_ALPHA,
	GL_ONE_MINUS_DST_ALPHA,
	GL_ONE_MINUS_CONSTANT_ALPHA,
};

BlendState::BlendState(
	Factor srcRGB,
	Factor srcAlpha,
	Factor dstRGB,
	Factor dstAlpha,
	Equation equationRGB,
	Equation equationAlpha,
	std::uint8_t r,
	std::uint8_t g,
	std::uint8_t b,
	std::uint8_t a
)
: srcRGB(srcRGB)
, srcAlpha(srcAlpha)
, dstRGB(dstRGB)
, dstAlpha(dstAlpha)
, equationRGB(equationRGB)
, equationAlpha(equationAlpha)
, color(
	(static_cast<std::uint32_t>(r) << 0 ) |
	(static_cast<std::uint32_t>(g) << 8 ) |
	(static_cast<std::uint32_t>(b) << 16) |
	(static_cast<std::uint32_t>(a) << 24)
)
{}

BlendState::BlendState(
	Factor src,
	Factor dst,
	Equation equation,
	std::uint8_t r,
	std::uint8_t g,
	std::uint8_t b,
	std::uint8_t a
)
: BlendState(src, src, dst, dst, equation, equation, r, g, b, a)
{}

void BlendState::enable() const
{
	glEnable(GL_BLEND);
	glBlendColor(
		static_cast<float>((color >> 0 ) & 0xFF) / 255.f,
		static_cast<float>((color >> 8 ) & 0xFF) / 255.f,
		static_cast<float>((color >> 16) & 0xFF) / 255.f,
		static_cast<float>((color >> 24) & 0xFF) / 255.f
	);
	glBlendEquationSeparate(
		equation[static_cast<std::size_t>(equationRGB)],
		equation[static_cast<std::size_t>(equationAlpha)]
	);
	glBlendFuncSeparate(
		factor[static_cast<std::size_t>(srcRGB)],
		factor[static_cast<std::size_t>(dstRGB)],
		factor[static_cast<std::size_t>(srcAlpha)],
		factor[static_cast<std::size_t>(dstAlpha)]
	);
}

void BlendState::disable()
{
	glDisable(GL_BLEND);
}

bool BlendState::operator==(const BlendState& obj) const
{
	return
		srcRGB   == obj.srcRGB   &&
		srcAlpha == obj.srcAlpha &&
		dstRGB   == obj.dstRGB   &&
		dstAlpha == obj.dstAlpha &&
		equationRGB   == obj.equationRGB   &&
		equationAlpha == obj.equationAlpha &&
		color == obj.color;
}
