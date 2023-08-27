#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

void drawPolygon(){
  glBegin(GL_LINE_LOOP);
  glVertex2f(100, 100);
  glVertex2f(200, 150);
  glVertex2f(300, 50);
  //glVertex2f(x2, y2);
  glEnd();
}

void userdraw(void){
  drawPolygon();
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