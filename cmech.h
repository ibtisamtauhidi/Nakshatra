void
plotBody(int id) {
	float timeDiff = currentTime - epoch[id];
	if(timeDiff<0) timeDiff-=orbitPeriod[id];	
	float i = ((2*PI)/orbitPeriod[id])*timeDiff;
	i= (2*PI)-i;
	float circumference = 2*PI;
	float a = aphelion[id]/10;
	float e = eccentricity[id];
	float r = (a*(1-(e*e)))/(1-(e*cos(i)));
	float x = r*cos(i);
	float y = r*sin(i);
	float z = 0;
	glPushMatrix();
    glTranslatef (x, y, z);
    glColor3f(bodyColorR[id],bodyColorG[id],bodyColorB[id]);
    glutSolidSphere(bodyRadii[id],90,90);
    glPopMatrix();
	glRasterPos3f(x+0.1,y+0.9,z);
	int len = (int) strlen(bodyName[id]);
	if(!((id<5)&&(cameraR<-150))){
	for (int i = 0; i < len; i++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,bodyName[id][i]);
	}    }
	glFlush();
}
void
plotOrbit(int id) {
	if(!((id<5)&&(cameraR<-700))){
	    glColor3f(bodyColorR[id],bodyColorG[id],bodyColorB[id]);
		glBegin(GL_LINE_LOOP);
		float circumference = 2*PI;
		float a = aphelion[id]/10;
		float e = eccentricity[id];
		for(float i=0.0;i<circumference;i+=0.01) {
			float r = (a*(1-(e*e)))/(1-(e*cos(i)));
			float x = r*cos(i);
			float y = r*sin(i);
			float z = 0;
			glVertex3f (x, y, z);
		}
		glEnd();
		glFlush();
	}
}
void
plotSun(void) {
    glPushMatrix();
	    glColor3f (1.0, 0.1, 0.0);
        glutSolidSphere(2.0,90,90);
        glRotatef((GLfloat) 5, 0.0, 1.0, 0.0);
    glPopMatrix();
    glFlush();
}
void
plotMoon(void) {
	float timeDiff = currentTime - epoch[3];
	if(timeDiff<0) timeDiff-=orbitPeriod[3];	
	float i = ((2*PI)/orbitPeriod[3])*timeDiff;
	i= (2*PI)-i;
	float circumference = 2*PI;
	float a = aphelion[3]/10;
	float e = eccentricity[3];
	float r = (a*(1-(e*e)))/(1-(e*cos(i)));
	float x = r*cos(i);
	float y = r*sin(i);
	float z = 0;

    glTranslatef (x, y, z);
	glPushMatrix();
	glRotatef(5.7,1,0,0);
	glColor3f (0.7, 0.7, 0.7);
	glBegin(GL_LINE_LOOP);
	a = 3;
	e = 0.05;
	for(float i=0.0;i<circumference;i+=0.01) {
		r = (a*(1-(e*e)))/(1-(e*cos(i)));
		x = r*cos(i);
		y = r*sin(i);
		z = 0;
		glVertex3f (x, y, z);
	}
	glEnd();
	glColor3f (1.0, 1.0, 1.0);
	timeDiff = currentTime - 13922899.58;
	if(timeDiff<0) timeDiff-=42588.0;	
	i = ((2*PI)/42588.0)*timeDiff;
	i= (2*PI)-i;
	r = (a*(1-(e*e)))/(1-(e*cos(i)));
	x = r*cos(i);
	y = r*sin(i);
	z = 0;
	glTranslatef (x, y, z);
    glutSolidSphere(0.3,90,90);
	glRasterPos3f(x+0.01,y,z);
	char name[] = "Moon";
	int len = (int) strlen(name);
	for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,name[i]);
	glPopMatrix();
}
void
plotMSL(void) {
	if((currentTime>=22038737.45)&&(currentTime<22404518.16)) {			
		float timeDiff = currentTime - 22038737.45;
		float i= 3.564756-(5.124026*(timeDiff/365780.71));
		float a = 15.21+(9.71*(timeDiff/365780.71));
		float e = 0.017+(0.077*(timeDiff/365780.71));
		float r = (a*(1-(e*e)))/(1-(e*cos(i)));
		float x = r*cos(i);
		float y = r*sin(i);
		float z = 0;
		glPushMatrix();
		glRotatef(ZInclination[4]*(timeDiff/365780.71),1,0,0);
		glTranslatef (x,y,z);
		glutSolidSphere(0.15,90,90);
		glColor3f (1.0, 1.0, 0.0);
		glRasterPos3f(0.5,0.5,0.5);
		char name[] = "MSL";
		int len = (int) strlen(name);
		for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,name[i]);
		glPopMatrix();
	}
}
void
plotStarMap(void) {
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0,0.0,2500);
	glutSolidSphere(8.0,90,90);
	glRasterPos3f(30.0,-60.0,0.0);
	char namePolaris[] = "Polaris";
	int len = (int) strlen(namePolaris);
	for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,namePolaris[i]);
	glBegin(GL_LINE_STRIP);
	glVertex3i(-50.0,50.0,0.0);
	glVertex3i(-90.0,150.0,0.0);
	glVertex3i(-200.0,130.0,0.0);
	glVertex3i(-210.0,60.0,0.0);
	glVertex3i(-280.0,30.0,0.0);
	glVertex3i(-310.0,0.0,0.0);
	glVertex3i(-400.0,50.0,0.0);
	glEnd();
	glRasterPos3f(-500.0,100.0,0.0);
	char nameBD0[] = "Saptarshi / Big Dipper";
	len = (int) strlen(nameBD0);
	for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,nameBD0[i]);

	/*
	glRasterPos3f(-500.0,150.0,0.0);
	char nameBD1[] = "Big Dipper";
	len = (int) strlen(nameBD1);
	for (int i = 0; i < len; i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,nameBD1[i]);
	*/
	glPopMatrix();
}