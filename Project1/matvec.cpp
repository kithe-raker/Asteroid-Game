// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
	if (window == NULL){
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//vector
	glm::vec3 vecA = glm::vec3(10.0f, 0.0f, 0.0f);
		printf("vecA x>%f y>%f z>%f\n", vecA.x, vecA.y, vecA.z);
	glm::vec3 vecB = glm::vec3(0.0f, 1.0f, 0.0f);
		printf("vecB x>%f y>%f z>%f\n", vecB.x, vecB.y, vecB.z);
	glm::vec3 vecC = glm::cross(vecA, vecB);
	printf("Cross product between vecA and vecB = (%f,%f,%f)\n", vecC.x,vecC.y,vecC.z);
	float result = glm::dot(vecA, vecB);
		printf("Dot product between vecA and vecB = %f\n", result);
	result = glm::length(vecA);
		printf("Length of vecA = %f\n", result);

	//matrix
	glm::mat3 matA = glm::mat3(1.0f);
		printf("Matrix A elements>\n");
		printf("%f %f %f\n", matA[0][0], matA[1][0], matA[2][0]);
		printf("%f %f %f\n", matA[0][1], matA[1][1], matA[2][1]);
		printf("%f %f %f\n", matA[0][2], matA[1][2], matA[2][2]);
	glm::mat4 matB = glm::mat4(1.0f);
	matB = glm::translate(matB, glm::vec3(10.0f, 20.0f,30.0f));
		printf("Matrix B elements>\n");
		printf("%f %f %f %f\n", matB[0][0], matB[1][0], matB[2][0], matB[3][0]);
		printf("%f %f %f %f\n", matB[0][1], matB[1][1], matB[2][1], matB[3][1]);
		printf("%f %f %f %f\n", matB[0][2], matB[1][2], matB[2][2], matB[3][2]);
		printf("%f %f %f %f\n", matB[0][3], matB[1][3], matB[2][3], matB[3][3]);
	glm::vec4 vecD(1.0f, 2.0f, 3.0f, 4.0f);
	glm::vec4 vecE = matB * vecD;
		printf("vecE = %f,%f,%f,%f\n", vecE.x, vecE.y, vecE.z, vecE.w);


	do{
		// Draw nothing, see you in tutorial 2 !
		


		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

