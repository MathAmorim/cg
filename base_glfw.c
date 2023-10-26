#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

/** Exemplo modificado de https://www.glfw.org/documentation.html
*/

int render(){
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-0.5,-0.5);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(0.5,-0.5);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0,0.5);
	glEnd(); 
}

void eventos_teclado(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	glfwDestroyWindow(window);
        exit(0);
}

int main(void)
{
    // Inicializa a GLFW
    if (!glfwInit())
        return -1;

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	 
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    // Cria uma janela no modo sem ser tela cheia
    GLFWwindow* window = glfwCreateWindow(500, 500, "Hello World", NULL, NULL);

    // Cria uma janela no modo em tela cheia
    //GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Hello World", monitor, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Cria o contexto do OpenGL para a janela atual
    glfwMakeContextCurrent(window);

    // Ajusta callback para eventos de teclado    
    glfwSetKeyCallback(window, eventos_teclado);

    // Loop principal de todos eventos (ie, desenho, e/s)
    while (!glfwWindowShouldClose(window))
    {
        // Funcao de desenho
	    render();
    
        glfwSwapBuffers(window);

        // Poo
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
