#include <GL\glew.h>         
#include <glm/vec3.hpp>
#include <iostream>
#include <GL\freeglut.h>

GLuint VBO;

void RenderSceneCB() {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glDrawArrays(GL_POINTS, 0, 1);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lesson1");
	glutDisplayFunc(RenderSceneCB);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	/*glm::vec3 Vertices[1];
  Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);*/
	glm::vec3 Vertices[3]{
	   glm::vec3(-1.0f, -1.0f, 0.0f),
	   glm::vec3(1.0f, -1.0f, 0.0f),
	   glm::vec3(0.0f, 1.0f, 0.0f)
	};
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glutDisplayFunc(RenderSceneCB);
	glutMainLoop();
}

