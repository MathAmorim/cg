#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float matriz_modelview[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0,
};
 /*rotação 
matriz_modelview[12] = translate_x
matriz_modelview[13] = translate_y
matriz_modelview[14] = translate_z
float matriz_modelview[16] = {
    cos(100), sin(100), 0.0, 0.0,
    -sin(100), cos(100), 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0,
}; 
translação
float matriz_modelview[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    1.0, -1.0, 1.0, 1.0,
};
*/

float matriz_projection[16] = {
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0,
};

int width = 500,
    height = 500,
	x=0, y=0;


float scala_x = 0,scala_y = 0,scala_z = 0;
float rotate_x = 0,rotate_y = 0,rotate_z = 0;
float translate_x = 0,translate_y = 0,translate_z = 0; 
 
// Declarações 
void init(void);
void render(void);
void eventos_teclado(unsigned char _key, int _x, int _y);
void show_info();

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
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor do buffer   

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -5, 5);
    //glMultMatrixf(matriz_projection);
}

void desenha_cena(){
    printf("Desenhando bule\n");
    glColor3f(1.0, 0.0, 0.0);
    glutWireTeapot(3.0);
}

void render(void){
	glClear(GL_COLOR_BUFFER_BIT);   // Limpa para a cor do buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glScalef(-0.1 + scala_x,0.1 + scala_y,0.01 + scala_z);
    glMultMatrixf(matriz_modelview);

    desenha_cena();
    
	glFlush(); // Envia o desenho para o framebuffer
}

void eventos_teclado(unsigned char _key, int _x, int _y){
	switch (_key) {
 		case 'e':
            scala_x +=0.1;
            matriz_modelview[0] = scala_x;
            break;
        case 'E':
            scala_x -=0.1;
            matriz_modelview[0] = scala_x;
            break;
        case 'f':
            scala_y +=0.1;
            matriz_modelview[5] = scala_y;
            break;
        case 'F':
            scala_y -=0.1;
            matriz_modelview[5] = scala_y;
            break;  
        case 'v':
            scala_z +=0.1;
            matriz_modelview[10] = scala_z;
            break;
        case 'V':
            scala_z -=0.1;
            matriz_modelview[10] = scala_z;
            break;
        case 'p':
            rotate_z += 1;
            matriz_modelview[0] = cos(rotate_z);
            matriz_modelview[1] = sin(rotate_z);
            matriz_modelview[4] = -sin(rotate_z);
            matriz_modelview[5] = cos(rotate_z);
            break;
        case 'P':
            rotate_z -= 1;
            matriz_modelview[0] = cos(rotate_z);
            matriz_modelview[1] = sin(rotate_z);
            matriz_modelview[4] = -sin(rotate_z);
            matriz_modelview[5] = cos(rotate_z);
            break;
        case 't':
            translate_x += 1;
            matriz_modelview[12] = translate_x;
            break;
        case 'T':
            translate_x -= 1;
            matriz_modelview[12] = translate_x;
            break;  
        case 'y':
            translate_y += 1;
            matriz_modelview[13] = translate_y;
            break;
        case 'Y':
            translate_y -= 1;
            matriz_modelview[13] = translate_y;
            break; 
            case 'z':
            translate_z += 1;
            matriz_modelview[14] = translate_z;
            break;
        case 'Z':
            translate_z -= 1;
            matriz_modelview[14] = translate_z;
            break;  
        case 'r':
                matriz_modelview[0] = 1.0;
                matriz_modelview[1] = 0.0;
                matriz_modelview[2] = 0.0;
                matriz_modelview[3] = 0.0;
                matriz_modelview[4] = 0.0;
                matriz_modelview[5] = 1.0;
                matriz_modelview[6] = 0.0;
                matriz_modelview[7] = 0.0;
                matriz_modelview[8] = 0.0;
                matriz_modelview[9] = 0.0;
                matriz_modelview[10] = 1.0;
                matriz_modelview[11] = 0.0;
                matriz_modelview[12] = 0.0;
                matriz_modelview[13] = 0.0;
                matriz_modelview[14] = 0.0;
                matriz_modelview[15] = 1.0;
            break;        
		case 'q':
        case 'Q':
			exit(0);
			break;
	}
   glutPostRedisplay();
}
