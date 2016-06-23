#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <stdio.h>
/*
Name: Diarmaid Farrell
Student number: 11531677

README!!!!!!!!!!!!!!!!!!!!!!!!!!

to use this program simply right click on either of the windows to change the shape/colour/transparency/brightness

once you have selected a drawing option just choose a colour by left clicking on the pallet (your chosen colour will be displayed 
in the top left hand corner of the pallet) and then left click on the drawing window to draw your item 


I delare that this is all my own work, I received no help from others in finishing this assignment beyond what is normal.


*/

GLubyte pixel_color[3];
GLfloat polysidesx[20];
GLfloat polysidesy[20];
GLfloat x1,x2,y1,y2;
GLfloat red = 0.5;
GLfloat blue = 0.5;
GLfloat green = 0.5;
GLfloat blend = 1.0;
GLfloat brightness = 1.0;
GLfloat brightness2 = 0.0;
GLfloat r2 = 0.0;
GLfloat b2 = 0.0;
GLfloat g2 = 0.0;

GLfloat palletred = 1.0;
GLfloat palletyellow = 1.0;
GLfloat palletgreen = 1.0;
GLfloat palletcyan = 1.0;
GLfloat palletblue = 1.0;
GLfloat palletpurple = 1.0;

GLfloat xx1,xx2,yy1,yy2;
//GLfloat hh;
GLsizei ww, hh;
static int firstdisplay = 1;
static int getpoints = 1;
static int polysides = 0;
static int polysides2 = 0;
static int polysides3 = 0; //changed this

static int window;
static int menu_id;
static int submenu_id;
static int submenu_id2;
static int submenu_id3;
static int submenu_id4;
static int submenu_id5;
static int submenu_id6;
static int submenu_id7;
static int submenu_id8;
static int submenu_id9;
static int submenu_id10;
static int value = 0; 

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }
  else{
    value = num;
  }
  glutPostRedisplay();
} 

void createMenu(void){     
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Polygon 3", 27);
	glutAddMenuEntry("Polygon 4", 28);
    glutAddMenuEntry("Polygon 5", 2);
    glutAddMenuEntry("Polygon 6", 29);
    glutAddMenuEntry("Polygon 7", 30);
    glutAddMenuEntry("Polygon 8", 31);
    glutAddMenuEntry("Polygon 9", 32);
    glutAddMenuEntry("Polygon 10", 33);
    glutAddMenuEntry("Line", 3);
    glutAddMenuEntry("point", 4);
    submenu_id2 = glutCreateMenu(menu);
    glutAddMenuEntry("transparency 0", 34); 
    glutAddMenuEntry("transparency .2", 6);
    glutAddMenuEntry("transparency .4", 35);
    glutAddMenuEntry("transparency .6", 36);
    glutAddMenuEntry("transparency .8", 37);
    glutAddMenuEntry("non-transparent 1.0", 5);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddSubMenu("Transparency", submenu_id2);
    glutAddMenuEntry("Quit", 0);     
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 

void createMenu2(void){     
	submenu_id3 = glutCreateMenu(menu);
	glutAddMenuEntry("brightness 0.0", 38);
	glutAddMenuEntry("brightness 0.25", 39);
    glutAddMenuEntry("brightness 0.5", 7);  
    glutAddMenuEntry("(normal) 1.0", 8); 
    glutAddMenuEntry("brightness 1.25", 9); 
    glutAddMenuEntry("brightness 1.50", 40);
    glutAddMenuEntry("brightness 1.75", 41);
    glutAddMenuEntry("brightness 2.00", 42);
    submenu_id4 = glutCreateMenu(menu);
    glutAddMenuEntry("red full", 10);
    glutAddMenuEntry("red medium", 11);
    glutAddMenuEntry("red none", 12); 
    submenu_id5 = glutCreateMenu(menu); 
    glutAddMenuEntry("yellow full", 13);
    glutAddMenuEntry("yellow medium", 14);
    glutAddMenuEntry("yellow none", 15);
    submenu_id6 = glutCreateMenu(menu);
    glutAddMenuEntry("green full", 16);
    glutAddMenuEntry("green medium", 17);
    glutAddMenuEntry("green none", 18);
    submenu_id7 = glutCreateMenu(menu);
    glutAddMenuEntry("cyan full", 19);
    glutAddMenuEntry("cyan medium", 20);
    glutAddMenuEntry("cyan none", 21);
    submenu_id8 = glutCreateMenu(menu);
    glutAddMenuEntry("blue full", 22);
    glutAddMenuEntry("blue medium", 23);
    glutAddMenuEntry("blue none", 24);
    submenu_id9 = glutCreateMenu(menu);
    glutAddMenuEntry("purple full", 25);
    glutAddMenuEntry("purple medium", 26);
    glutAddMenuEntry("purple none", 27);
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("brightness", submenu_id3);
    glutAddSubMenu("red levels", submenu_id4);
    glutAddSubMenu("yellow levels", submenu_id5);
    glutAddSubMenu("green levels", submenu_id6);
    glutAddSubMenu("cyan levels", submenu_id7);
    glutAddSubMenu("blue levels", submenu_id8);
    glutAddSubMenu("purple levels", submenu_id9);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void){
	glClearColor(1.0,1.0,1.0,1.0);
	if(firstdisplay == 1){
		//glClearColor(0.0,0.0,1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		firstdisplay = 0;
	}
	if(value == 1){ //clear screen
		glClear(GL_COLOR_BUFFER_BIT);
  		glClearColor(1.0,1.0,1.0,1.0);
  		value = 50;
	}
	if(value == 34){ //fully transparent
		blend = 0.0;
		glColor4f(red,green,blue,blend);
	}
	if(value == 6){ //high transparency
		blend = 0.2;
		glColor4f(red,green,blue,blend);
	}
	if(value == 35){ 
		blend = 0.4;
		glColor4f(red,green,blue,blend);
	}
	if(value == 36){ 
		blend = 0.6;
		glColor4f(red,green,blue,blend);
	}
	if(value == 37){ //slight transparency
		blend = 0.8;
		glColor4f(red,green,blue,blend);
	}
	if(value == 5){ //no transparency
		blend = 1.0;
		glColor4f(red,green,blue,blend);
	}

	glPointSize(3.0);
	glColor4f(red,green,blue,blend);
	
	glFlush();
	return;
}

void displayPlus(void){

	if(value == 38){
		brightness = 0.0;brightness2 = 0.0;
	}
	if(value == 39){
		brightness = 0.25;brightness2 = 0.0;
	}
  	if(value == 7){
  		brightness = 0.5;brightness2 = 0.0;
  	}
	if(value == 8){
		brightness = 1.0;brightness2 = 0.0;
	}
	if(value == 9){
		brightness = 1.0;brightness2 = 0.25;
	} 
	if(value == 40){
		brightness = 1.0;brightness2 = 0.50;
	} 
	if(value == 41){
		brightness = 1.0;brightness2 = 0.75;
	}
	if(value == 42){
		brightness = 1.0;brightness2 = 1.0;
	} 
	
	if(value == 10){palletred = 1.0;} //red
	if(value == 11){palletred = 0.5;}
	if(value == 12){palletred = 0.0;}
	if(value == 13){palletyellow = 1.0;} //yellow
	if(value == 14){palletyellow = 0.5;}
	if(value == 15){palletyellow = 0.0;}
	if(value == 16){palletgreen = 1.0;} //green
	if(value == 17){palletgreen = 0.5;}
	if(value == 18){palletgreen = 0.0;}
	if(value == 19){palletcyan = 1.0;} //cyan
	if(value == 20){palletcyan = 0.5;}
	if(value == 21){palletcyan = 0.0;}
	if(value == 22){palletblue = 1.0;} //blue
	if(value == 23){palletblue = 0.5;}
	if(value == 24){palletblue = 0.0;}
	if(value == 25){palletpurple = 1.0;} //purple
	if(value == 26){palletpurple = 0.5;}
	if(value == 27){palletpurple = 0.0;}

	glBegin(GL_POLYGON);
	glColor4f(palletred * brightness , brightness2, brightness2, 1.0); //red
    glVertex2f(-0.6 , -0.45); //bottom left
	glColor4f(palletyellow  * brightness, palletyellow  * brightness , brightness2, 1.0); //yellow
    glVertex2f(0.0, -0.9); //bottom middle
	glColor4f(brightness2, palletgreen  * brightness, brightness2, 1.0); //green
    glVertex2f(0.6, -0.45); //bottom right
	glColor4f(brightness2, palletcyan   * brightness, palletcyan   * brightness, 1.0); //teal
    glVertex2f(0.6, 0.45); //right /top
	glColor4f(brightness2, brightness2, palletblue  * brightness, 1.0); //blue
    glVertex2f(0, 0.75); //top middle
	glColor4f(palletpurple  * brightness, brightness2, palletpurple  * brightness, 1.0); //purple
    glVertex2f(-0.6, 0.45); //left /top
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(0, 0, 0, 1.0); 
    glVertex2f(1.0, -1.0); //bottom right
	glColor4f(0, 0, 0, 1.0); 
    glVertex2f(0.9, -1.0); //bottom left
	glColor4f(1, 1, 1, 1.0); 
    glVertex2f(0.9, 1.0); //left /top
	//glColor4f(0, 1, 1); 
    glVertex2f(1.0, 1.0); //right /top
	glEnd();
  	
  	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y){
	static int first=1;


	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		glColor4f(red,green,blue, blend);


		if(value == 27){ 
			polysides3 = 3;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 28){ 
			polysides3 = 4;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 2){ 
			polysides3 = 5;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
						glVertex2f(polysidesx[4],polysidesy[4]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 29){ 
			polysides3 = 6;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
						glVertex2f(polysidesx[4],polysidesy[4]);
						glVertex2f(polysidesx[5],polysidesy[5]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 30){ 
			polysides3 = 7;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
						glVertex2f(polysidesx[4],polysidesy[4]);
						glVertex2f(polysidesx[5],polysidesy[5]);
						glVertex2f(polysidesx[6],polysidesy[6]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 31){ 
			polysides3 = 8;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
						glVertex2f(polysidesx[4],polysidesy[4]);
						glVertex2f(polysidesx[5],polysidesy[5]);
						glVertex2f(polysidesx[6],polysidesy[6]);
						glVertex2f(polysidesx[7],polysidesy[7]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 32){ 
			polysides3 = 9;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
						glVertex2f(polysidesx[4],polysidesy[4]);
						glVertex2f(polysidesx[5],polysidesy[5]);
						glVertex2f(polysidesx[6],polysidesy[6]);
						glVertex2f(polysidesx[7],polysidesy[7]);
						glVertex2f(polysidesx[8],polysidesy[8]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		if(value == 33){ 
			polysides3 = 10;
			if(getpoints == 1 && polysides < polysides3){
				polysidesx[polysides] = x;
				polysidesy[polysides] = hh - y;
				glPointSize(2.0);
				glBegin(GL_POINTS);
					glVertex2f(polysidesx[polysides],polysidesy[polysides]);
				glEnd();
				glFlush();
				polysides++;
				if(polysides >= polysides3){
					getpoints = 0;
					glBegin(GL_POLYGON);
						glVertex2f(polysidesx[0],polysidesy[0]);
						glVertex2f(polysidesx[1],polysidesy[1]);
						glVertex2f(polysidesx[2],polysidesy[2]);
						glVertex2f(polysidesx[3],polysidesy[3]);
						glVertex2f(polysidesx[4],polysidesy[4]);
						glVertex2f(polysidesx[5],polysidesy[5]);
						glVertex2f(polysidesx[6],polysidesy[6]);
						glVertex2f(polysidesx[7],polysidesy[7]);
						glVertex2f(polysidesx[8],polysidesy[8]);
						glVertex2f(polysidesx[9],polysidesy[9]);
					glEnd();
					glFlush();
					getpoints = 1;
					polysides = 0;
				}
			}
		}

		else if(value == 3){ // line
			if (first){
				x1=x; 
				y1=hh-y;

				glPointSize(1.0);
				glBegin(GL_POINTS);
					glVertex2f(x1,y1);
				glEnd();
				glFlush();
			}
			else{
				x2=x;
				y2=hh-y;
				
				glLineWidth(10.0);
				glBegin(GL_LINES);
				glVertex2f(x1, y1);
				glVertex2f(x2, y2);
				glEnd();
				glPointSize(10.0);
				glBegin(GL_POINTS);
					glVertex2f((x-250.0)/250.0,-(y-250.0)/250.0);
				glEnd();

				glFlush();
			}
			first = !first;
		}
		
	}
	
	if(value == 4){ //high transparency
		x1=x; 
		y1=hh-y;

		glPointSize(5.0);
		glBegin(GL_POINTS);
		glVertex2f(x1,y1);
		glEnd();
		glFlush();
	}
	return;
}

void MyMousePlus(GLint x, GLint y){
	if (x > 125 && x < 375 && y > 125 && y < 375)
		glColor4f(0.0,1.0,0.0,1.0);
	else
		glColor4f(1.0,0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(-1.0,1.0);
		glVertex2f(-1.0,0.9);
		glVertex2f(0.9,0.3);
		glVertex2f(0.9,-0.3);
	glEnd();
	glFlush();	
	return;
}
void MyMouse2(GLint x, GLint y){
	glColor4f(red,green,blue,blend);
	glPointSize(10.0);
	glBegin(GL_POINTS);
		glVertex2f((x-250.0)/250.0,-(y-250.0)/250.0);
	glEnd();
	glFlush();	
	return;
}
void colorchooser(GLfloat tmpf, GLint tmpx){
	if(tmpx > 350 && tmpx < 400){
		red = tmpf;
	}
	else if(tmpx > 400 && tmpx < 450){
		green = tmpf;
	}
	else if(tmpx > 450){
		blue = tmpf;
	}
}
void MyMouse3(GLint button, GLint state, GLint x, GLint y){
	static int first=1;
	GLfloat colorchoice;
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		glReadPixels(x, 500 - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE , &pixel_color[0]);
		red = (float)pixel_color[0]/255.0;
		green = (float)pixel_color[1]/255.0;
		blue = (float)pixel_color[2]/255.0;

		glColor4f(red,green,blue,blend);
		//SDL_GL_SwapBuffers()
		glBegin(GL_POLYGON);
			glVertex2f(-0.9,0.9); //top left
			glVertex2f(-0.9,0.8); //bottom left
			glVertex2f(-0.8,0.8); //bottom right
			glVertex2f(-0.8,0.9); //top right
		glEnd();
		glFlush();	
	}
	return;
}
void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);
	glViewport(0,0,w,h);
	hh=h;
	return;
}
int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(800,200);
	glutCreateWindow("mouse");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(display);
	glutMouseFunc(MyMouse);
	glutReshapeFunc(MyReshape);
	createMenu();

	glutInitWindowPosition(200,200); //0,0 means top left corner, 1st one is Left->Right , 2nd one is Top->Bottom 
	glutCreateWindow("mouse2");
	glutDisplayFunc(displayPlus);
	glutMouseFunc(MyMouse3);
	createMenu2();
	
	glutMainLoop();
}