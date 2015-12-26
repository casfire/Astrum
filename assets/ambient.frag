precision mediump float;

uniform sampler2D uTextureDiffuse;
uniform vec4 uAmbientColor;
uniform vec4 uTextureRect;

varying vec2 vTexCoord;

void main() {
	
	vec2 texCoord = vec2(
		vTexCoord.x * (uTextureRect.z - uTextureRect.x) + uTextureRect.x,
		vTexCoord.y * (uTextureRect.a - uTextureRect.y) + uTextureRect.y
	);
	
	gl_FragColor = texture2D(uTextureDiffuse, texCoord) * uAmbientColor;
	
}
