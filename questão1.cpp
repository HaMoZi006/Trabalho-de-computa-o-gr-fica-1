#include <GL/glut.h>

void display() {
    // Cor de fundo (bege claro)
    glClearColor(1.0f, 0.96f, 0.82f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Corpo do barco (vermelho)
    glColor3f(0.89f, 0.0f, 0.11f); // vermelho vibrante
    glBegin(GL_POLYGON);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.8f, -0.4f);
    glEnd();

    // --- Vela esquerda (cinza)
    glColor3f(0.75f, 0.75f, 0.75f); // cinza claro
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, 0.4f);  
    glVertex2f(-0.2f, -0.3f);   
    glVertex2f(-0.5f, -0.3f);   

    glEnd();

    // --- Vela direita (cinza)
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glEnd();

    // --- Mastro (marrom)
    glColor3f(0.4f, 0.2f, 0.0f); // marrom escuro
    glBegin(GL_QUADS);
    glVertex2f(-0.225f, -0.4f);
    glVertex2f(-0.175f, -0.4f);
    glVertex2f(-0.175f, 0.35f);
    glVertex2f(-0.225f, 0.35f);
    glEnd();


    // --- Bandeira azul no topo
    glColor3f(0.2f, 0.2f, 0.8f); // azul escuro
    glBegin(GL_QUADS);
    glVertex2f(-0.23f, 0.35f);
    glVertex2f(-0.23f, 0.42f);
    glVertex2f(-0.03f, 0.42f);
    glVertex2f(-0.03f, 0.35f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Barquinho - OpenGL");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
