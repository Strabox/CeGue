#ifndef ROAD_H
#define ROAD_H

#include "glut.h"
#include "SOIL.h"
#include "StaticObject.h"

class Road : public StaticObject {

public:

	Road() :StaticObject(Box(-6.0, 6.0, -2.5, 2.5)){}

	~Road(){}

	int answerToColision(){ return 4; }				// 4 = ground

	int loadSelfTexture(){
		textureID = SOIL_load_OGL_texture(
			"Road.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
			);
		if (0 == textureID)
		{
			printf("SOIL loading error: '%s'\n", SOIL_last_result());
		}
		printf("Texture loaded - Road\n");
		return 1;
	}

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
		GLfloat shininess = 100;

		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		
		glPushMatrix();
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureID);

		double tile_width = 0.25;
		double texymin, texymax, texxmin, texxmax;
		for (double y = -2.5 + tile_width / 2.0; y <= 2.5 - tile_width / 2.0; y += tile_width){
			for (double x = -5.5 + tile_width / 2.0; x <= 5.5 - tile_width / 2.0; x += tile_width){
				glPushMatrix();
				glTranslatef(x, y, 0.0);
				glColor3f(0.5, 0.5, 0.5);

				texymin = (y - tile_width / 2.0 + 2.5)/5.0;
				texymax = (y + tile_width / 2.0 + 2.5) / 5.0;
				texxmin = (x - tile_width / 2.0 + 5.5) / 11.0;
				texxmax = (x + tile_width / 2.0 + 5.5) / 11.0;

				glBegin(GL_QUADS);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(texxmin, texymin);
				glVertex3f(-tile_width / 2.0, -tile_width / 2.0, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(texxmax, texymin);
				glVertex3f(tile_width / 2.0, -tile_width / 2.0, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(texxmax, texymax);
				glVertex3f(tile_width / 2.0, tile_width / 2.0, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(texxmin, texymax);
				glVertex3f(-tile_width / 2.0, tile_width / 2.0, 0.5);
				glEnd();
				glPopMatrix();
			}
		}
		
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}

};

#endif