#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>    /*Для Linux и Windows*/
#else
#include <GLUT/GLUT.h>  /*Для Mac OS*/
#endif

void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("PW5");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(-15, 15, -15, 15, -15, 15);   //при изменении параметров функции меняются размеры окна
	gluPerspective(60, 1, 0, 20);   //эта функция позволяет установить "камеру" в определенное место, задать перспективу
	gluLookAt(0, 0, 25, 0, 0, 0, 0, 1, 0);   //при изменении предпоследнего параметра сцена переворачивается

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1, 1, 1, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glutWireTeapot(8);   //параметр задает размер
	//glutSolidSphere(10, 8, 8);   //первый параметр задает радиус, второй параметр задает количество углов
	//glutWireSphere(10, 36, 20); 
	//glutSolidCube(5);
	//glutWireCube(5);
	//glutSolidCone(5, 10, 36, 20);
	//glutWireCone(5, 10, 36, 20);
	//glutSolidTorus(5, 10, 36, 20);
	//glutWireTorus(5, 10, 36, 20);
	//glutSolidTetrahedron();
	//glutWireTetrahedron();
	//glutSolidOctahedron();
	//glutWireOctahedron();
	//glutSolidDodecahedron();
	//glutWireDodecahedron();
	//glutSolidIcosahedron();
	//glutWireIcosahedron();

	//оси OX, OY и OZ
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3i(-800, 0, 0);
	glVertex3i(800, 0, 0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3i(0, -600, 0);
	glVertex3i(0, 600, 0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3i(0, 0, -800);
	glVertex3i(0, 0, 800);
	glEnd();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:   // ESC
		exit(0);
		break;
	case 43:   //+
		glMatrixMode(GL_MODELVIEW);
		glScaled(1.3, 1.3, 0);
		display();
		break;
	case 45:   //-
		glMatrixMode(GL_MODELVIEW);
		glScaled(0.9, 0.9, 0);
		display();
		break;
	case 127: // DELETE (вращение объектов против часовой стрелки вокруг оси OZ)
		glMatrixMode(GL_MODELVIEW);
		glRotated(-10, 0, 0, 1);
		display();
		break;
	default:
		break;
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, 1, 0);   //если изменить третий параметр функции, объект начинает пропадать
		display();
		break;
	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, -1, 0);
		display();
		break;
	case GLUT_KEY_LEFT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-1, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(1, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME:   //вращение объектов против часовой стрелки вокруг оси OX
		glMatrixMode(GL_MODELVIEW);
		glRotated(-1, 1, 0, 0);
		display();
		break;
	case GLUT_KEY_END:   //вращение объектов против часовой стрелки вокруг оси OY
		glMatrixMode(GL_MODELVIEW);
		glRotated(-1, 0, 1, 0);
		display();
		break;
	case GLUT_KEY_PAGE_UP:   //вращение объектов по часовой стрелки вокруг всех трех осей одновременно
		glMatrixMode(GL_MODELVIEW);
		glRotated(1, 1, 1, 1);
		display();
		break;
	case GLUT_KEY_PAGE_DOWN:   //вращение объектов против часовой стрелки вокруг всех трех осей одновременно
		glMatrixMode(GL_MODELVIEW);
		glRotated(-1, 1, 1, 1);
		display();
		break;
	}
}