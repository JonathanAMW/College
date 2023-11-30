//MEMBUAT MEJA DAN KURSI PADA OPENGL

//ANGGOTA KELOMPOK
//ANANTA MIYORU WIJAYA 	- 5221600015
//HUSEIN AZKA EFFENDI 	- 5221600009

#define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h> //glew dan glad tidak bisa bersatu
#include <GL/freeglut.h> 

#include<stb/stb_image.h>
#include"cube.h"

// Globals.
static float angle = 0.0; // Rotation.angle 
static int isAnimate = 0; // Animated?
static int animationPeriod = 100; // Time interval between frames.

static float angleX = 0.0; // Rotation.angle 
static float angleY = 0.0; // Rotation.angle 
static float X = 0.0;
static float Y = 0.0;
static float Z = 0.0;

bool isLight = false;
bool bShouldReverse = false;

//besar array untuk menyimpan texture
#define ARRAY_SIZE 3
void loadTextureFromFile(const char *filename, unsigned int texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                     GL_RGB, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture - " << filename << std::endl;
    }
    stbi_image_free(data);
}

//declare texture file to be imported
const char* filename1 = "Textures/white_texture.jpg";
const char* filename2 = "Textures/glass.jpg";
const char* filename3 = "Textures/wood.jpg";


unsigned int tob[ARRAY_SIZE]; //jumlah texture yang akan dimasukkan array

void textureSetup()
{
	glGenTextures(ARRAY_SIZE, &tob[0]);

    loadTextureFromFile(filename1, tob[0]);
    loadTextureFromFile(filename2, tob[1]);
    loadTextureFromFile(filename3, tob[2]);
}

void drawChair()
{
	float width = 10;
	
	glTranslatef(0.0f, 0.0f, angle);
	
	//kaki kanan
	glBindTexture(GL_TEXTURE_2D, tob[0]);
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(width-2, 0.0 , 0.0);
	glScalef(1.0, 1.0, width-2);
    glutCustomSolidCube(2);
    glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(width-2, 0.0 , width-2);
	glScalef(1.0, 1.0, 1.1);
	glutCustomSolidCube(2);
    glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(width-2, 0.0 , -(width-2));
	glScalef(1.0, 1.0, 1.1);
	glutCustomSolidCube(2);
    glPopMatrix();


	//kaki kiri
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(-width+2, 0.0 , 0.0);
	glScalef(1.0, 1.0, width-2);
	glutCustomSolidCube(2);
    glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(-width+2, 0.0 , width-2);
	glScalef(1.0, 1.0, 1.1);
	glutCustomSolidCube(2);
    glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslated(-width+2, 0.0 , -(width-2));
	glScalef(1.0, 1.0, 1.1);
	glutCustomSolidCube(2);
    glPopMatrix();

	//kaki bawah kiri
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(-width+2, 7.0 , 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 1.0, 7.0);
	glutCustomSolidCube(2);
    glPopMatrix();

	//kaki bawah kanan
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(width-2, 7.0 , 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 1.0, 7.0);
	glutCustomSolidCube(2);
    glPopMatrix();

	//pertengahan kaki 
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(0.0, 7.0 , 0.0);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glScalef(1.0, 1.0, width);
	glutCustomSolidCube(1.5);
    glPopMatrix();

	//kaki atas kiri
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(-width+2, 13.0 , 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 1.0, 7.0);
	glutCustomSolidCube(1.5);
    glPopMatrix();

	//kaki atas kanan
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(width-2, 13.0 , 0.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 1.0, 7.0);
	glutCustomSolidCube(1.5);
    glPopMatrix();

	//tempat duduk
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(0.0, 18.0 , 1.0);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(10.0, 1.0, 10.0);
	glutCustomSolidCube(2);

    glPopMatrix();

	//sandaran duduk
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	glTranslated(0.0, 27.0 , -9.0);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(20.0, 20.0, 1.0);
	
	glutCustomSolidCube(1);
    glPopMatrix();
}

void drawDesk()
{
	//tengah bawah
	glBindTexture(GL_TEXTURE_2D, tob[2]);
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glTranslated(1.0, 13 , 20.0);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(18.0, 13, 1.0);
	glutCustomSolidCube(2);
    glPopMatrix();
	
	//kiri bawah
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glTranslated(20, 13.0 , 11.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 10.0, 13.0);
	glutCustomSolidCube(2);
    glPopMatrix();
	
	//kanan bawah
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glTranslated(-18, 13.0 , 11.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 10.0, 13.0);
	glutCustomSolidCube(2);
    glPopMatrix();
	
	//kanan atas
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glTranslated(-18, 42.5 , 11.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 10.0, 14.75);
	glutCustomSolidCube(2);
    glPopMatrix();
	
	//kiri atas
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glTranslated(20, 42.5 , 11.0);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(1.0, 10.0, 14.75);
	glutCustomSolidCube(2);
    glPopMatrix();
	
	//tengah
	glPushMatrix();
	glColor3f(0.5, 0.35, 0.05);
	glTranslated(1.0, 27.0 , 11.0);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(20.0, 1.0, 10.0);
	glutCustomSolidCube(2);
    glPopMatrix();
	
	//depan
	glBindTexture(GL_TEXTURE_2D, tob[1]);
	glPushMatrix();
	//glColor3f(1.0f, 0.90f, 0.5f);
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslated(1.0, 42.5 , 20.0);
	//glRotatef(90, 1.0f, 0.0f, 0.0f);
	glScalef(18.0, 14.75, 1.0);
	glutCustomSolidCube(2);
    glPopMatrix();
}

void lightingSetup()
{
	if(isLight)
	{
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING); //Enable lighting
		glEnable(GL_LIGHT0); //Enable light #0
		glEnable(GL_LIGHT1); //Enable light #1
		glEnable(GL_NORMALIZE); //Automatically normalize normals
	}
	else if (!isLight)
	{
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING); //Enable lighting
		glDisable(GL_LIGHT0); //Enable light #0
		glDisable(GL_LIGHT1); //Enable light #1
		glDisable(GL_NORMALIZE); //Automatically normalize normals
	}
	glShadeModel(GL_SMOOTH); //Enable smooth shading

	//Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
}

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	
	//enable texture
	glEnable(GL_TEXTURE_2D);

	lightingSetup();

    // Place scene in frustum.
	glTranslatef(0.0, -15.0, -50.0);

	// Modeling transformations.
	glTranslatef(X, Y, Z);
	glRotatef(angleX, 0.0f, 1.0f, 0.0f);
	glRotatef(angleY, 1.0f, 0.0f, 0.0f);
	
	//draw chair
	glPushMatrix();
	drawChair();
	glPopMatrix();
	
	//draw desk
	glPushMatrix();
	drawDesk();
	glPopMatrix();

	glutSwapBuffers();
}

// Routine to increase the rotation angle.
void increaseAngle(void)
{
	if(angle <= -25.0) bShouldReverse = true;
	else if(angle >= 0.0) bShouldReverse = false;

	if(!bShouldReverse)
	{
		angle -= 1.0;
	}
	else if(bShouldReverse)
	{
		angle += 1.0;
	}
	// += 5.0;
	//if (angle > 360.0) angle -= 360.0;
}

// Timer function.
void animate(int value)
{
	if (isAnimate)
	{
		increaseAngle();

		glutPostRedisplay();
		glutTimerFunc(animationPeriod, animate, 1);
	}
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	textureSetup();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-10.0, 10.0, -10.0, 10.0, 5.0, 100.0);

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
	case ' ':
		if (isAnimate) isAnimate = 0;
		else
		{
			isAnimate = 1;
			animate(1);
		}
		glutPostRedisplay();
		break;

	//move camera
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
	case 'j':
		angleX += 0.5;
		glutPostRedisplay();
		break;
	case 'l':
		angleX -= 0.5;
		glutPostRedisplay();
		break;
	case 'i':
		angleY += 0.5;
		glutPostRedisplay();
		break;
	case 'k':
		angleY -= 0.5;
		glutPostRedisplay();
		break;
	case 'p':
		angleX = 0.0;
		angleY = 0.0;
		glutPostRedisplay();
		break;
	case 'x':
		if(isLight) isLight = false;
		else if(!isLight) isLight = true;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN) animationPeriod += 5;
	if (key == GLUT_KEY_UP) if (animationPeriod > 5) animationPeriod -= 5;
	glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Press space to toggle between animation on and off." << "\n" 
		<< "Press the up/down arrow keys to speed up/slow down animation." << "\n" 
		<< "Press wasd to move the object around camera" << "\n" 
		<< "Press qe to zoom the object around camera" << "\n" 
		<< "Press jl to rotate horizontally the object around camera" << "\n" 
		<< "Press ik to rotate vertically the object around camera" << "\n" 
		<< "Press p to reset the object position" << "\n" 
		<< "Press x to toggle light on and off" << std::endl;
}

// Main routine.
int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("5221600009 || 5221600015_Meja dan Kursi");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);

	glewExperimental = GL_TRUE;
	glewInit();
	
	setup();

	glutMainLoop();
}


