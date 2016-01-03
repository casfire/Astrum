#include "TextField.hpp"

using namespace gui;

struct Glyph {
	std::uint16_t x, y, w, h;
	std::uint16_t xOff, yOff;
	std::uint16_t advance;
};

static const float GlyphBase = 45;
static const float GlyphTextureW = 512;
static const float GlyphTextureH = 512;

static Glyph glyphs[96] = {
	{8, 53, 0, 0, 0, 45, 18},
	{16, 8, 9, 45, 18, 0, 42},
	{33, 8, 27, 18, 0, 0, 42},
	{68, 8, 45, 45, 0, 0, 60},
	{121, 8, 45, 45, 0, 0, 60},
	{174, 8, 36, 45, 0, 0, 51},
	{218, 8, 45, 45, 0, 0, 60},
	{271, 8, 9, 18, 0, 0, 24},
	{288, 8, 18, 45, 0, 0, 33},
	{314, 8, 18, 45, 0, 0, 33},
	{340, 8, 27, 27, 0, 0, 42},
	{375, 8, 45, 45, 0, 0, 60},
	{428, 44, 9, 18, 0, 36, 24},
	{445, 26, 45, 9, 0, 18, 60},
	{8, 106, 9, 9, 0, 36, 24},
	{25, 70, 18, 45, 0, 0, 33},
	{51, 70, 45, 45, 0, 0, 60},
	{104, 70, 18, 45, 0, 0, 33},
	{130, 70, 45, 45, 0, 0, 60},
	{183, 70, 45, 45, 0, 0, 60},
	{236, 70, 45, 45, 0, 0, 60},
	{289, 70, 45, 45, 0, 0, 60},
	{342, 70, 45, 45, 0, 0, 60},
	{395, 70, 45, 45, 0, 0, 60},
	{448, 70, 45, 45, 0, 0, 60},
	{8, 123, 45, 45, 0, 0, 60},
	{61, 123, 9, 45, 0, 0, 24},
	{78, 123, 9, 54, 0, 0, 24},
	{95, 132, 27, 27, 0, 9, 42},
	{130, 132, 45, 27, 0, 9, 60},
	{183, 132, 27, 27, 0, 9, 42},
	{218, 123, 45, 45, 0, 0, 60},
	{271, 123, 45, 45, 0, 0, 60},
	{324, 123, 45, 45, 0, 0, 60},
	{377, 123, 45, 45, 0, 0, 60},
	{430, 123, 45, 45, 0, 0, 60},
	{8, 185, 45, 45, 0, 0, 60},
	{61, 185, 45, 45, 0, 0, 60},
	{114, 185, 45, 45, 0, 0, 60},
	{167, 185, 45, 45, 0, 0, 60},
	{220, 185, 45, 45, 0, 0, 60},
	{273, 185, 9, 45, 0, 0, 24},
	{290, 185, 36, 45, 0, 0, 51},
	{334, 185, 45, 45, 0, 0, 60},
	{387, 185, 45, 45, 0, 0, 60},
	{440, 185, 63, 45, 0, 0, 78},
	{8, 238, 45, 45, 0, 0, 60},
	{61, 238, 45, 45, 0, 0, 60},
	{114, 238, 45, 45, 0, 0, 60},
	{167, 238, 45, 45, 0, 0, 60},
	{220, 238, 45, 45, 0, 0, 60},
	{273, 238, 45, 45, 0, 0, 60},
	{326, 238, 45, 45, 0, 0, 60},
	{379, 238, 45, 45, 0, 0, 60},
	{432, 238, 45, 45, 0, 0, 60},
	{8, 291, 63, 45, 0, 0, 78},
	{79, 291, 45, 45, 0, 0, 60},
	{132, 291, 45, 45, 0, 0, 60},
	{185, 291, 45, 45, 0, 0, 60},
	{238, 291, 18, 45, 0, 0, 33},
	{264, 291, 18, 45, 0, 0, 33},
	{290, 291, 18, 45, 0, 0, 33},
	{316, 291, 27, 18, 0, 0, 42},
	{351, 327, 45, 9, 0, 36, 60},
	{404, 291, 9, 18, 0, 0, 24},
	{421, 291, 45, 45, 0, 0, 60},
	{8, 344, 45, 45, 0, 0, 60},
	{61, 344, 45, 45, 0, 0, 60},
	{114, 344, 45, 45, 0, 0, 60},
	{167, 344, 45, 45, 0, 0, 60},
	{220, 344, 45, 45, 0, 0, 60},
	{273, 344, 45, 45, 0, 0, 60},
	{326, 344, 45, 45, 0, 0, 60},
	{379, 344, 9, 45, 0, 0, 24},
	{396, 344, 36, 45, 0, 0, 51},
	{440, 344, 45, 45, 0, 0, 60},
	{8, 397, 45, 45, 0, 0, 60},
	{61, 397, 63, 45, 0, 0, 78},
	{132, 397, 45, 45, 0, 0, 60},
	{185, 397, 45, 45, 0, 0, 60},
	{238, 397, 45, 45, 0, 0, 60},
	{291, 397, 45, 54, 0, 0, 60},
	{344, 397, 45, 45, 0, 0, 60},
	{397, 397, 45, 45, 0, 0, 60},
	{450, 397, 45, 45, 0, 0, 60},
	{8, 459, 45, 45, 0, 0, 60},
	{61, 459, 45, 45, 0, 0, 60},
	{114, 459, 63, 45, 0, 0, 78},
	{185, 459, 45, 45, 0, 0, 60},
	{238, 459, 45, 45, 0, 0, 60},
	{291, 459, 45, 45, 0, 0, 60},
	{344, 459, 23, 45, 5, 0, 42},
	{375, 459, 9, 45, 0, 0, 24},
	{392, 459, 23, 45, 0, 0, 42},
	{423, 468, 45, 18, 0, 9, 60},
	{423, 468, 45, 18, 0, 9, 60},
};

TextField::TextField(
	const std::string& text,
	const glm::vec4& color,
	Align alignX,
	Align alignY
)
: color(color)
, alignX(alignX)
, alignY(alignY)
{
	setText(text);
}

void TextField::setText(const std::string& text)
{
	this->text = text;
	this->width = 0;
	for (char c : text) {
		std::size_t i = (c < 32) ? ('?' - 32) : (c - 32);
		this->width += glyphs[i].advance;
	}
}

void TextField::setTextColor(const glm::vec4& color)
{
	this->color = color;
}

void TextField::setTextAlign(Align x, Align y)
{
	this->alignX = x;
	this->alignY = y;
}

void TextField::setTextAlignX(Align x)
{
	this->alignX = x;
}

void TextField::setTextAlignY(Align y)
{
	this->alignY = y;
}

const std::string& TextField::getText() const
{
	return text;
}

glm::vec4 TextField::getTextColor() const
{
	return color;
}

TextField::Align TextField::getTextAlignX() const
{
	return alignX;
}

TextField::Align TextField::getTextAlignY() const
{
	return alignY;
}

void TextField::render(
	const Camera2D&      camera,
	const AmbientRender& ambient,
	const Quad&          quad,
	const unsigned&      font
) const {
	
	const float width  = this->width;
	const float height = GlyphBase;
	
	Transform2D letter(*this);
	glm::vec2 pos   = glm::vec2(0);
	glm::vec2 scale = getSize() / glm::vec2(width, height);
	if (scale.x > scale.y) {
		scale.x = scale.y;
		pos.x = (getSize().x - width * scale.x) * static_cast<int>(alignX) / 2.f;
	} else {
		scale.y = scale.x;
		pos.y = (getSize().y - height * scale.y) * static_cast<int>(alignY) / 2.f;
	}
	
	for (char c : text) {
		
		const Glyph& g = glyphs[(c < 32) ? ('?' - 32) : (c - 32)];
		
		letter.setSize(glm::vec2(g.w, g.h) * scale);
		letter.setOrigin(getOrigin() - pos - glm::vec2(g.xOff, g.yOff) * scale);
		pos.x += g.advance * scale.x;
		
		ambient.render(
			camera,
			quad,
			font,
			letter,
			color,
			glm::vec4(
				g.x / GlyphTextureW,
				g.y / GlyphTextureH,
				(g.x + g.w) / GlyphTextureW,
				(g.y + g.h) / GlyphTextureH
			)
		);
		
	}
	
}
