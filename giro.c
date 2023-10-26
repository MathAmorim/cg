#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>  // Para usar funções trigonométricas

int width = 500,
    height = 500,
    x = 0, y = 0;
float angle = 0.0;  // Ângulo para girar as cores

// Declarações
void init(void);
void render(void);
void eventos_teclado(unsigned char _key, int _x, int _y);
void show_info();
void show_extensions();
void update_colors();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Especifica o buffer a ser utilizado
    glutInitWindowSize(width, height);  // Dimensões da Janela em pixels
    glutInitWindowPosition(0, 0); // Especifica coordenada superior esquerda
    glutCreateWindow("Janela inicial"); // Cria a janela mas só exibe após mainLoop
    init();
    show_info();
    glutDisplayFunc(render);
    glutKeyboardFunc(eventos_teclado);
    glutTimerFunc(100, update_colors, 0);  // Define a função de temporização
    glutMainLoop();

    return 0;
}

void show_info() {
    printf("Empresa: %s\n", glGetString(GL_VENDOR));
    printf("Modelo: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL: %s\n", glGetString(GL_VERSION));
    //show_extensions();
}

void update_colors() {
    // Atualiza o ângulo para girar as cores
    angle += 1.0;
    if (angle >= 360.0) {
        angle -= 360.0;
    }

    glutPostRedisplay();  // Solicita uma atualização da janela
    glutTimerFunc(100, update_colors, 0);  // Define o próximo chamada da função de temporização
}

/* void show_extensions() {
    const char* exts = glGetString(GL_EXTENSIONS);
    printf("Extensões: \n");

    char** t;
    for (t = &exts; **t != '\0'; (*t)++) {
        if (**t == ' ') {
            printf("\n");
        } else {
            printf("%c", **t);
        }
    }
} */

void desenha_tri() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0, 0.5);
    glEnd();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor do buffer

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT);   // Limpa para a cor do buffer

    glPushMatrix();  // Salva a matriz atual
    glRotatef(angle, 0.0, 0.0, 1.0);  // Gira as cores
    desenha_tri();
    glPopMatrix();  // Restaura a matriz salva

    glFlush(); // Envia o desenho para o framebuffer
}

void eventos_teclado(unsigned char _key, int _x, int _y) {
    switch (_key) {
    case 'q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}