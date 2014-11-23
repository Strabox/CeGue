#ifndef ROADSIDE_H
#define ROADSIDE_H

#include "glut.h"
#include "SOIL.h"
#include "StaticObject.h"

class Roadside : public StaticObject {

public:

	Roadside() :StaticObject(Box(-6.0,6.0,-0.5,0.2)){}

	~Roadside(){}

	int answerToColision(){ return 4; }			// 4 = ground

	int loadSelfTexture(){
		textureID = SOIL_load_OGL_texture(
			"Roadside.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
			);
		if (0 == textureID)
		{
			printf("SOIL loading error: '%s'\n", SOIL_last_result());
		}
		printf("Texture loaded - Roadside\n");
		return 1;
	}

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.0, 0.01, 0.0, 1.0 };
		GLfloat mat_ambient[] = { 0.2, 0.5, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.2, 0.5, 0.0, 1.0 };
		GLfloat shininess = 10;

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureID);

		double tile_width = 0.25;
		for (double y = -0.5 + tile_width / 2.0; y <= 0.5 - tile_width / 2.0; y += tile_width){
			for (double x = -5.5 + tile_width / 2.0; x <= 5.5 - tile_width / 2.0; x += tile_width){
				glPushMatrix();
				glTranslatef(x, y, 0.0);
				glColor3f(0.0, 0.5, 0.0);

				glBegin(GL_QUADS);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0.1, 0.1);
				glVertex3f(-tile_width / 2.0, -tile_width / 2.0, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0.9, 0.1);
				glVertex3f(tile_width / 2.0, -tile_width / 2.0, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0.9, 0.9);
				glVertex3f(tile_width / 2.0, tile_width / 2.0, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0.1, 0.9);
				glVertex3f(-tile_width / 2.0, tile_width / 2.0, 0.5);
				glEnd();
				glPopMatrix();
			}
		}
		for (double z = -0.5 + tile_width / 2.0; z <= 0.5 - tile_width / 2.0; z += tile_width){
			for (double x = -5.5 + tile_width/ 2.0; x <= 5.5 - tile_width / 2.0; x += tile_width){
				glPushMatrix();
				glTranslatef(x, 0.0, z);
				glColor3f(0.0, 0.5, 0.0);

				glBegin(GL_QUADS);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(0.1, 0.1);
				glVertex3f(-tile_width / 2.0, -0.5, -tile_width / 2.0);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(0.9, 0.1);
				glVertex3f(tile_width / 2.0, -0.5, -tile_width / 2.0);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(0.9, 0.9);
				glVertex3f(tile_width / 2.0, -0.5, tile_width / 2.0);
				glNormal3f(0.0, -1.0, 1.0);
				glTexCoord2f(0.1, 0.9);
				glVertex3f(-tile_width / 2.0, -0.5, tile_width / 2.0);
				glEnd();
				glPopMatrix();
			}
		}
		for (double z = -0.5 + tile_width / 2.0; z <= 0.5 - tile_width / 2.0; z += tile_width){
			for (double x = -5.5 + tile_width / 2.0; x <= 5.5 - tile_width / 2.0; x += tile_width){
				glPushMatrix();
				glTranslatef(x, 0.0, z);
				glColor3f(0.0, 0.5, 0.0);

				glBegin(GL_QUADS);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(0.1, 0.1);
				glVertex3f(tile_width / 2.0, 0.5, -tile_width / 2.0);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(0.9, 0.1);
				glVertex3f(-tile_width / 2.0, 0.5, -tile_width / 2.0);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(0.9, 0.9);
				glVertex3f(-tile_width / 2.0, 0.5, tile_width / 2.0);
				glNormal3f(0.0, 1.0, 1.0);
				glTexCoord2f(0.1, 0.9);
				glVertex3f(tile_width / 2.0, 0.5, tile_width / 2.0);
				glEnd();
				glPopMatrix();
			}
		}

		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}

};

#endif