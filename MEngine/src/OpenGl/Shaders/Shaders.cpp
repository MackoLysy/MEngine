#include "Shaders.h"

const char * posColorVertexShader = R"(
	#version 330 core

	layout(location = 0) in vec3 position;
	layout(location = 1) in vec4 colors;

	uniform mat4 u_View;
	uniform mat4 u_Projection;
	uniform mat4 u_Model;

	out vec4 v_colors;

	void main()
	{
		gl_Position = u_Projection * u_View * u_Model * vec4(position, 1);
		v_colors = colors;
	}
)";

const char * posColorPixelShader = R"(
	#version 330 core
	layout(location = 0) out vec4 color;

	in vec4 v_colors;

	void main()
	{
		color = v_colors;
	}
)";


extern const char* posTexVertexShader = R"(
	#version 330 core

	layout(location = 0) in vec3 position;
	layout(location = 1) in vec2 texCoords;

	uniform mat4 u_View;
	uniform mat4 u_Projection;
	uniform mat4 u_Model;

	out vec2 v_texCoord;

	void main()
	{
		gl_Position = u_Projection * u_View * u_Model * vec4(position, 1);
		v_texCoord = texCoords;
	}
)";
extern const char* posTexPixelShader = R"(
	#version 330 core
	layout(location = 0) out vec4 color;

	in vec2 v_texCoord;

	uniform sampler2D u_Texture;

	void main()
	{
		vec4 texColor = texture(u_Texture, v_texCoord);
		color = texColor;
	}
)";