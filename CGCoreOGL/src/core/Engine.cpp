#include "core/Engine.h"
#include <iostream>
#include "core/Input.h"


#pragma comment(lib, "glfw3.lib")

void printGLVersion()
{
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
		glGetString(GL_SHADING_LANGUAGE_VERSION));
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


Engine::Engine(Vec2<uint> winsize)
	:windowSize(winsize)
{
	if (Init())
	{
		printGLVersion();
	}
	else
	{
		window = NULL;
	}
}

Engine::~Engine()
{
	Cleanup();
}

void Engine::Run(std::function<void(float)> rendFunc)
{
	if (window == NULL)
		return;
	Input input(window);
	float deltaTime;
	float lastFrame = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		input.Update();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		rendFunc(deltaTime);
		Input::MouseMoved = false;
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	}
}

bool Engine::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(windowSize.x, windowSize.y, "EngineOGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window\n";
		return false;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD\n";
		return false;
	}
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, windowSize.x, windowSize.y);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return true;
}

void Engine::Cleanup()
{
	glfwTerminate();
}
