#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <cmath>

typedef struct {
float x;
float y;
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
{ Point2D_t shape[360];

double srad,r;
for(int s=0;s<360;s++)
{ srad=s*3.14/180;
r=sin(5*srad);
shape[s].x=(float)(r*cos(srad));
shape[s].y=(float)(r*sin(srad));

}
Polygon(shape,360);

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
  //gluOrtho2D(-320., 320., -240.0, 240.0); //membuat koordinat kartesian
  gluOrtho2D(-15., 15., -15.0, 15.0); //membuat koordinat kartesian
  glutIdleFunc (display);  
  glutDisplayFunc(display); 
  glutMainLoop(); 
  return 0;  
}

