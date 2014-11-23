#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include "glut.h"
#include "SOIL.h"
#include "GameObject.h"

class PauseWindow : public Entity {

public:

	PauseWindow(){}

	~PauseWindow(){}

	int loadSelfTexture(){
		textureID = SOIL_load_OGL_texture(
			"PauseWindow.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
			);
		if (0 == textureID)
		{
			printf("SOIL loading error: '%s'\n", SOIL_last_result());
		}
		return 1;
	}

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 1.0, 1.0, 0.5, 1.0 };
		GLfloat mat_ambient[] = { 1.0, 1.0, 0.5, 1.0 };
		GLfloat shininess = 0;

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);

		glPushMatrix();
			glTranslatef(vector.getX(), vector.getY(), vector.getZ());
			glColor3f(1.0, 1.0, 0.5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3d(-2, -2, 0);
			glTexCoord2f(1, 0);
			glVertex3d(2, -2, 0);
			glTexCoord2f(1, 1);
			glVertex3d(2, 2, 0);
			glTexCoord2f(0, 1);
			glVertex3d(-2, 2, 0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
};

#endif