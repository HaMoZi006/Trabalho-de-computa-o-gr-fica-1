#include <GL/glut.h>
#include <cmath>

#define M_PI 3.14159265358979323846

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Anel externo (azul escuro)
    glColor3f(0.0f, 0.0f, 0.2f);
    drawCircle(0.5f, 100);

    // Anel do meio (azul mais claro)
    glColor3f(0.0f, 0.0f, 0.6f);
    drawCircle(0.35f, 100);

    // Anel interno (azul escuro de novo)
    glColor3f(0.0f, 0.0f, 0.2f);
    drawCircle(0.2f, 100);

    // Centro branco
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.08f, 100);

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // fundo branco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Alvo Azul");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

