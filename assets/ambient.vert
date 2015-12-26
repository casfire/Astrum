attribute vec2 aPosition;
attribute vec2 aTexCoord;

uniform mat3 uMatrix;

varying vec2 vTexCoord;

void main() {
	
	vTexCoord = aTexCoord;
	
	gl_Position = vec4(
		(uMatrix * vec3(aPosition, 1)).xy,
		0, 1
	);
	
}