#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

void drawDot(float x, float y){
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}

void userdraw(void){
  glPointSize(1);
  drawDot(100,50);
  drawDot(100,130);
  glPointSize(10);
  drawDot(150,130);
}

void display(void) {

glClear( GL_COLOR_BUFFER_BIT);
userdraw();
glutSwapBuffers();

}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  //glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition (100, 100);
glutInitWindowSize(640,480); 
glutCreateWindow ("Test");
glClearColor(0.0, 0.0, 0.0, 0.0); 
gluOrtho2D(-320., 320., -240.0, 240.0);
glutIdleFunc (display);  
glutDisplayFunc(display); 
glutMainLoop(); 
return 0;  
}