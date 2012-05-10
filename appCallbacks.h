void
appKeyHandler(unsigned char key, int x, int y) {
	switch (key) {
		case 'w':
			cameraR+=5;
			glutPostRedisplay();
			break;
		case 's':
			cameraR-=5;
			glutPostRedisplay();
			break;
		case 'a':
			cameraZ+=5;
			glutPostRedisplay();
			break;
		case 'd':
			cameraZ-=5;
			glutPostRedisplay();
			break;
		case '1':
			cameraR=-50;
			cameraX=0;
			cameraY=0;
			cameraZ=0;
			glutPostRedisplay();
			break;
		case '2':
			cameraR=-1500;
			cameraX=0;
			cameraY=0;
			cameraZ=0;
			glutPostRedisplay();
			break;
		case '3':
			cameraR=-50;
			cameraX=60;
			cameraY=-15;
			cameraZ=-60;
			glutPostRedisplay();
			break;
		case '4':
			cameraR=-500;
			cameraX=60;
			cameraY=-15;
			cameraZ=-60;
			glutPostRedisplay();
			break;
		case '5':
			cameraR=-2000;
			cameraX=60;
			cameraY=15;
			cameraZ=-60;
			glutPostRedisplay();
			break;
		case 'p':
			if(timeON==1) timeON=0;
			else timeON=1;
			glutPostRedisplay();
			break;
		case 'c':
			timeRate = 0;
			fastForward = 0;
			initTime();
			glutPostRedisplay();
			break;
		case 'm':
			if(timeRate<9) {
				timeRate++;
				fastForward = 1;
				incrTime();
			}
			glutPostRedisplay();
			break;
		case 'n':
			if(timeRate>-9) {
				timeRate--;
				fastForward = 1;
				incrTime();
			}
			glutPostRedisplay();
			break;
		case 27:
			if(nowPlaying!= 0) {
				nowPlaying = 0;
			} else exit(0);
			glutPostRedisplay();
			break;
		case 32:
			timeRate=0;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}
void
appSKeyHandler(int key,int x,int y) {
	switch(key) {
		case GLUT_KEY_UP:
			cameraX+=3;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			cameraX-=3;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			cameraY+=5;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			cameraY-=5;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F1:
			timeON = 0;
			cameraR=-50;
			cameraX=0;
			cameraY=0;
			cameraZ=0;
			nowPlaying = 1;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F2:
			timeON = 0;
			cameraR=-50;
			cameraX=60;
			cameraY=-15;
			cameraZ=-60;
			nowPlaying = 2;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F3:
			currentTime = 22038737.45;
			timeON = 1;
			fastForward=1;
			timeRate=0;
			cameraR=-50;
			cameraX=0;
			cameraY=0;
			cameraZ=0;
			nowPlaying = 3;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F11:
			if(fullScreenON==1) {
				glutFullScreen();
				fullScreenON=0;
			} else {
				glutReshapeWindow(900, 600);	
				fullScreenON=1;
			}
			break;
	}
}
void
display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(nowPlaying==0) {
	    glColor3f (0.5, 0.5, 0.5);	
		glBegin(GL_POLYGON);
			glVertex3i(-55,50,0);
			glVertex3i(55,50,0);
			glVertex3i(55,22,0);
			glVertex3i(-55,22,0);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glRasterPos3f(-5.0,25.0,0.0);
		char string1[] = "N A K S H A T R A";
		int len = (int) strlen(string1);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string1[i]);
		glColor3f(1.0,1.0,1.0);
		glRasterPos3f(-7.5,23.5,0.0);
		char string2[] = "space - time simulator suite";
		len = (int) strlen(string2);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string2[i]);

		glColor3f (1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex3i(-16,20,0);
			glVertex3i(16,20,0);
			glVertex3i(16,17,0);
			glVertex3i(-16,17,0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3i(-16,16,0);
			glVertex3i(16,16,0);
			glVertex3i(16,13,0);
			glVertex3i(-16,13,0);
		glEnd();
		glBegin(GL_POLYGON);
			glVertex3i(-16,12,0);
			glVertex3i(16,12,0);
			glVertex3i(16,9,0);
			glVertex3i(-16,9,0);
		glEnd();

		glColor3f (1.0, 0.01, 0.01);
		glRasterPos3f(-8.5,18.0,0.0);
		char string3[] = "F1: The Sun and its Planets";
		len = (int) strlen(string3);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string3[i]);
		glRasterPos3f(-10.5,14,0.0);
		char string4[] = "F2: Sun - Earth - Moon System";
		len = (int) strlen(string4);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string4[i]);
		glRasterPos3f(-9.5,10.0,0.0);
		char string5[] = "F3: MSL Trajectory Simulator";
		len = (int) strlen(string5);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string5[i]);

		glColor3f (0.0, 1.0, 0.0);
		glBegin(GL_LINES);
			glVertex3f(-41.5,4.0,0.0);
			glVertex3f(41.5,4.0,0.0);
		glEnd();

		glColor3f (0.0, 1.0, 1.0);
		glRasterPos3f(-41.5,1.0,0.0);
		char string6[] = "UP / DOWN : Move Up / Down";
		len = (int) strlen(string6);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string6[i]);
		glRasterPos3f(-41.5,-1.0,0.0);
		char string7[] = "LEFT / RIGHT : Tilt Left / Right";
		len = (int) strlen(string7);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string7[i]);
		glRasterPos3f(-41.5,-3.0,0.0);
		char string8[] = "A / D : Move Left / Right";
		len = (int) strlen(string8);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string8[i]);
		glRasterPos3f(-41.5,-5.0,0.0);
		char string9[] = "W / S : Zoom In / Out";
		len = (int) strlen(string9);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string9[i]);
		glRasterPos3f(-41.5,-7.0,0.0);
		char string20[] = "M : Increase Time Rate";
		len = (int) strlen(string20);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string20[i]);
		glRasterPos3f(-41.5,-9.0,0.0);
		char string21[] = "N : Decrease Time Rate";
		len = (int) strlen(string21);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string21[i]);
		glRasterPos3f(-41.5,-11.0,0.0);
		char string22[] = "SPACE : Pause";
		len = (int) strlen(string22);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string22[i]);
		glRasterPos3f(-41.5,-13.0,0.0);
		char string10[] = "C : Reset Time";
		len = (int) strlen(string10);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string10[i]);
		glRasterPos3f(-41.5,-15.0,0.0);
		char string11[] = "1 - 5 : Predefined Cameras";
		len = (int) strlen(string11);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string11[i]);
		glRasterPos3f(-41.5,-17.0,0.0);
		char string12[] = "ESC : Home / Exit";
		len = (int) strlen(string12);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string12[i]);
		glRasterPos3f(-41.5,-19.0,0.0);
		char string23[] = "F11 : Turn On / Off Full Screen";
		len = (int) strlen(string23);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string23[i]);
		glRasterPos3f(-41.5,-19.0,0.0);

		glRasterPos3f(25.0,1.0,0.0);
		char string17[] = "Submitted by -";
		len = (int) strlen(string17);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string17[i]);
		glRasterPos3f(27.5,-1.0,0.0);
		char string18[] = "Syed I. Tauhidi";
		len = (int) strlen(string18);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string18[i]);
		glRasterPos3f(27.5,-3.0,0.0);
		char string19[] = "Manoj Panith";
		len = (int) strlen(string19);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string19[i]);
		glRasterPos3f(25.0,-7.0,0.0);
		char string14[] = "Under guidance of -";
		len = (int) strlen(string14);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string14[i]);
		glRasterPos3f(27.5,-9.0,0.0);
		char string15[] = "Madhubala ma'am";
		len = (int) strlen(string15);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string15[i]);
		glRasterPos3f(27.5,-11.0,0.0);
		char string16[] = "Madhura ma'am";
		len = (int) strlen(string16);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string16[i]);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef (0.0, 0.0, -50);
		glRotatef((GLfloat) 0, -1.0, 0.0, 0.0);
		glRotatef((GLfloat) 0, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
		glFlush();
		glutSwapBuffers();
	} else if(nowPlaying==1) {
		plotStarMap();
		for (int i=9;i>0;i--) {
			glPushMatrix();
			glRotatef((GLfloat) ZInclination[i], -1.0, 0.0, 0.0);
			plotOrbit(i);
			plotBody(i);
			glPopMatrix();
		}
		plotSun(); 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef (0.0, 0.0, cameraR);
		glRotatef((GLfloat) cameraX, -1.0, 0.0, 0.0);
		glRotatef((GLfloat) cameraY, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) cameraZ, 0.0, 0.0, 1.0);
		if(timeON==1) {
				glColor3f(1.0,1.0,1.0);
				int p=sin(cameraX);
				int r=sin(cameraY);
				int t=sin(cameraZ);
				glRasterPos3f((cameraR/2)*p,(cameraR/2)*r,(cameraR/2)*t);
				int len = (int) strlen(currentTimeString);
				for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,currentTimeString[i]); 
		}
		glFlush();
		glutSwapBuffers();
	} else if(nowPlaying==2) {
		plotOrbit(3);
		plotBody(3);
		plotSun(); 
		plotMoon();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef (0.0, 0.0, cameraR);
		glRotatef((GLfloat) cameraX, -1.0, 0.0, 0.0);
		glRotatef((GLfloat) cameraY, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) cameraZ, 0.0, 0.0, 1.0);
		if(timeON==1) {
				glColor3f(1.0,1.0,1.0);
				int p=sin(cameraX);
				int r=sin(cameraY);
				int t=sin(cameraZ);
				glRasterPos3f((cameraR/2)*p,(cameraR/2)*r,(cameraR/2)*t);
				int len = (int) strlen(currentTimeString);
				for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,currentTimeString[i]); 
		}
		glFlush();
		glutSwapBuffers();
	} else if(nowPlaying==3) {
		plotOrbit(3);
		plotBody(3);
		glPushMatrix();
		glRotatef(ZInclination[4],1,0,0);
		plotOrbit(4);
		plotBody(4);
		glPopMatrix();
		plotSun();
		plotMSL();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef (0.0, 0.0, cameraR);
		glRotatef((GLfloat) cameraX, -1.0, 0.0, 0.0);
		glRotatef((GLfloat) cameraY, 0.0, 1.0, 0.0);
		glRotatef((GLfloat) cameraZ, 0.0, 0.0, 1.0);
		if(timeON==1) {
				glColor3f(1.0,1.0,1.0);
				int p=sin(cameraX);
				int r=sin(cameraY);
				int t=sin(cameraZ);
				glRasterPos3f((cameraR/2)*p,(cameraR/2)*r,(cameraR/2)*t);
				int len = (int) strlen(currentTimeString);
				for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,currentTimeString[i]); 
		}
		glFlush();
		glutSwapBuffers();
	}
}
void
appReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 5000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, cameraR);
    glRotatef((GLfloat) cameraX, -1.0, 0.0, 0.0);
    glRotatef((GLfloat) cameraY, 0.0, 1.0, 0.0);
    glRotatef((GLfloat) cameraZ, 0.0, 0.0, 1.0);
}
void
appAnimate() {
	incrTime();
	glutPostRedisplay();
}
void
appMenuHandler(int key) {
	switch(key){
		case 0:
			appKeyHandler('1',0,0);
			break;
		case 1:
			appKeyHandler('2',0,0);
			break;
		case 2:
			appKeyHandler('3',0,0);
			break;
		case 3:
			appKeyHandler('4',0,0);
			break;
		case 4:
			appKeyHandler('5',0,0);
			break;
		case 5:
			appSKeyHandler(GLUT_KEY_F1,0,0);
			break;
		case 6:
			appSKeyHandler(GLUT_KEY_F2,0,0);
			break;
		case 7:
			appSKeyHandler(GLUT_KEY_F3,0,0);
			break;
		default:
			break;
	}
}