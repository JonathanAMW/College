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
//glBegin(GL_LINE_LOOP);
glBegin(GL_LINE_STRIP);
for (i=0;i<n;i++) {
glVertex2f(pnt[i].x, pnt[i].y);
}
glEnd();
}

void userdraw()
{ Point2D_t shape[720];

double srad,r;
for(int s=0;s<720;s++)
{ srad=s*3.14/180;
//r=sin(2*srad); // 4 daun
//r=sin(3*srad); // 3 daun
r=srad; // spiral
shape[s].x=(float)(r*cos(srad));
shape[s].y=(float)(r*sin(srad));

}
Polygon(shape,720);

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

  //spiral
  gluOrtho2D(-100, 100.0, -100.0, 100.0); //membuat koordinat kartesian
  //rose
  //gluOrtho2D(-5.0, 5.0, -5.0, 5.0); //membuat koordinat kartesian

  glutIdleFunc (display);  
  glutDisplayFunc(display); 
  glutMainLoop(); 
  return 0;  
}

