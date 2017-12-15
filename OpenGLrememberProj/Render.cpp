#include "Render.h"

#include <windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#include "MyOGL.h"
#include "Camera.h"
#include "Light.h"
#include "Primitives.h"


double i = 0, ugol = 0, vx0=10, vy0=10, vz0=0.5, vx=0, vy=0, vz=0, kx=50, ky=-70, kz, kx2 = 40, ky2 = 150, kz2 = 0, kx3 = -110, ky3 = -90, kz3 = 0;
bool textureMode = true;
double time = 0;
bool lightMode = true;
int person1=1, person2= 0, person3= 0, t=0, flag = 0, flag2 = 0,flag3=0,  L2_flag = 0,L2_flag2 = 0,L2_flag3 = 0;

GLuint texId1, texId2, texId3, texId4;	// Место для двух текстур


//класс для настройки камеры
class CustomCamera : public Camera
{
public:
	//дистанция камеры
	double camDist;
	//углы поворота камеры
	double fi1, fi2;

	
	//значния масеры по умолчанию
	CustomCamera()
	{
		camDist = 600;
		fi1 = -acos(-1)/2;
		fi2 = acos(-1)/2;
	}

	
	//считает позицию камеры, исходя из углов поворота, вызывается движком
	void SetUpCamera()
	{
		//отвечает за поворот камеры мышкой

		lookPoint.setCoords(vx, vy, vz);

		/*pos.setCoords(camDist*cos(fi2)*cos(fi1),
		camDist*cos(fi2)*sin(fi1),
		camDist*sin(fi2));*/

		pos.setCoords(vx + camDist*cos(fi2)*cos(fi1),
			vy + camDist*cos(fi2)*sin(fi1),
		vz + camDist*sin(fi2));

		if (cos(fi2) <= 0)
			normal.setCoords(0, 0, -1);
		else
			normal.setCoords(0, 0, 1);


		LookAt();
	}

	void CustomCamera::LookAt()
	{
		//функция настройки камеры
		gluLookAt(pos.X(), pos.Y(), pos.Z(), lookPoint.X(), lookPoint.Y(), lookPoint.Z(), normal.X(), normal.Y(), normal.Z());
	}

void speed()
	{
	
	
	}

}  camera;   //создаем объект камеры




void setNormal(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {

	double ax, ay, az, bx, by, bz, Nx, Ny, Nz;
	ax = x1 - x2;
	bx = x3 - x2;
	ay = y1 - y2;
	by = y3 - y2;
	az = z1 - z2;
	bz = z3 - z1;

	Nx = ay*bz - by*az;
	Ny = 0 - ax*bz - bx*az;
	Nz = ax*by - bx*ay;

	glNormal3d(Nx, Ny, Nz);
}
void obr_setNormal(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {

	double ax, ay, az, bx, by, bz, Nx, Ny, Nz;
	ax = x1 - x2;
	bx = x3 - x2;
	ay = y1 - y2;
	by = y3 - y2;
	az = z1 - z2;
	bz = z3 - z1;

	Nx = ay*bz - by*az;
	Ny = 0 - ax*bz - bx*az;
	Nz = ax*by - bx*ay;

	glNormal3d(-Nx, -Ny, -Nz);
}
void cube() {
	glBegin(GL_QUADS);
	glColor3d(0.7, 0.6, 0.9);
	glNormal3d(0, 0, 1);
	//кубик	
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 20);//верх
	glTexCoord2d(1, 0.807); glVertex3d(0, 20, 20);
	glTexCoord2d(1, 0.629); ; glVertex3d(20, 20, 20);
	glTexCoord2d(0.820, 0.629); glVertex3d(20, 0, 20);

	glNormal3d(0, 0,-1);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 0);//низ
	glTexCoord2d(1, 0.807); glVertex3d(0, 20, 0);
	glTexCoord2d(1, 0.629);   glVertex3d(20, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(20, 0, 0);
	glNormal3d(-1, 0, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 20);
	glTexCoord2d(1, 0.807); glVertex3d(0, 20, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(0, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(0, 0, 0);
	glNormal3d(1, 0, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(20, 0, 20);
	glTexCoord2d(1, 0.807); glVertex3d(20, 20, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(20, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(20, 0, 0);
	glNormal3d(0, -1, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 20);
	glTexCoord2d(1, 0.807); glVertex3d(20, 0, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(20, 0, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(0, 0, 0);
	glNormal3d(0, 1, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 20, 20);
	glTexCoord2d(1, 0.807); glVertex3d(20, 20, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(20, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(0, 20, 0);

	glEnd();
}


void cube2() {
	glBegin(GL_QUADS);
	glColor3d(0.7, 0.6, 0.9);
	//кубик	
	glNormal3d(0, 0, 1);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 20);//верх
	glTexCoord2d(1, 0.807); glVertex3d(0, 20, 20);
	glTexCoord2d(1, 0.629); ; glVertex3d(20, 20, 20);
	glTexCoord2d(0.820, 0.629); glVertex3d(20, 0, 20);
	glNormal3d(0, 0, -1);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 0);//низ
	glTexCoord2d(1, 0.807); glVertex3d(0, 20, 0);
	glTexCoord2d(1, 0.629);   glVertex3d(20, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(20, 0, 0);
	glNormal3d(-1, 0, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 20);
	glTexCoord2d(1, 0.807); glVertex3d(0, 20, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(0, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(0, 0, 0);
	glNormal3d(1, 0, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(20, 0, 20);
	glTexCoord2d(1, 0.807); glVertex3d(20, 20, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(20, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(20, 0, 0);
	glNormal3d(0, -1, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 0, 20);
	glTexCoord2d(1, 0.807); glVertex3d(20, 0, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(20, 0, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(0, 0, 0);
	glNormal3d(0, 1, 0);
	glTexCoord2d(0.820, 0.807); glVertex3d(0, 20, 20);
	glTexCoord2d(1, 0.807); glVertex3d(20, 20, 20);
	glTexCoord2d(1, 0.629);  glVertex3d(20, 20, 0);
	glTexCoord2d(0.820, 0.629); glVertex3d(0, 20, 0);

	glEnd();
}

void fig() {
	glBegin(GL_QUADS);
	glColor3d(0.7, 0.6, 0.9);
	glTranslated(0, 0, 0);
	cube2();
	glTranslated(20, 0, 0);
	cube2();
	glTranslated(0, 20, 0);
	cube2();
	glTranslated(-20, -40, 0);
	cube2();
	glEnd();
	//фигура
}
void cube3() {
	
	fig();

}
void Dr_Zoidberg() {
	glBegin(GL_QUADS);
	glColor3d(0.7, 0.6, 0.9);

	glNormal3d(0, 0, 1);
	//голова
	glTexCoord2d(0.812, 0.508); glVertex3d(0, 0, 30);//верх
	glTexCoord2d(1, 0.508); glVertex3d(0, 20, 30);
	glTexCoord2d(1, 0.320); glVertex3d(20, 20, 30);
	glTexCoord2d(0.812, 0.320); glVertex3d(20, 0, 30);

	glNormal3d(0, 0, -1);
	glTexCoord2d(0.812, 0.508); glVertex3d(0, 0, 18);//низ
	glTexCoord2d(1, 0.508); glVertex3d(0, 20, 18);
	glTexCoord2d(1, 0.320);  glVertex3d(20, 20, 18);
	glTexCoord2d(0.812, 0.320); glVertex3d(20, 0, 18);

	glNormal3d(-1, 0,0);
	glTexCoord2d(0.812, 0.508); glVertex3d(0, 0, 30);
	glTexCoord2d(1, 0.508); glVertex3d(0, 20, 30);
	glTexCoord2d(1, 0.320); glVertex3d(0, 20, 18);
	glTexCoord2d(0.812, 0.320); glVertex3d(0, 0, 18);
	glNormal3d(1, 0, 0);


	glTexCoord2d(0.812, 0.508); glVertex3d(20, 0, 30);
	glTexCoord2d(1, 0.508); glVertex3d(20, 20, 30);
	glTexCoord2d(1, 0.320); glVertex3d(20, 20, 18);
	glTexCoord2d(0.812, 0.320); glVertex3d(20, 0, 18);

	glNormal3d(0, -1, 0);
	glTexCoord2d(0.812, 0.508); glVertex3d(0, 0, 30);
	glTexCoord2d(1, 0.508);glVertex3d(20, 0, 30);
	glTexCoord2d(1, 0.320);glVertex3d(20, 0, 18);
	glTexCoord2d(0.812, 0.320);glVertex3d(0, 0, 18);

	glNormal3d(0, 1, 0);
	glTexCoord2d(0.812, 0.320); glVertex3d(0, 20, 30);
	glTexCoord2d(1, 0.320); glVertex3d(20, 20, 30);
	glTexCoord2d(1, 0.188); glVertex3d(20, 20, 18);
	glTexCoord2d(0.812, 0.188); glVertex3d(0, 20, 18);


	//туловище
	glNormal3d(0, 0, 1);
	glTexCoord2d(0.625, 0.188); glVertex3d(4, 4, 18);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 16, 18);
	glTexCoord2d(0.812, 0.0009); glVertex3d(16, 16, 18);
	glTexCoord2d(0.625, 0.0009); glVertex3d(16, 4, 18);
	glNormal3d(0, 0, -1);
	glTexCoord2d(0.625, 0.188); glVertex3d(4, 4, 6);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 16, 6);
	glTexCoord2d(0.812, 0.0009); glVertex3d(16, 16, 6);
	glTexCoord2d(0.625, 0.0009); glVertex3d(16, 4, 6);
	glNormal3d(-1, 0, 0);
	glTexCoord2d(0.625, 0.188); glVertex3d(4, 4, 18);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 16, 18);
	glTexCoord2d(0.812, 0.0009); glVertex3d(4, 16, 6);
	glTexCoord2d(0.625, 0.0009); glVertex3d(4, 4, 6);
	glNormal3d(1, 0, 0);

	glTexCoord2d(0.625, 0.188); glVertex3d(4+12, 4, 18);
	glTexCoord2d(0.812, 0.188); glVertex3d(4+12, 16, 18);
	glTexCoord2d(0.812, 0.0009); glVertex3d(4+12, 16, 6);
	glTexCoord2d(0.625, 0.0009); glVertex3d(4+12, 4, 6);
	glNormal3d(0,-1, 0);

	glTexCoord2d(0.625, 0.188);glVertex3d(4, 4, 18);
	glTexCoord2d(0.812, 0.188); glVertex3d(16, 4, 18);
	glTexCoord2d(0.812, 0); glVertex3d(16, 4, 6);
	glTexCoord2d(0.625, 0); glVertex3d(4, 4, 6);
	glNormal3d(0, 1, 0);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 16, 18);
	glTexCoord2d(1, 0.188); glVertex3d(16, 16, 18);
	glTexCoord2d(1, 0); glVertex3d(16, 16, 6);
	glTexCoord2d(0.812, 0); glVertex3d(4, 16, 6);
		
	//ноги


	glNormal3d(0, 0, 1);

	glTexCoord2d(0.720, 0.379); glVertex3d(7 - 2, 7, 6);
	glTexCoord2d(0.806, 0.379); glVertex3d(7 - 2, 13, 6);
	glTexCoord2d(0.806, 0.322); glVertex3d(13 + 2, 13, 6);
	glTexCoord2d(0.720, 0.322); glVertex3d(13 + 2, 7, 6);


	glNormal3d(-1, 0, 0);

	glTexCoord2d(0.636, 0.379); glVertex3d(7 - 2, 7, 6);
	glTexCoord2d(0.720, 0.379); glVertex3d(7 - 2, 13, 6);
	glTexCoord2d(0.720, 0.322); glVertex3d(7 - 2, 13, 0);
	glTexCoord2d(0.636, 0.322); glVertex3d(7 - 2, 7, 0);

	glNormal3d(1, 0, 0);
	glTexCoord2d(0.636, 0.379); glVertex3d(13 + 2, 7, 6);
	glTexCoord2d(0.720, 0.379); glVertex3d(13 + 2, 13, 6);
	glTexCoord2d(0.720, 0.322); glVertex3d(13 + 2, 13, 0);
	glTexCoord2d(0.636, 0.322); glVertex3d(13 + 2, 7, 0);

	glNormal3d(0, -1, 0);
	glTexCoord2d(0.720, 0.379); glVertex3d(7 - 2, 7, 6);
	glTexCoord2d(0.806, 0.379); glVertex3d(13 + 2, 7, 6);
	glTexCoord2d(0.806, 0.322); glVertex3d(13 + 2, 7, 0);
	glTexCoord2d(0.720, 0.322); glVertex3d(7 - 2, 7, 0);
	glNormal3d(0, 1, 0);
	glTexCoord2d(0.720, 0.379); glVertex3d(7 - 2, 13, 6);
	glTexCoord2d(0.806, 0.379);glVertex3d(13 + 2, 13, 6);
	glTexCoord2d(0.806, 0.322);glVertex3d(13 + 2, 13, 0);
	glTexCoord2d(0.720, 0.322);glVertex3d(7 - 2, 13, 0);
	//рука 1
	obr_setNormal(4, 16, 8, 0, 16, 8, 4, 6, 18);		//косячное освещение
	glTexCoord2d(0.812, 0.320);  glVertex3d(4, 6, 18);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 16, 8);
	glTexCoord2d(0.740, 0.188);  glVertex3d(0, 16, 8);
	glTexCoord2d(0.740, 0.320);  glVertex3d(0, 6, 18);
	 setNormal(4, 14, 6, 0, 14, 6, 0, 4, 16);
	glTexCoord2d(0.812, 0.320);	glVertex3d(4, 4, 16);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 14, 6);
	glTexCoord2d(0.740, 0.188);glVertex3d(0, 14, 6);
	glTexCoord2d(0.740, 0.320); glVertex3d(0, 4, 16);
	obr_setNormal(4, 6, 18, 0, 6, 18, 0, 4, 16);
	glTexCoord2d(0.625, 0.188); glVertex3d(4, 4, 16);
	glTexCoord2d(0.812, 0.188); glVertex3d(4, 6, 18);
	glTexCoord2d(0.812, 0); glVertex3d(0, 6, 18);
	glTexCoord2d(0.625, 0);glVertex3d(0, 4, 16);
	setNormal(4, 16, 8, 4, 14, 6, 0, 16, 8);
	glTexCoord2d(0.740, 0.188); glVertex3d(4, 16, 8);
	glTexCoord2d(0.740, 0.209);  glVertex3d(4, 14, 6);
	glTexCoord2d(0.811, 0.209);  glVertex3d(0, 14, 6);
	glTexCoord2d(0.811, 0.188); glVertex3d(0, 16, 8);
	glNormal3d(-1, 0, 0);
	 glTexCoord2d(0.740, 0.188);  glVertex3d(0, 16, 8);
	 glTexCoord2d(0.669, 0.188); glVertex3d(0, 14, 6);
	 glTexCoord2d(0.669, 0.320);  glVertex3d(0, 4, 16);
	 glTexCoord2d(0.740, 0.320); glVertex3d(0, 6, 18);

	//рука 2
		obr_setNormal(16 + 4, 16, 8, 12 + 4, 16, 8, 12 + 4, 6, 18);	//косячное освещение
		glTexCoord2d(0.812, 0.320);glVertex3d(16 + 4, 6, 18);
		glTexCoord2d(0.812, 0.188);glVertex3d(16 + 4, 16, 8);
		glTexCoord2d(0.740, 0.188);glVertex3d(12 + 4, 16, 8);
		glTexCoord2d(0.740, 0.320);glVertex3d(12 + 4, 6, 18);
		setNormal(16 + 4, 14, 6, 12 + 4, 14, 6, 12 + 4, 4, 16);
		glTexCoord2d(0.812, 0.320);glVertex3d(16 + 4, 4, 16);
		glTexCoord2d(0.812, 0.188);glVertex3d(16 + 4, 14, 6);
		glTexCoord2d(0.740, 0.188);glVertex3d(12 + 4, 14, 6);
		glTexCoord2d(0.740, 0.320); glVertex3d(12 + 4, 4, 16);
	obr_setNormal(16 + 4, 6, 18, 12 + 4, 6, 18, 12 + 4, 4, 16);
	glTexCoord2d(0.625, 0.188);	glVertex3d(16 + 4, 4, 16);
	glTexCoord2d(0.812, 0.188);glVertex3d(16 + 4, 6, 18);
	glTexCoord2d(0.812, 0);glVertex3d(12 + 4, 6, 18);
	glTexCoord2d(0.625, 0);glVertex3d(12 + 4, 4, 16);
	setNormal(16 + 4, 16, 8, 16 + 4, 14, 6, 12 + 4, 16, 8);
	glTexCoord2d(0.740, 0.188);	glVertex3d(16 + 4, 16, 8);
	glTexCoord2d(0.740, 0.209);	glVertex3d(16 + 4, 14, 6);
	glTexCoord2d(0.811, 0.209);	glVertex3d(12 + 4, 14, 6);
	glTexCoord2d(0.811, 0.188);	glVertex3d(12 + 4, 16, 8);
	glNormal3d(1, 0, 0);
	glTexCoord2d(0.740, 0.188); glVertex3d(16 + 4, 16, 8);
	glTexCoord2d(0.669, 0.188);glVertex3d(16 + 4, 14, 6);
	glTexCoord2d(0.669, 0.320);	glVertex3d(16 + 4, 4, 16);
	glTexCoord2d(0.740, 0.320);	glVertex3d(16 + 4, 6, 18);

	glEnd();

}

//Класс для настройки света
class CustomLight : public Light
{
public:
	CustomLight()
	{
		//начальная позиция света

	//	pos = Vector3(0, 0, 200);
		light.pos = camera.pos;
	}

	
	//рисует сферу и линии под источником света, вызывается движком
	void  DrawLightGhismo()
	{
		glDisable(GL_LIGHTING);
		glColor3d(0.9, 0.8, 0);
		Sphere s;
		s.pos = pos;
		s.scale = s.scale*0.08;
		s.Show();
		
		if (OpenGL::isKeyPressed('G'))
		{
			glColor3d(0, 0, 0);
			//линия от источника света до окружности
			glBegin(GL_LINES);
			glVertex3d(pos.X(), pos.Y(), pos.Z());
			glVertex3d(pos.X(), pos.Y(), 0);
			glEnd();

			//рисуем окружность
			Circle c;
			c.pos.setCoords(pos.X(), pos.Y(), 0);
			c.scale = c.scale*1.5;
			c.Show();
		}

	}

	void SetUpLight()
	{
		GLfloat amb[] = { 0.2, 0.2, 0.2, 0 };
		GLfloat dif[] = { 1.0, 1.0, 1.0, 0 };
		GLfloat spec[] = { .7, .7, .7, 0 };
		GLfloat position[] = { pos.X(), pos.Y(), pos.Z(), 1. };

		// параметры источника света
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		// характеристики излучаемого света
		// фоновое освещение (рассеянный свет)
		glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
		// диффузная составляющая света
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
		// зеркально отражаемая составляющая света
		glLightfv(GL_LIGHT0, GL_SPECULAR, spec);

		glEnable(GL_LIGHT0);
	}


} light;  //создаем источник света




//старые координаты мыши
int mouseX = vx, mouseY = vy;

void mouseEvent(OpenGL *ogl, int mX, int mY)
{
	int dx = mouseX - mX;
	int dy = mouseY - mY;
	mouseX = mX;
	mouseY = mY;

	//меняем углы камеры при нажатой левой кнопке мыши
	if (OpenGL::isKeyPressed(VK_RBUTTON))
	{
		camera.fi1 += 0.01*dx;
		camera.fi2 += -0.01*dy;
	}

	
	//двигаем свет по плоскости, в точку где мышь
	if (OpenGL::isKeyPressed('G') && !OpenGL::isKeyPressed(VK_LBUTTON))
	{
		LPPOINT POINT = new tagPOINT();
		GetCursorPos(POINT);
		ScreenToClient(ogl->getHwnd(), POINT);
		POINT->y = ogl->getHeight() - POINT->y;

		Ray r = camera.getLookRay(POINT->x, POINT->y);

		double z = light.pos.Z();

		double k = 0, x = 0, y = 0;
		if (r.direction.Z() == 0)
			k = 0;
		else
			k = (z - r.origin.Z()) / r.direction.Z();

		x = k*r.direction.X() + r.origin.X();
		y = k*r.direction.Y() + r.origin.Y();

		light.pos = Vector3(x, y, z);
	}

	if (OpenGL::isKeyPressed('G') && OpenGL::isKeyPressed(VK_LBUTTON))
	{
		light.pos = light.pos + Vector3(0, 0, 0.02*dy);
	}

	
}

void mouseWheelEvent(OpenGL *ogl, int delta)
{

	if (delta < 0 && camera.camDist <= 1)
		return;
	if (delta > 0 && camera.camDist >= 1000000)
		return;

	camera.camDist += camera.camDist*0.0005*delta;

}
//клавиатура
void keyDownEvent(OpenGL *ogl, int key)
{
	if (key == 'L')
	{
		lightMode = !lightMode;
	}

	if (key == 'T')
	{
		textureMode = !textureMode;
	}
	if (key == 'W' )
	{
		light.pos = camera.pos;
		if (key != 'A' && key != 'D')
		{
			if (vy < 180) 
			{
			//условие новое чтобы убрать баг	
				vy = vy + 10;
				if (vy == ky - 10)
				{
					if (vx == kx || vx == kx + 10 || vx == kx - 10 )
					{
						if (ky < 180)
						{
							/*if (ky ==(ky2-40 +20) && ky2 < 180)
								ky2 = ky2 + 10;*/
							ky = ky + 10;
						}
					}
				}
				if (vy == ky2 - 10)
				{
					if ( vx == kx2 || vx == kx2 + 10 || vx == kx2 - 10)
					{
						if (ky2 < 180)
						{
							ky2 = ky2 + 10;
						}
					}
				}
				if (vy == ky3 - 30)
				{
						if (vx == kx3 || vx == kx3 + 10 || vx == kx3 - 10)
						{
							if (ky3 + 30 < 180)
							{
								ky3 = ky3 + 10;
							}
						}
				}
				if (vy == ky3 - 10)
				{
					if (vx == kx3 || vx == kx3 + 30  || vx == kx3 + 20 )
					{
						if (ky3 + 30 < 190)
						{
							ky3 = ky3 + 10;
						}
					}
				}
			}
		}
	}
	if (key == 'S')
	{
		light.pos = camera.pos;

		
		if (vy > -200)
		{
			vy = vy - 10;
			if (vy == ky + 10)
			{
				if (vx == kx || vx == kx + 10 || vx == kx - 10)
				{
					if (ky > -200)
						ky = ky - 10;
				}
			}
			if (vy == ky2 + 10)
			{
				if (vx == kx2 || vx == kx2 + 10 || vx == kx2 - 10)
				{
					if (ky2 > -200)
						ky2 = ky2 - 10;
				}
			}
			if (vy == ky3 + 30)
			{
				if ( vx == kx3 + 30 || vx == kx3 + 20 || vx == kx3 + 10)
				{
					if (ky3  > -180)
					{
						ky3 = ky3 - 10;
					}
				}
			}
			if (vy == ky3 + 10)
			{
				if (vx == kx3 || vx == kx3 + 10 || vx == kx3 - 10)
				{
					if (ky3  > -180)	
					{
						ky3 = ky3 - 10;
					}
				}
			}
		}
	}
	if (key == 'A')
	{
		light.pos = camera.pos;
		if (vx > -200) 
		{
			vx = vx - 10;
			if (vx == kx + 10)
			{
				if (vy == ky || vy == ky + 10 || vy == ky - 10)
				{
					if (kx > -200)
						kx = kx - 10;
				}
			}
			if (vx == kx2 + 10)
			{
				if (vy == ky2 || vy == ky2 + 10 || vy == ky2 - 10)
				{
					if (kx2 > -200)
						kx2 = kx2 - 10;
				}
			}
			if (vx == kx3 + 30)
			{
				if (vy == ky3 || vy == ky3 + 30 || vy == ky3 + 20 || vy == ky3 + 10 || vy == ky3 + 15 || vy == ky3 -10)
				{
					if (kx3-30 > -230)
					{

							kx3 = kx3 - 10; 
					}
				}
			}
			if (vx == kx3 + 10)
			{
				if (vy == ky3 || vy == ky3 - 30 || vy == ky3 - 20 || vy == ky3 -15 || vy == ky3 - 10)
				{
					if (kx3 - 30 > -230)
					{

						kx3 = kx3 - 10;
					}
				}
			}
			
		}
	}
	if (key == 'D')
	{
		light.pos = camera.pos;
		if (vx < 180) 
		{
			vx = vx + 10;
			if (vx == kx - 10)
			{
				if (vy == ky || vy == ky + 10 || vy == ky - 10)
				{
					if (kx < 180)
					kx = kx + 10;
				}
			}
			if (vx == kx2 - 10)
			{
				if (vy == ky2 || vy == ky2 + 10 || vy == ky2 - 10)
				{
					if (kx2 < 180)
						kx2 = kx2 + 10;
				}
			}
			if (vx == kx3 - 10)
			{
				if (vy == ky3 || vy == ky3 - 30 || vy == ky3 - 20 || vy == ky3 - 10 || vy == ky3 - 15 || vy == ky3 + 10)
				{
					if (kx3 - 30 < 130)
					{

						kx3 = kx3 + 10;
					}
				}
			}

			if (vx == kx3 + 10)
			{
				if (vy == ky3 || vy == ky3 + 30 || vy == ky3 + 20 || vy == ky3 + 15 || vy == ky3 + 10)
				{
					if (kx3 - 30 < 130)
					{

						kx3 = kx3 + 10;
					}
				}
			}
		}
	}
	if (key == 'W' && key == 'A')
	{
		vy = vy + 10;
		vx = vx - 10;

	}
	if (key == 'W' && key == 'D')
	{
		vy = vy + 10;
		vx = vx + 10;

	}
	if (key == 'S' && key == 'A')
	{
		vy = vy - 10;
		vx = vx - 10;

	}
	if (key == 'S' && key == 'D')
	{
		vy = vy - 10;
		vx = vx + 10;

	}
	if (key == ' ')
	{
		
			camera.fi1 = -acos(-1) / 2;
			camera.fi2 = acos(-1) / 2;
			camera.camDist = 600;
			light.pos = camera.pos;
			//light.pos = Vector3(0, 0,200);
		
	}
	if (key == 'F')
	{
		light.pos = camera.pos;
	}
	if (key == '0')
	{
		flag = 1; flag2 = 1; flag3 = 1;
		L2_flag = 0, L2_flag2 = 0, L2_flag3 = 0;
	}

	if (key == 'Q')
	{
		flag = 0; flag2 = 0; flag3 = 0;
		vx0 = 10, vy0 = 10, vz0 = 0.5, vx = 0, vy = 0, vz = 0, kx = 50, ky = -70, kz, kx2 = 40, ky2 = 150, kz2 = 0, kx3 = -110, ky3 = -90, kz3 = 0;
	}
	if (key == '1')
	{
		person1 = 1;
		person2 = 0;
		person3 = 0;
	}
	if (key == '2')
	{
		person1 = 0;
		person2 = 1;
		person3 = 0;
	}
	if (key == '3')
	{
		person1 = 0;
		person2 = 0;
		person3 = 1;
	}

	if (key == '9')
	{
		L2_flag = 8;
	}
}

void keyUpEvent(OpenGL *ogl, int key)
{
	
}


//выполняется перед первым рендером -текстуры
void initRender(OpenGL *ogl)
{
	//настройка текстур

	//4 байта на хранение пикселя
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	//настройка режима наложения текстур
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//включаем текстуры
	glEnable(GL_TEXTURE_2D);


	//массив трехбайтных элементов  (R G B)
	RGBTRIPLE *texarray;

	//массив символов, (высота*ширина*4      4, потомучто   выше, мы указали использовать по 4 байта на пиксель текстуры - R G B A)
	char *texCharArray;
	int texW, texH;
	OpenGL::LoadBMP("texture_prism_norm1.bmp", &texW, &texH, &texarray);
	OpenGL::RGBtoChar(texarray, texW, texH, &texCharArray);


	//генерируем ИД для текстуры 
	glGenTextures(1, &texId1);
	//биндим айдишник, все что будет происходить с текстурой, будте происходить по этому ИД 
	glBindTexture(GL_TEXTURE_2D, texId1);

	//загружаем текстуру в видеопямять, в оперативке нам больше она не нужна 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, GL_RGBA, GL_UNSIGNED_BYTE, texCharArray);

	//отчистка памяти 
	free(texCharArray);
	free(texarray);

	//наводим шмон 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	OpenGL::LoadBMP("textur1.0.bmp", &texW, &texH, &texarray);
	OpenGL::RGBtoChar(texarray, texW, texH, &texCharArray);


	//генерируем ИД для текстуры 
	glGenTextures(1, &texId2);
	//биндим айдишник, все что будет происходить с текстурой, будте происходить по этому ИД 
	glBindTexture(GL_TEXTURE_2D, texId2);

	//загружаем текстуру в видеопямять, в оперативке нам больше она не нужна 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, GL_RGBA, GL_UNSIGNED_BYTE, texCharArray);

	//отчистка памяти 
	free(texCharArray);
	free(texarray);

	//наводим шмон 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	OpenGL::LoadBMP("textur2.0.bmp", &texW, &texH, &texarray);
	OpenGL::RGBtoChar(texarray, texW, texH, &texCharArray);


	//генерируем ИД для текстуры 
	glGenTextures(1, &texId3);
	//биндим айдишник, все что будет происходить с текстурой, будте происходить по этому ИД 
	glBindTexture(GL_TEXTURE_2D, texId3);

	//загружаем текстуру в видеопямять, в оперативке нам больше она не нужна 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, GL_RGBA, GL_UNSIGNED_BYTE, texCharArray);

	//отчистка памяти 
	free(texCharArray);
	free(texarray);

	//наводим шмон 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	OpenGL::LoadBMP("textur3.0.bmp", &texW, &texH, &texarray);
	OpenGL::RGBtoChar(texarray, texW, texH, &texCharArray);


	//генерируем ИД для текстуры 
	glGenTextures(1, &texId4);
	//биндим айдишник, все что будет происходить с текстурой, будте происходить по этому ИД 
	glBindTexture(GL_TEXTURE_2D, texId4);

	//загружаем текстуру в видеопямять, в оперативке нам больше она не нужна 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, GL_RGBA, GL_UNSIGNED_BYTE, texCharArray);

	//отчистка памяти 
	free(texCharArray);
	free(texarray);

	//наводим шмон 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);



	//камеру и свет привязываем к "движку"
	ogl->mainCamera = &camera;
	ogl->mainLight = &light;

	// нормализация нормалей : их длины будет равна 1
	glEnable(GL_NORMALIZE);

	// устранение ступенчатости для линий
	glEnable(GL_LINE_SMOOTH);


	//   задать параметры освещения
	//  параметр GL_LIGHT_MODEL_TWO_SIDE - 
	//                0 -  лицевые и изнаночные рисуются одинаково(по умолчанию), 
	//                1 - лицевые и изнаночные обрабатываются разными режимами       
	//                соответственно лицевым и изнаночным свойствам материалов.    
	//  параметр GL_LIGHT_MODEL_AMBIENT - задать фоновое освещение, 
	//                не зависящее от сточников
	// по умолчанию (0.2, 0.2, 0.2, 1.0)

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);
}






void func_tena_y(double x, double y, double l, double q, double h, double r, double r1, double r2, double r3, double s, double s1, double s2, double s3)		 /*стена с шириной по y и высотой по z*/
{

	glBegin(GL_QUADS);
	setNormal(x, y, 15.7, x + q, y, 15.7, x + q, y, 15.7 + h);
	//боковины
	glTexCoord2d(r, r1); glVertex3d(x, y, 0);
	glTexCoord2d(r2, r3); glVertex3d(x + q, y, 0);
	glTexCoord2d(s, s1); glVertex3d(x + q, y, h);
	glTexCoord2d(s2, s3); glVertex3d(x, y, h);

	setNormal(x, y + l, 15.7, x + q, y + l, 15.7, x + q, y + l, 15.7 + h);
	glTexCoord2d(r, r1); glVertex3d(x, y + l, 0);
	glTexCoord2d(r2, r3); glVertex3d(x + q, y + l, 0);
	glTexCoord2d(s, s1); glVertex3d(x + q, y + l, h);
	glTexCoord2d(s2, s3); glVertex3d(x, y + l, h);

	setNormal(x, y, 0 + 15.7, x, y + l, 0 + 15.7, x, y + l, h + 15.7);
	glTexCoord2d(r, r1); glVertex3d(x, y, 0);
	glTexCoord2d(r2, r3); glVertex3d(x, y + l, 0);
	glTexCoord2d(s, s1); glVertex3d(x, y + l, h);
	glTexCoord2d(s2, s3); glVertex3d(x, y, h);

	setNormal(x + q, y, 0 + 15.7, x + q, y + l, 0 + 15.7, x + q, y + l, h + 15.7);
	glTexCoord2d(r, r1); glVertex3d(x + q, y, 0);
	glTexCoord2d(r2, r3); glVertex3d(x + q, y + l, 0);
	glTexCoord2d(s, s1); glVertex3d(x + q, y + l, h);
	glTexCoord2d(s2, s3); glVertex3d(x + q, y, h);


	//низ


	glVertex3d(x, y, 0);
	glVertex3d(x + q, y, 0);
	glVertex3d(x + q, y + l, 0);
	glVertex3d(x, y + l, 0);
	//верх
	glVertex3d(x, y, h);
	glVertex3d(x + q, y, h);
	glVertex3d(x + q, y + l, h);
	glVertex3d(x, y + l, h);
	glEnd();
}


void func_tena_r(double x, double y, double l, double q, double h, double r, double r1, double r2, double r3, double s, double s1, double s2, double s3)		 /*стена с шириной по y и высотой по z*/
{

	glBegin(GL_QUADS);
	setNormal(x, y, 15.7, x + q, y, 15.7, x + q, y, 15.7 + h);
	//боковины

	glColor3d(0.5, 0.1, 0.5);
	glTexCoord2d(r, r1); glVertex3d(x, y, 15.7);
	glTexCoord2d(r2, r3); glVertex3d(x + q, y, 15.7);
	glTexCoord2d(s, s1); glVertex3d(x + q, y, 15.7 + h);
	glTexCoord2d(s2, s3); glVertex3d(x, y, 15.7 + h);

	setNormal(x, y + l, 15.7, x + q, y + l, 15.7, x + q, y + l, 15.7 + h);
	glTexCoord2d(r, r1); glVertex3d(x, y + l, 15.7);
	glTexCoord2d(r2, r3); glVertex3d(x + q, y + l, 15.7);
	glTexCoord2d(s, s1); glVertex3d(x + q, y + l, 15.7 + h);
	glTexCoord2d(s2, s3); glVertex3d(x, y + l, 15.7 + h);

	setNormal(x, y, 0 + 15.7, x, y + l, 0 + 15.7, x, y + l, h + 15.7);
	glTexCoord2d(r, r1); glVertex3d(x, y, 0 + 15.7);
	glTexCoord2d(r2, r3); glVertex3d(x, y + l, 0 + 15.7);
	glTexCoord2d(s, s1); glVertex3d(x, y + l, h + 15.7);
	glTexCoord2d(s2, s3); glVertex3d(x, y, h + 15.7);

	setNormal(x + q, y, 0 + 15.7, x + q, y + l, 0 + 15.7, x + q, y + l, h + 15.7);
	glTexCoord2d(r, r1); glVertex3d(x + q, y, 0 + 15.7);
	glTexCoord2d(r2, r3); glVertex3d(x + q, y + l, 0 + 15.7);
	glTexCoord2d(s, s1); glVertex3d(x + q, y + l, h + 15.7);
	glTexCoord2d(s2, s3); glVertex3d(x + q, y, h + 15.7);


	//низ


	glVertex3d(x, y, 0 + 15.7);
	glVertex3d(x + q, y, 0 + 15.7);
	glVertex3d(x + q, y + l, 0 + 15.7);
	glVertex3d(x, y + l, 0 + 15.7);
	//верх
	glVertex3d(x, y, h + 15.7);
	glVertex3d(x + q, y, h + 15.7);
	glVertex3d(x + q, y + l, h + 15.7);
	glVertex3d(x, y + l, h + 15.7);


	glVertex3d(0, 0, 15.7);
	glVertex3d(97, 0, 0 + 15.7);
	glVertex3d(97, 172, 0 + 15.7);
	glVertex3d(0, 172, 0 + 15.7);

	//терраса
	glVertex3d(107, 192, 15.7);
	glVertex3d(107, 172, 0 + 15.7);
	glVertex3d(0, 172, 0 + 15.7);
	glVertex3d(0, 192, 0 + 15.7);
	glVertex3d(97, 29, 15.7);
	glVertex3d(97, 192, 0 + 15.7);
	glVertex3d(107, 192, 0 + 15.7);
	glVertex3d(107, 29, 0 + 15.7);

	//крыша 	
	glVertex3d(108, 203, 15.7);
	glVertex3d(108, 192, 0 + 15.7);
	glVertex3d(14.5, 192, 0 + 15.7);
	glVertex3d(14.5, 203, 0 + 15.7);


	glEnd();
}

void etash_1()
{


	glColor3d(0.5, 0.1, 0.5);
	//стены 1-го этажа 
	func_tena_y(0, 0, 1, 16, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(16, 0, 1, 16, 15.7, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);//белая стена
	func_tena_y(32, 0, 1, 16, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(48, 0, 1, 16, 15.7, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);
	func_tena_y(64, 0, 1, 16, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(80, 0, 1, 17, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена

	func_tena_y(96, 1, 28, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);
	func_tena_y(96, 29, 1, 12, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);
	func_tena_y(107, 30, 30, 1, 15.7, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);
	func_tena_y(107, 60, 20, 1, 15.7, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);
	func_tena_y(107, 80, 2, 8, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_y(107, 80, 14, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);
	//тут дверь
	func_tena_y(107, 97, 8, 1, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(107, 105, 15, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);
	func_tena_y(107, 120, 20, 1, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(107, 140, 30, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);
	//вход в гараж
	func_tena_y(108, 192, 11, 1, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена

	func_tena_y(108, 202, 1, -11, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_y(97, 202, 1, -30, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(67, 202, 1, -25, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_y(42, 202, 5, -3, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_y(39, 202, 1, -8, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_y(28, 202, 1, -12, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_y(16, 203, -32, -1.5, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_y(16, 171, -50, -1.5, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_y(16, 121, 1, -12, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_y(0, 121, 15, 1, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_y(0, 121, -24, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_y(0, 97, -58, 1, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_y(0, 39, -39, 1, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно





}


void etash_2()
{

	//стены 2-го этажа 
	func_tena_r(0, 0, 1, 16, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(16, 0, 1, 16, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(32, 0, 1, 16, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(48, 0, 1, 16, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(64, 0, 1, 16, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(80, 0, 1, 17, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена

	func_tena_r(96, 1, 28, 1, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_r(96, 29, 1, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(96, 30, 30, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(96, 60, 20, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(96, 80, 2, 8, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(96, 80, 14, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
																					 //тут дверь - вход на террасу
	func_tena_r(96, 97, 8, 1, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_r(96, 105, 15, 1, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_r(96, 120, 20, 1, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
	func_tena_r(96, 140, 32, 1, 15.7, 0.340, 1, 0.678, 1, 0.678, 0.810, 0.340, 0.810);//черная стена
																					  //вход на террасу
	func_tena_r(0, 172, -51, 1, 15.7, 0.5673828, 0.808, 0.810, 0.808, 0.810, 0.576, 0.56738, 0.576);//окно
	func_tena_r(0, 121, -24, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(0, 97, -58, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(0, 39, -39, 1, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
	func_tena_r(0, 171, 1, 97, 15.7, 0, 0.809, 0.566, 0.809, 0.566, 0.492, 0, 0.492);//серая стена
																					 //Color4f(1.0f, 1.0f, 0.0f, 0.5f); //альфа 
	func_tena_r(96, 29, 0.5, 12, 15.7*0.4, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);//белая стена
	func_tena_r(107, 29, 163, 0.5, 15.7*0.4, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);//белая стена
	func_tena_r(107, 192, -0.5, -107, 15.7*0.4, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);//белая стена
	func_tena_r(0, 192, -20, 0.5, 15.7*0.4, 0, 1, 0.339, 1, 0.339, 0.810, 0, 0.810);//белая стена



	glBegin(GL_QUADS);
	glVertex3d(0, 0, 15.7 * 2);
	glVertex3d(0, 172, 15.7 * 2);
	glVertex3d(96, 172, 15.7 * 2);
	glVertex3d(96, 0, 15.7 * 2);

	glEnd();
}


void zemla() {

	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glTexCoord2d(0, 0); glVertex3d(-200, -200, -0.1);
	glTexCoord2d(0, 0.489);  glVertex3d(-200, 200, -0.1);
	glTexCoord2d(0.488, 0.489);  glVertex3d(200, 200, -0.1);
	glTexCoord2d(0.488, 0); glVertex3d(200, -200, -0.1);
	glEnd();
}
//доделать бок основания )
void zemla2() {

	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glTexCoord2d(0, 0); glVertex3d(-200, -200, -0.1);
	glTexCoord2d(0, 0.489);  glVertex3d(-200, 200, -0.1);
	glTexCoord2d(0.488, 0.489);  glVertex3d(200, 200, -0.1);
	glTexCoord2d(0.488, 0); glVertex3d(200, -200, -0.1);
	glEnd();
}

void printCircle() {
		double x, y, x1, y1;
		glBegin(GL_TRIANGLE_FAN);


		glTexCoord2d(0.19921875, 0.80078125);
		glNormal3d(0, 0, 1);
		glVertex3d(0, 0, 0.01);
		for (double alpha = 0; alpha <= 360; alpha += 1) {
			x = 0 + cos(alpha * 3.141592653589793238 / 180) * 20;
			y = 0 + sin(alpha * 3.141592653589793238 / 180) * 20;

			x1 = 0.19921875 + cos(alpha * 3.141592653589793238 / 180) * 0.185;
			y1 = 0.80078125 + sin(alpha * 3.141592653589793238 / 180) * 0.185;
			
			glTexCoord2d(x1, y1);
			glVertex3d(x, y, 0.01);


		}
		//glTexCoord2d(0, 0); 
		glEnd();
	}


void main() {

	//Начало рисования
	glBindTexture(GL_TEXTURE_2D, texId2);
	//земля на которой стоит весь проект
	zemla();
	glPushMatrix();
	glTranslated(0, 0, -10);
	zemla();
	glPopMatrix();
	if ((kx == -80) && (ky == 100))
		flag = 1;
	if ((kx2 == -80) && (ky2 == 100))
		flag2 = 1;
	if ((kx3 == 130) && (ky3 == 80))
		flag3 = 1;
	if (flag == 0)
	{
		glPushMatrix();
		glTranslated(kx, ky, kz);
		cube();			//кубик 1-ый
		glPopMatrix();
	}


	glPushMatrix();

	if (flag2 == 0)
	{
		glTranslated(kx2, ky2, kz2);
		cube2();			//кубик 2-ой
		glPopMatrix();
	}
	if (flag3 == 0)
	{
		glPushMatrix();
		glTranslated(kx3, ky3, kz3);
		cube3();			//фигура 3
		glPopMatrix();
	}

	if (person1 == 1 && person2 == 0 && person3 == 0)
	{
		glBindTexture(GL_TEXTURE_2D, texId2);
		glPushMatrix();

		glTranslated(vx, vy, vz);
		Dr_Zoidberg();		//модель Доктора Зойдберга
		glPopMatrix();


	}
	for (i = 0; i < 4; i++) {
		//4 дома
		glPushMatrix();
		glRotatef(90.0*i, 0.0, 0.0, 1.0);
		glTranslatef(300.0, 0.0, 0.0);
		glTranslated(-50.0, -100.0, 0.0);
		etash_1();
		etash_2();
		glPopMatrix();
	}



	if (person1 == 0 && person2 == 1 && person3 == 0)
	{
		glBindTexture(GL_TEXTURE_2D, texId3);
		glPushMatrix();
		glTranslated(vx, vy, vz);
		Dr_Zoidberg();		//модель РОБОТА
		glPopMatrix();

	}
	if (person1 == 0 && person2 == 0 && person3 == 1)
	{
		glBindTexture(GL_TEXTURE_2D, texId4);
		glPushMatrix();
		glTranslated(vx, vy, vz);
		Dr_Zoidberg();			//модель Зефирки
		glPopMatrix();

	}


	//круг с текстуркой :)
	glPushMatrix();
	if (textureMode)
	glBindTexture(GL_TEXTURE_2D, texId1);
	glTranslated(vx0, vy0, vz0);	
	printCircle();
	glPopMatrix();

	

}



void level2() {
	person1 = 0; person2 = 1; person3 = 0; // перерубление персонажа
	
										   //Начало рисования
	glBindTexture(GL_TEXTURE_2D, texId3);
	//земля на которой стоит весь проект
	zemla();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texId3);
	glTranslated(0, 0, -10);
	zemla();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, texId2);
	if ((kx == -200) && (ky == 180))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if ((kx == 180) && (ky == 180))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if ((kx ==-200) && (ky == -200))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if ((kx ==-10) && (ky == 180))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if ((kx == -10) && (ky == -200))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if ((kx == -200) && (ky == -10))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if ((kx == 180) && (ky == -10))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	
	if ((kx == 180) && (ky == -200))
	{
		L2_flag++;
		kx = 50, ky = -70;
	}
	if (L2_flag != 8)
	{
		glPushMatrix();
		glTranslated(kx, ky, kz);
		cube();			//кубик 1-ый
		glPopMatrix();
	}
	

	if (person1 == 1 && person2 == 0 && person3 == 0)
	{
		glBindTexture(GL_TEXTURE_2D, texId2);
		glPushMatrix();

		glTranslated(vx, vy, vz);
		Dr_Zoidberg();		//модель Доктора Зойдберга
		glPopMatrix();


	}

		
	for (i = 0; i < 4; i++) {
		//4 дома
		
			glPushMatrix();
			glRotatef(90.0*i, 0.0, 0.0, 1.0);
			glTranslatef(300.0, 0.0, 0.0);
			glTranslated(-50.0, -100.0, 0.0);
			etash_1();
			etash_2();
			glPopMatrix();
		
	}

	if (person1 == 0 && person2 == 1 && person3 == 0)
	{
		glBindTexture(GL_TEXTURE_2D, texId3);
		glPushMatrix();
		glTranslated(vx, vy, vz);
		Dr_Zoidberg();		//модель РОБОТА
		glPopMatrix();

	}
	if (person1 == 0 && person2 == 0 && person3 == 1)
	{
		glBindTexture(GL_TEXTURE_2D, texId4);
		glPushMatrix();
		glTranslated(vx, vy, vz);
		Dr_Zoidberg();		//модель Зефирки
		glPopMatrix();

	}

	if (textureMode)
		glBindTexture(GL_TEXTURE_2D, texId1);
	//круг с текстуркой :)
	glPushMatrix();
	glTranslated(vx0, vy0, vz0);
	printCircle();
	glPopMatrix();



}
void Render(OpenGL *ogl)
{
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);
	if (textureMode)
		glEnable(GL_TEXTURE_2D);

	if (lightMode)
		glEnable(GL_LIGHTING);


	//настройка материала
	GLfloat amb[] = { 0.2, 0.2, 0.1, 1. };
	GLfloat dif[] = { 0.4, 0.65, 0.5, 1. };
	GLfloat spec[] = { 0.9, 0.8, 0.3, 1. };
	GLfloat sh = 0.1f * 256;


	//фоновая
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	//дифузная
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
	//зеркальная
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec); \
		//размер блика
		glMaterialf(GL_FRONT, GL_SHININESS, sh);

	//чтоб было красиво, без квадратиков (сглаживание освещения)
	glShadeModel(GL_SMOOTH);
	//===================================
	//Прогать тут  
	
	if (flag == 1 && flag2 == 1 && flag3 == 1)
	{
		if (t<180)
		{
			t += 2;
			glPushMatrix();
			glRotatef(t, 1.0, 0.0, 0.0);
			zemla();
			glPopMatrix();
		}
		
			level2();
			if (L2_flag == 8)
			{
				t = 0;
				//доделать выыиграшь )
				//if ((vx == (vx0 - 10)) && (vy ==(vy - 10)))
				{
					
				}
			}

	}
	else 
		main();


	
	//текст сообщения вверху слева, если надоест - закоментировать, или заменить =)
	char c[250];  //максимальная длина сообщения
	sprintf_s(c, "(T)Текстуры - %d\n(L)Свет - %d\n\nУправление светом:\n"
		"G - перемещение в горвыавыизонтальной плоскости,\nG+ЛКМ+перемещение по вертикальной линии\n"
		"R - установить камеру и свет в начальное положение\n"
		"F - переместить свет в точку камеры", textureMode, lightMode);
	ogl->message = std::string(c);
	



}   //конец тела функции

