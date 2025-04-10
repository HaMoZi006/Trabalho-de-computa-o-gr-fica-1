
#include <GL/glut.h>

// Posição Y do quadrado
float posY = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.0f, posY, 0.0f);  // Aplica translação no eixo Y
    glColor3f(1.0f, 0.0f, 0.0f);     // Cor vermelha
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 32) { // 32 é o código ASCII da barra de espaço
        posY += 0.01f; 
        glutPostRedisplay(); 
    }
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fundo branco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Define uma projeção ortogonal
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Quadrado Vermelho - Barra de Espaço Move");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

