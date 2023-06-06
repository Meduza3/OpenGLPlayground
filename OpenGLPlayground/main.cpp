#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {

	//GLFW Initialization
	glfwInit();

	//Info about the 4.3 OpenGL Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Non fullscreen 800x800 window
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Playgroud", NULL, NULL);

	//Error checking
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Make the window the current context
	glfwMakeContextCurrent(window);

	//Load GLAD
	gladLoadGL();

	//Specify the viewport
	glViewport(0, 0, 800, 800);

	//Specify the color of the background and assign a new color to it.
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	//Main loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}