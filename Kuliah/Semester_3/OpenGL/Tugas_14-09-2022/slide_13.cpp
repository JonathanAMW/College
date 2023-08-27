#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

typedef struct {
int x;
int y;
} Point2D_t;

void Polygon(Point2D_t pnt[],int n)
{
int i;
glBegin(GL_LINE_LOOP);
for (i=0;i<n;i++) {
glVertex2f(pnt[i].x, pnt[i].y);
}
glEnd();
}

void userdraw()
{ 
  Point2D_t kotak[4]={{100,100},{300,100}, {300,200},{100,200}};
  Polygon(kotak,4);

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
  glutInitWindowSize(640,480); //mengeset resolusi kanvas
  glutCreateWindow ("5221600015_Ananta Miyoru Wijaya");
  glClearColor(0.0, 0.0, 0.0, 0.0); 
  gluOrtho2D(-320., 320., -240.0, 240.0); //membuat koordinat kartesian
  glutIdleFunc (display);  
  glutDisplayFunc(display); 
  glutMainLoop(); 
  return 0;  
}

