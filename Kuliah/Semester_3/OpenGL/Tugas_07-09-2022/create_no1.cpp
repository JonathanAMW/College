#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>


void drawCircle(float c_x, float c_y, float r, int number)
{
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < number; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(number);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + c_x, y + c_y);

    }
    glEnd();
}

void userdraw(void) {

  drawCircle(25, 25, 100, 360);

}

void display(void) {

glClear( GL_COLOR_BUFFER_BIT);
userdraw();
glutSwapBuffers();

}

int main(int argc, char **argv){
glutInit(&argc,argv);
glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB );
glutInitWindowPosition(100,100);
glutInitWindowSize(640,480);
glutCreateWindow ("Circle");
glClearColor(0.0, 0.0, 0.0, 0.0);
gluOrtho2D(-320., 320., -240.0, 240.0);
glutIdleFunc(display);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
