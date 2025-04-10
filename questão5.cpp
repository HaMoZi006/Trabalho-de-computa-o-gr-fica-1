#include <GL/glut.h>
#include <cmath>

#define M_PI 3.14159265358979323846

float angle = 0.0f; // Ângulo de rotação

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Translação + Rotação
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, -1.0f); // Sentido horário

    int numSegments = 100;
    float radius = 0.5f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f); // Centro branco
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);

        switch (i % 8) {
        case 0: glColor3f(1.0f, 0.0f, 0.0f); break; // vermelho
        case 1: glColor3f(0.0f, 1.0f, 0.0f); break; // verde
        case 2: glColor3f(0.0f, 0.0f, 1.0f); break; // azul
        case 3: glColor3f(1.0f, 1.0f, 0.0f); break; // amarelo
        case 4: glColor3f(1.0f, 0.0f, 1.0f); break; // rosa
        case 5: glColor3f(0.5f, 0.0f, 0.5f); break; // roxo escuro
        }
        
        glVertex2f(x, y);
    }
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0f; // Rotação no sentido horário
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay();             
    glutTimerFunc(16, update, 0);    
}

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Fundo escuro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circulo Multicolorido Girando");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}


