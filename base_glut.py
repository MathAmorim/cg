from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import numpy as np

'''
Codigo adaptado de PyOpenGL Demos
'''

janela = 0

def InitGL():
    glClearColor(0.0, 0.0, 0.0, 0.0)    # This Will Clear The Background Color To Black    

    glMatrixMode(GL_MODELVIEW)    
    glLoadIdentity()

def show_info():
    print('Empresa: ' + str(glGetString(GL_VENDOR).decode()))
    print('Modelo: ' + str(glGetString(GL_RENDERER).decode()))
    print('OpenGL: ' + str(glGetString(GL_VERSION).decode()))
    #show_extensions()

def show_extensions():
    exts = glGetString(GL_EXTENSIONS).decode().split(' ')
    print('Extensoes ativas: ')
    for ext in exts:
        print(ext)

def desenha_tri():
    glBegin(GL_TRIANGLES)
    glColor3f(1.0, 0.0, 0.0)
    glVertex2f(-0.5,-0.5)
    glColor3f(0.0, 1.0, 0.0)
    glVertex2f(0.5,-0.5)
    glColor3f(0.0, 0.0, 1.0)
    glVertex2f(0,0.5)
    glEnd()

def render():
    glClear(GL_COLOR_BUFFER_BIT)
    desenha_tri()        
    glutSwapBuffers()

def keyboard(key, x, y):
    k = key.decode()
    if k == 'q':
        os._exit(0)

def main():
    print('Funcao principal')
    global janela

    # Inicia XXX da glut
    glutInit(sys.argv)

    # Seleciona os modos de display (buffer duplo, cor RGBA, depth buffer, ...)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB)

    # Define tamanho da janela
    glutInitWindowSize(500, 500)

    # Define posicao da janela (Origem eh no canto superior esquerdo)
    glutInitWindowPosition(0, 0)  

    # Define o modo de compatibilidade (opengl com pipeline fixo, versao 3.2)
    glutInitContextVersion(3,2)
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE)

    # Cria a janela
    janela = glutCreateWindow('Janela inicial')

    # Define a funcao de rendering
    glutDisplayFunc(render)

    # Tela cheia?
    #glutFullScreen()

    # Define a funcao que gerencia eventos de teclado
    glutKeyboardFunc(keyboard)

    # Inicializa o estado do OpenGL na janela
    InitGL()

    # Mostra detalhes do hardware, driver e ultima versao do OpenGL suportada
    show_info()

    # Loop principal de eventos
    glutMainLoop()

if __name__ == '__main__':
    print("Aperte q para sair")
    main()
    