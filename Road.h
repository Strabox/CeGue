#ifndef ROAD_H
#define ROAD_H

#include "glut.h"
#include "StaticObject.h"

class Road : public StaticObject {

public:

	Road() :StaticObject(Box(-6.0, 6.0, -2.5, 2.5)){
		FILE *fileptr;
		long filelen;

		fopen_s(&fileptr,"tex_road_big.bmp", "rb");  // Open the file in binary mode
		fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
		filelen = ftell(fileptr);             // Get the current byte offset in the file
		rewind(fileptr);                      // Jump back to the beginning of the file

		texels = (char *)malloc((filelen + 1)*sizeof(char)); // Enough memory for file + \0
		fread(texels, filelen, 1, fileptr); // Read in the entire file
		printf("%d\n%s\n", sizeof(texels), (char*)texels);
		fclose(fileptr);
		giveTextureID(1);
	}

	~Road(){}

	int answerToColision(){ return 4; }				// 4 = ground

	int giveTextureID(GLint id){
		textureID = 1;//id;
		glBindTexture(GL_TEXTURE_2D, textureID);
		
		return 0;
	}

	void draw(){
		Vector3 vector = getPosition();
		GLfloat mat_specular[] = { 0.1, 0.1, 0.1, 1.0 };
		GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat mat_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat shininess = 100;

		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);
		//printf("%d\n%s\n", sizeof(texels), (char*)texels);

		glPushMatrix();
		glTranslatef(vector.getX(), vector.getY(), vector.getZ());

		for (double y = -2.25; y <= 2.25; y+=0.5){
			for (double x = -5.25; x <= 5.25; x+=0.5){
				glPushMatrix();
				glTranslatef(x, y, 0.0);
				//glScalef(0.5, 0.5, 1.0);
				glColor3f(0.1, 0.1, 0.1);
				/*
				glTexCoord(x, y);
				glVertex(...
				Desenhar quadrado
				http://neerci.ist.utl.pt/~neerci.daemon/neerci_shelf/LEIC/3%20Ano/1%20Semestre/Computacao%20Grafica/Teoricas%20e%20Resumos/2012%20-%202013/19%20-%20Mapeamento%20de%20Texturas.pdf
				*/
				glBegin(GL_QUADS);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0, 0);
				glVertex3f(-0.25, -0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(1, 0);
				glVertex3f(0.25, -0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(1, 1);
				glVertex3f(0.25, 0.25, 0.5);
				glNormal3f(0.0, 0.0, 1.0);
				glTexCoord2f(0, 1);
				glVertex3f(-0.25, 0.25, 0.5);
				glEnd();
				glPopMatrix();
			}
		}

		glPopMatrix();
	}

};

#endif