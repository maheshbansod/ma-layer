#version 330 core

out vec4 FragColor;
in vec4 aColor;
in vec2 texPosition;

uniform sampler2D texture1;

void main() {
	vec4 texColor = texture(texture1, texPosition);//*aColor;
	if(texColor.a < 0.1)
        discard;
	FragColor = texColor;
}
