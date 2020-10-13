/*

Nombre del archivo: main.cpp
Contenido: Sistema solar 
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

#define PI 3.1415926
float x, y;
float angulo = 0.0f;
GLfloat left, right, up, down = 0.1;

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 4, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); 
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
    glutSolidSphere(0.2, 100, 100); /* Sol */
    glPopMatrix();
    glPushMatrix();	
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();

    glBegin(GL_POINTS);
    for (int i = 2; i < 6; i++) {
        float angulo = 0.0f;
        while (angulo <= (2 * PI)) {
            float x = (float)(((float)i / 7.0) * cos(angulo));
            float y = (float)(((float)i / 7.0) * sin(angulo));
            glVertex2f(x, y);
            angulo += 0.001;
        }
    }
    glEnd();

    glPopMatrix();
    glPushMatrix();

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    float angulo = 0.0f;
    while (angulo <= (2 * PI)) {
        float x = (float)(((float)6 / 7.0) * cos(angulo));
        float y = (float)(((float)6 / 7.0) * sin(angulo));
        glVertex2f(x, y);
        angulo += 0.05;
    }
    glEnd();

    glPopMatrix();
    glPushMatrix();

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 7; i < 11; i++) {
        float angulo = 0.0f;
        while (angulo <= (2 * PI)) {
            float x = (float)(((float)i / 7.0) * cos(angulo));
            float y = (float)(((float)i / 7.0) * sin(angulo));
            glVertex2f(x, y);
            angulo += 0.001;
        }
    }
    glEnd();

    glPopMatrix();

    /*
    Dibujar planetas
    */
    /* Mercurio */
    glColor3f(0.57, 0.07, 0.20);
    glPushMatrix();
    glTranslatef(0.28, 0.04, 0.0);
    glutSolidSphere(0.05, 100, 100);
    glPopMatrix();

    /* Venus */
    glColor3f(0.9, 0.4, 0.160);
    glPushMatrix();
    glTranslatef(0.32, 0.3, 0.0);
    glutSolidSphere(0.06, 100, 100);
    glPopMatrix();

    /* Tierra */
    glColor3f(0.070, 0.25, 0.85);
    glPushMatrix();
    glTranslatef(-0.52, 0.30, 0.0);
    glutSolidSphere(0.10, 100, 100);
    glPopMatrix();

    /* Marte */
    glColor3f(0.900, 0.130, 0.011);
    glPushMatrix();
    glTranslatef(0.67, -0.29, 0.0);
    glutSolidSphere(0.09, 100, 100);
    glPopMatrix();

    /* Júpiter */
    glColor3f(0.480, 0.240, 0.045);
    glPushMatrix();
    glTranslatef(-0.90, -0.40, 0.0);
    glutSolidSphere(0.13, 100, 100);
    glPopMatrix();

    /* Saturno */
    glColor3f(0.8, 0.517, 0.2);
    glPushMatrix();
    glTranslatef(0.90, 0.7, 0.0);
    glutSolidSphere(0.12, 100, 100);
    glPopMatrix();

    /* Urano */
    glColor3f(0.2, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(-0.2, 1.28, 0.0);
    glutSolidSphere(0.09, 100, 100);
    glPopMatrix();

    /* Neptuno */
    glColor3f(0.086, 0.549, 0.831);
    glPushMatrix();
    glTranslatef(-1.40, 0.2, 0.0);
    glutSolidSphere(0.09, 100, 100);
    glPopMatrix();

    
    glutSwapBuffers();
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
    glutCreateWindow("Sistema solar - 2024011-3743");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

