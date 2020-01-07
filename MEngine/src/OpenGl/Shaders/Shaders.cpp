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
		//gl_Position = u_Model * u_Projection * vec4(position, 1);
		gl_Position = u_Projection * u_View * u_Model * vec4(position, 1);
		//gl_Position = vec4(position, 1);
		v_colors = colors;
	}
)";

const char * posColorPixelShader = R"(
	#version 330 core
	layout(location = 0) out vec4 color;

	in vec4 v_colors;

	uniform sampler2D u_Texture;

	void main()
	{
		// vec4 texColor = texture(u_Texture, v_texCoord);
		color = v_colors;
	}
)";
