#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int width = 500,
    height = 500,
	x=0, y=0;
 
// Declarações 
void init(void);
void render(void);
void eventos_teclado(unsigned char _key, int _x, int _y);
void show_info();
void show_extensions();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE  | GLUT_RGB);  // Especifica o buffer a ser utilizado
	glutInitWindowSize(width,height);  // Dimensoes da Janela em pixels
	glutInitWindowPosition(0,0); // Especifica coordenada superior esquerda 
	glutCreateWindow("Janela inicial"); // Cria a janela mas só exibe após mainLoop
	init();
    show_info();
	glutDisplayFunc(render); 
	glutKeyboardFunc(eventos_teclado);
	glutMainLoop();

	return 0;
}

void show_info(){
    printf("Empresa: %s\n", glGetString(GL_VENDOR));
    printf("Modelo: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL: %s\n", glGetString(GL_VERSION));
    //show_extensions();
}

void desenha_tri(){
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.5,-0.5);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.5,-0.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0,0.5);
    glEnd();
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor do buffer

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void render(void){
	glClear(GL_COLOR_BUFFER_BIT);   // Limpa para a cor do buffer
    desenha_tri();
	glFlush(); // Envia o desenho para o framebuffer
}

void eventos_teclado(unsigned char _key, int _x, int _y){
	switch (_key) {
		case 'q':
		case 27:
			exit(0);
			break;
	}
   glutPostRedisplay();
}