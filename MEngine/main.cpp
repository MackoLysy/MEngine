#include "src/OpenGl/VertexBuffer.h"
#include "src/OpenGl/IndexBuffer.h"
#include "src/OpenGl/VertexArray.h"
#include "src/Shader.h"
#include "src/Renderer.h"
#include "src/Texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw.h"
#include "imGui/imgui_impl_opengl3.h"
#include <string>
#include <fstream>
#include <sstream>

int main(void)
{
	{
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}
		/* Make the window's context current */
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);
		const GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cout << "GLEW Error: " << glewGetErrorString(err) << std::endl;
			exit(1);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		const char* glsl_version = "#version 130";
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);


		float data[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, //0
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,	//1
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,//2
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f//3
		};

		unsigned int indecies[]
		{
			0, 1, 2,
			2, 3, 0
		};
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		VertexArray va;
		VertexBuffer vb(data, sizeof(float) * 20);
		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);
		//va.AddBuffer(vb, layout);

		Shader shader("res/shader/Basic.Shader");

		glm::mat4 view = glm::lookAt(
			glm::vec3(0.0f, 0.0f, 10.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
		);

		glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 100.0f);
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 mvp = proj * view * glm::translate(model, glm::vec3(0.0, 0.0, 0.0));
		IndexBuffer ib(indecies, 6);
		Texture textrue("res/images.png");
		textrue.Bind(3);
		shader.Bind();
		shader.setUniform1i("u_Texture", 3);
		shader.setUniforMat4f("u_MVP", mvp);
		float r = 0.05f;
		float increment = 0.005f;
		float f1 = 0, f2 = 0, f3 = 0;
		float rotate = 0;
		Renderer rednerer;

		while (!glfwWindowShouldClose(window))
		{
			rednerer.Clear();
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			shader.setUniform4f("u_Color", r, 0.7f, 0.7f, 1.0f);
			{
				ImGui::Begin("Hello, world!");
				ImGui::Text("Super Text!");

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				ImGui::SliderFloat("f1", &f1, 0.0, 10.0);
				ImGui::SliderFloat("f2", &f2, 0.0, 10.0);
				ImGui::SliderFloat("f3", &f3, 0.0, 10.0);
				ImGui::SliderFloat("Rotate", &rotate, 0.0, 360.0);
				ImGui::End();
			}
			auto value = glm::translate(model, glm::vec3(f1, f2, f3)) * glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
			glm::mat4 mvp = proj * view * value;
			shader.setUniforMat4f("u_MVP", mvp);
			rednerer.Draw(va, ib, shader);

			if (r > 1.0f)
			{
				increment = -0.005f;
			}
			if (r < 0.0f)
			{
				increment = 0.005f;
			}
			r = r + increment;
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}