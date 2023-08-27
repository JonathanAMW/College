#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

void drawLine(float x1, float y1, float x2, float y2){
  glBegin(GL_LINES);
  glColor3f(1, 0, 0); glVertex2f(x1, y1);
  glColor3f(0, 1, 0); glVertex2f(x2, y2);
  glEnd();
}

void drawPolygonRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
  glBegin(GL_POLYGON);
  glColor4f(1, 0, 0,0); glVertex2f(x1, y1); //merah
  glColor4f(1, 1, 0,0); glVertex2f(x2, y2); //kuning
  glColor4f(0, 0, 1, 0); glVertex2f(x3, y3); //biru
  glColor4f(0, 1, 0,0); glVertex2f(x4, y4); //hijau
  glEnd();
}

void drawPolygonTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
  glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(x1, y1, z1);
    glColor3f(0, 1, 0); glVertex3f(x2, y2, z2);
    glColor3f(0, 0, 1); glVertex3f(x3, y3, z3);
  glEnd();
}

void userdraw(void){
  drawPolygonRectangle(100, 100, 100, 190, 190, 190, 190, 100);
  drawPolygonRectangle(50, 50, 50, 75, 75, 75, 75, 50);

  drawPolygonTriangle(-60, -75, 0, 60, -75, 0, 0, 75, 0);
  drawPolygonTriangle(-130, 10, 0, -100, 10, 0, -115, 30, 0);
  
  drawLine(-100, -100, -200, -150);
  drawLine(-110, -110, -150, -160);
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