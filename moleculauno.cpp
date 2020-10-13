/*

Nombre del archivo: main.cpp
Contenido: Molécula uno
Autor: Leidy Johana Rivera - 2024011-3743

*/

/*
Include librerías necesarias
*/

#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <cmath>


using namespace std;
 /*
 Método que dibuja la Molécula uno
 */
void drawMoleculeOne(void) {
    int slices = 30;
    int stacks = 30;

    /* Centro */
    glPushMatrix();
    glColor3f(1, 1, 0);
    glutSolidSphere(0.4, slices, stacks);
    glPopMatrix();

    /* Esfera 1 */
    glPushMatrix();
    glColor3f(0.419, 0.850, 0.970);
    glTranslated(1.0, 0.18, 0.0);
    glScaled(0.6, 0.6, 0.6);
    glutSolidSphere(0.4, slices, stacks);
    glPopMatrix();

    /* Esfera 2 */
    glPushMatrix();
    glTranslated(-0.7, 0.8, 0);
    glScaled(0.6, 0.6, 0.6);
    glutSolidSphere(0.4, slices, stacks);
    glPopMatrix();

    /* Esfera 3 */
    glPushMatrix();
    glTranslated(-0.8, -1.2, 0);
    glScaled(0.8, 0.8, 0.8);
    glutSolidSphere(0.4, slices, stacks);
    glPopMatrix();

    /* Esfera 4 */
    glPushMatrix();
    glTranslated(1.2, -0.5, 0);
    glScaled(0.7, 0.7, 0.7);
    glutSolidSphere(0.4, slices, stacks);
    glPopMatrix();

    /*
    Dibujo las líneas que unen las esferas
    */

    glLineWidth(6);
    glColor3f(1, 1, 1);

    glBegin(GL_LINES);
    glVertex3f(-0.39, 0.0, 0);
    glVertex3f(-0.7, 0.57, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.4, 0.0, 0);
    glVertex3f(0.77, 0.13, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.36, -0.2, 0);
    glVertex3f(0.92, -0.4, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-0.286, -0.3, 0);
    glVertex3f(-0.65, -0.85, 0);
    glEnd();

}
const float DEG2RAD = 3.14159 / 180;



void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    drawMoleculeOne();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

/*
Entrada por teclado
*/

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'h':
        printf("help\n\n");
        printf("c - Toggle culling\n");
        printf("q/escape - Quit\n\n");
        break;
    case 'c':
        if (glIsEnabled(GL_CULL_FACE))
            glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE);
        break;
    case '1':
        glRotatef(1.0, 1., 0., 0.);
        break;
    case '2':
        glRotatef(1.0, 0., 1., 0.);
        break;
    case 'q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

/*
Método main
*/

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("Molécula uno - 2024011-3743");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

