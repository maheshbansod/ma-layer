#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 ourColor;
layout (location = 2) in vec2 texPos;

out vec4 aColor;
out vec2 texPosition;

void main() {
	gl_Position = vec4(aPos.x, aPos.y,aPos.z , 1);
	aColor = vec4(ourColor, 1);
	texPosition =texPos;
}
