#include "appHeader.h"

int
main(int argc, char** argv)
{
	initTime();
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (900, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Solar System 3D");
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutCreateMenu(appMenuHandler);
	glutAddMenuEntry("Camera 1",0);
	glutAddMenuEntry("Camera 2",1);
	glutAddMenuEntry("Camera 3",2);
	glutAddMenuEntry("Camera 4",3);
	glutAddMenuEntry("Camera 5",4);
	glutAddMenuEntry("Solar Syatem Simulator",5);
	glutAddMenuEntry("Sun - Earth - Moon System",6);
	glutAddMenuEntry("Earth - Mars - MSL System",7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(appKeyHandler);
	glutSpecialFunc(appSKeyHandler);
	glutDisplayFunc(display);
	glutReshapeFunc(appReshape);
	glutIdleFunc(appAnimate);
	glutFullScreen();
	glutMainLoop();
	return 0;
}