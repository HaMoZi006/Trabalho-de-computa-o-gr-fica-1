
#include <GL/glut.h>

float posY = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.0f, posY, 0.0f); 
    glColor3f(1.0f, 0.0f, 0.0f);    
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
    if (key == 32) { 
        posY += 0.01f; 
        glutPostRedisplay(); 
    }
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); 
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

—----------------
QUADRADINHO ROXO

#include <GL/glut.h>

float posX = -0.9f;    
float speed = 0.01f;   

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(posX, 0.0f, 0.0f);   
        glColor3f(0.5f, 0.0f, 0.5f);      
        glBegin(GL_QUADS);
            glVertex2f(-0.1f, -0.1f);
            glVertex2f( 0.1f, -0.1f);
            glVertex2f( 0.1f,  0.1f);
            glVertex2f(-0.1f,  0.1f);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    posX += speed;

    if (posX > 0.9f || posX < -0.9f) {
        speed = -speed;
    }

    glutPostRedisplay();                 
    glutTimerFunc(16, update, 0);        
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);            
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Quadrado Roxo Animado");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
