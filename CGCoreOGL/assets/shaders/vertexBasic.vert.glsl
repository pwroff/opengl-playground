#version 460 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;

out vec2 TexCoord;
out vec3 vPosition;
out vec3 vNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vec4 wpos = model * vec4(aPos, 1.0f);
	gl_Position = projection * view * wpos;
	vPosition = wpos.xyz;
	vNormal = (model * vec4(aNormal, 1.0f)).xyz;
	TexCoord = vec2(aTexCoord.x, 1.0 - aTexCoord.y);
}
