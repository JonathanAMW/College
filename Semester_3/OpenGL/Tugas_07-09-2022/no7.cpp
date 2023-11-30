
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>


void drawDot(float x, float y){
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}

void userdraw(void){
  float x, y;
  for(int i=0; i<1000; i++){
    x=640*(float)rand()/RAND_MAX-320;
    y=480*(float)rand()/RAND_MAX-240;
    drawDot(x,y);
  }

}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
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
