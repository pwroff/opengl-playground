#version 460 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 vPosition;
in vec3 vNormal;

uniform vec4 objectColor;
uniform vec4 lightColor;
uniform vec3 lightPosition;
uniform vec3 uEyePosition;
uniform vec4 uWarmColor;

vec3 lit(vec3 l, vec3 n, vec3 v) {
	vec3 r_l = reflect(-l, n);
	float s = clamp(100.0 * dot(r_l, v) - 95.0, 0.0, 1.0);
	vec3 highlightColor = vec3(1, 1, 1);
	return mix(uWarmColor.xyz, highlightColor, s);
}

void main()
{
	vec3 n = normalize(vNormal);
	vec3 v = normalize(uEyePosition.xyz - vPosition);
	FragColor = objectColor*0.1;
	vec3 l = normalize(lightPosition - vPosition);
	float NDL = clamp(dot(n, l), 0.0, 1.0);
	FragColor.rgb += NDL * lightColor.rgb * lit(l, n, v);

}

