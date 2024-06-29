#include <process.h>
#include <math.h>
#include <stdio.h>
#include <glut.h>

GLdouble drawH = 300, drawW = 300;


float X = 0; float Y = 0;



void specialKey(int  key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: //when the UP key pressed
		if (Y < 275) {
			if ((X > -275 && X < 150 && Y==175)|| (X > -300 && X < 25 && Y == -275))
			{


			}
			else
			{
				Y = Y + 5;
			}
		}
		
		


		break;

	case GLUT_KEY_DOWN:
		if (Y > -275) {
			if ((X > -300 && X < 25 && Y == -25) || (X > -275 && X < 275 && Y == 275)) {
			
			}
			else {
				Y = Y - 5;
			}
		}


		break;


	case GLUT_KEY_RIGHT: //when the UP key pressed
		if (X < 275) {
			if ((X == 125 && Y < 275) ||( Y<275&&Y>175)) {
				
			}
			else {
				X = X + 5;
			}
		}


		break;

	case GLUT_KEY_LEFT:
		if (X > -275) {
			if ((Y > -300 && Y < 275 && X>250)|| (Y > -275 && Y < -25 && X==25))
			{

			}
			else {
			X = X - 5;
			}

			

			}
			
				
			
		

		


	}
	
	
	

	glutPostRedisplay();


}

void endgame() {
	if (X == 275 && Y == -275) {
		printf("You won");
		exit(1);
	}
}






void display()
{
	glClear(GL_COLOR_BUFFER_BIT);;
	glColor3f(1, 0, 0);
	glRectf(-25+X, 25+Y, 25+X, -25+Y); // moving object
	endgame();
	glColor3f(0.51, 0.22, 0.01);
	glRectf(-300 , -250 , 0, -50); // bottom rec
	glRectf(250, -300, 150, 250);  //right rec
	glRectf(150, 250, -250, 200);  // top rec
	glColor3f(0.18, 0.88, 0.03);
	glRectf(300, -300, 250, -250);  // green square for the win

	
	glFlush();


}
void reshape(int width, int height)
{
	// set the coordinates and size of the viewing area on the window
	glViewport(0, 0, width, height);

	// Start modifying the projection matrix.
	glMatrixMode(GL_PROJECTION);

	// Reset the matrix
	glLoadIdentity();

	// set the displayed area 
	float ratio = (float)width / height; //aspect ratio
	if (width > height)

	{
		glOrtho(-drawW * ratio, drawW * ratio, -drawH, drawH, -1, 1);
	}
	else
	{
		glOrtho(-drawW, drawW, -drawH / ratio, drawH / ratio, -1, 1);
	}
	glClearColor(0.13, 0.52, 0.42, 1.0);

}
int main(int argc, char* argv[]) {

	//Initialize GLUT using program arguments (if any)
	glutInit(&argc, argv);

	//set initial window size
	glutInitWindowSize(600, 600);

	//create a GLUT window and set its title
	glutCreateWindow("Maze");

	//Attach callback finctions
	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutSpecialFunc(specialKey);

	glutMainLoop();

	return 0;
}