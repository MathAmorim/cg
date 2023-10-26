#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int width = 500,
    height = 500,
    x = 0, y = 0;
int drawMode = GL_POINTS;  // Inicialmente, desenhe pontos

// Declarações
void init(void);
void render(void);
void eventos_teclado(unsigned char _key, int _x, int _y);
void show_info();

void draw_text(const char* text, int x, int y);

int main(int argc, char** argv) {
    system("clear");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Especifica o buffer a ser utilizado
    glutInitWindowSize(width, height);            // Dimensoes da Janela em pixels
    glutInitWindowPosition(0, 0);                 // Especifica coordenada superior esquerda
    glutCreateWindow("Janela inicial");           // Cria a janela mas só exibe após mainLoop
    init();
    show_info();
    glutDisplayFunc(render);
    glutKeyboardFunc(eventos_teclado);
    glutMainLoop();

    return 0;
}

void show_info() {
    printf("Empresa: %s\n", glGetString(GL_VENDOR));
    printf("Modelo: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL: %s\n", glGetString(GL_VERSION));
}

void desenha_forma() {
    switch (drawMode) {
    case GL_POINTS:
        glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(0, 0);
        glEnd();
        break;
    case GL_LINES:
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glEnd();
        break;
    case GL_LINE_STRIP:
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0.5, 0.5);
        glEnd();
        break;
    case GL_LINE_LOOP:
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0.5, 0.5);
        glEnd();
        break;
    case GL_TRIANGLES:
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0, 0.5);
        glEnd();
        break;
    case GL_TRIANGLE_STRIP:
        glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(-0.5, 0.5);
        glColor3f(1.0, 1.0, 0.0); // Amarelo
        glVertex2f(0.5, 0.5);
        glEnd();
        break;
    case GL_TRIANGLE_FAN:
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(0, 0);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0.5, -0.5);
        glColor3f(1.0, 1.0, 0.0); // Amarelo
        glVertex2f(-0.5, 0.5);
        glColor3f(0.0, 1.0, 1.0); // Ciano
        glVertex2f(0.5, 0.5);
        glEnd();
        break;
    case GL_QUADS:
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0.5, 0.5);
        glColor3f(1.0, 1.0, 0.0); // Amarelo
        glVertex2f(-0.5, 0.5);
        glEnd();
        break;
    case GL_QUAD_STRIP:
        glBegin(GL_QUAD_STRIP);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(-0.5, 0.5);
        glColor3f(1.0, 1.0, 0.0); // Amarelo
        glVertex2f(0.5, 0.5);
        glEnd();
        break;
    case GL_POLYGON:
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0); // Vermelho
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(0.5, 0.5);
        glColor3f(1.0, 1.0, 0.0); // Amarelo
        glVertex2f(0, 0.7);
        glColor3f(0.0, 1.0, 1.0); // Ciano
        glVertex2f(-0.5, 0.5);
        glEnd();
        break;
}
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Cor do buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpa para a cor do buffer
    desenha_forma();
    glFlush();  // Envia o desenho para o framebuffer
}

void eventos_teclado(unsigned char _key, int _x, int _y) {
    switch (_key) {
        case 'q':
        case 27:
            exit(0);
            break;
        case 't':
            // Alterna entre os modos de desenho
            drawMode++;
            if (drawMode > GL_POLYGON) {
                drawMode = GL_POINTS;
            }
            break;
    }
    glutPostRedisplay();
}
