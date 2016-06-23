#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <math.h>

/* This program draws a cylinder and then rotates it by 90 degs.
Then it places a cuboid on top of the cylinder
*/

float theta = M_PI/4;

void display(void)
{
	GLfloat x=cos(theta), y=sin(theta);

	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//(camerax, cameray, cameraz,
	// lookatx, lookaty, lookatz,
	//        ,        ,        )
	// the final three are for tilting the camera )
	//add the xy to this,
	gluLookAt(x,3.0,y,0.0,0.0,0.0,0.0,1.0,0.0);
	//gluLookAt(0.0,2.0,-2.0,0.0,0.0,0.0,0.0,1.0,0.0);


	//alright how do we create the objects?
	
	//cylinder start here
	GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_LINE);
	
	glRotatef(-90.0,1.0,0.0,0.0);
	gluCylinder(MyCylinder,0.5,0.5,1.0,12,12);
	//culinder end here?

	//any of these operations add to the original, don't reset
	
	glRotatef(90.0,1.0,0.0,0.0); //these seem to move the cube upright
	glTranslatef(0.0,1.0,0.0);
	
	//something here is causing the rectangle to tilt what is it?

	
	glRotatef(-15.0,0.0,0.0,1.0); //these two commands are what tilt the cube, why?
	glTranslatef(0.0,0.5,0.0);
	
	glScalef(0.25,1.0,0.25); //this must decide the size/stretch of the origin
	glutWireCube(1.0); //this creates the rectangle
	
	//rotate the origin( )
	glRotatef(-90.0,0.0,0.0,1.0);
	
	//trandlate(up/down, forward/back, left/right) //this moves the origin
	glTranslatef(-0.8,1.0,0.0);
	//scalef, how does it work? (height, length, thickness)
	glScalef(0.2,3.0,1.0); //this must decide the size/stretch of the cube
	glutWireCube(1.0); //this creates the rectangle, paremeter is size?

	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,6.0);


	glViewport(0,0,w,h);
	return;
}

void MyIdle()
{
	theta += 0.001;
	if(theta > 2*M_PI) theta -= 2*M_PI;
	glutPostRedisplay();

	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cylinder");
	glutDisplayFunc(display);
	glutIdleFunc(MyIdle);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}