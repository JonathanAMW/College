#include <iostream>
#include <cmath>

#include <GL/glew.h>
#include <GL/freeglut.h> 

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;

static float A = 0.0;
static float B = 0.0;
static float C = 0.0;
static float D = 0.0;

void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*M_PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*M_PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Modeling transformations.
	glTranslatef(X, Y, Z);
	glRotatef(A, B, C, D);

	glRotatef(-60, 1.0, 0.0, 0.0);
	draw_cylinder(5.0, 1.0, 255, 160, 100);
	glRotatef(60, -1.0, 0.0, 0.0);

    glRotatef(-60, -1.0, 0.5, 0.0);
	draw_cylinder(1., -15.0, 255, 160, 100);
    glRotatef(60, 1.0, -0.5, 0.0);

	glRotatef(231.5, -1, -5, -5);
	draw_cylinder(1.0, -15.0, 255, 160, 100);
//	glRotatef(60, 1.0, 15.0, 0.0);
	glRotatef(-231.5, 1, 5, 5);

	glRotatef(-196.5, 0, -4.5, -3.5);
	draw_cylinder(1.0, -15.0, 255, 160, 100);


	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	//glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X+=0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	case 'i':
		A += 0.5;
		glutPostRedisplay();
		std::cout << A << "\n";
		break;
	case 'k':
		A -= 0.5;
		glutPostRedisplay();
		std::cout << A << "\n";
		break;
	case 'o':
		B += 0.5;
		glutPostRedisplay();
		std::cout << B << "\n";
		break;
	case 'l':
		B -= 0.5;
		glutPostRedisplay();
		std::cout << B << "\n";
		break;
	case 'u':
		C += 0.5;
		glutPostRedisplay();
		std::cout << C << "\n";
		break;
	case 'j':
		C -= 0.5;
		glutPostRedisplay();
		std::cout << C << "\n";
		break;
	case 'y':
		D += 0.5;
		glutPostRedisplay();
		std::cout << D << "\n";
		break;
	case 'h':
		D -= 0.5;
		glutPostRedisplay();
		std::cout << D << "\n";
		break;
	case 'p':
		std::cout << A << "\n";
		std::cout << B << "\n";
		std::cout << C << "\n";
		std::cout << D << "\n";
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("5221600015_Ananta Miyoru Wijaya.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}

