# Lab1-Engineering-and-computer-graphics
learning to use openGL
1. create a window
**First**, we must deal with the dependencies **(libraries)** : we need the basics to display messages in the console:
```c++
#include <GL\glew.h>         
#include <glm/vec3.hpp>
#include <iostream>
#include <GL\freeglut.h>
```
**Second** we initialize **GLUT**, the first is a pointer to the argument line and the second is to the argument array.
```c++
int main(int argc, char** argv)
```
**Third** the **LUT. GLUT_DOUBLE** enables double buffering used color buffer for the final render target (i.e. the screen) plus the following functions that set the window parameters and give the window its title
```c++
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
```
```c++
glutInitWindowSize(1024, 768);
glutInitWindowPosition(100, 100);
glutCreateWindow("Lesson1");
  ```
  
**Fourth** **GLUT** is responsible for interacting with the window system and provides us with various callback options. Until now, we are using only one, the most important one, which generates 1 frame. **GLUT** regularly calls this function.
```c++
glutDisplayFunc(RenderSceneCB);
```
**Fifth**The **glClearColor** function specifies clear values for the color buffers
```c++
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
```
**Sixth** This function will cause all the GLUT functions that control functions to be repeated when necessary, that is, it is a smart loop, in other words, it is giving **GLUT** control over the program,
```c++
glutMainLoop();
```
**Seven** All we do in our render function is clear the frame buffer (using the old color set, try changing it). The second function asks **GLUT** to swap the background buffer and the frame buffer. The next call will render to the current framebuffer and the backgroundbuffer will be rendered.
```c++
glClear(GL_COLOR_BUFFER_BIT);
glutSwapBuffers();
```

# Creating a triangle
As indicated in lesson one and two, we proceed to make a triangle

**firt** start by drawing the triangle point and then the vertex points
```c++
  Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f)
```
```c++
glm::vec3 Vertices[3]{
	   glm::vec3(-1.0f, -1.0f, 0.0f),
	   glm::vec3(1.0f, -1.0f, 0.0f),
	   glm::vec3(0.0f, 1.0f, 0.0f)
	};
 ```
**second** Here we take the size of the data in bytes and the address of the array of vertices and the pattern that indicates the uses of data
```c++
glEnableVertexAttribArray(0);
```
**third** specifies the index of the vertex to be activated, or  can also specify which ones are deactivated
```c++
glEnableVertexAttribArray(0);
glDisableVertexAttribArray(0);
```
**four**Instead of calling a GL procedure to pass each individual vertex, normal, texture coordinate, edge flag, or color, you can prespecify separate arrays of vertices, normals, and colors and use them to construct a sequence of primitives.
When glDrawArrays is called, it uses count sequential elements from each enabled array to construct a sequence of geometric primitives, beginning with element first. mode specifies what kind of primitives are constructed and how the array elements construct those primitives.
Vertex attributes that are modified by glDrawArrays have an unspecified value after glDrawArrays returns. Attributes that aren't modified remain well defined.
```c++
glDrawArrays(GL_POINTS, 0, 1);
glDrawArrays(GL_TRIANGLES, 0, 3);
```


