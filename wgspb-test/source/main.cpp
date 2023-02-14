
/*
	DO NOT MODIFY THIS FILE.
	Use test.cpp instead.
*/

#include <stdio.h>
#include <windows.h>

#include "GL/glut.h"
#include "nvToolsExt.h"

#include "test.h"

int originalWindow = 0, currentWindow;

void platform::drawPoint(float x, float y, float r, float g, float b, float a)
{
	glColor4f(r, g, b, a);
	glVertex2f(x, y);
}

void display(void)
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	nvtxRangePush("test::render()");
	glBegin(GL_POINTS);
	test::render();
	glEnd();
	nvtxRangePop();

	glutSwapBuffers();
};

void idle(void)
{
	nvtxRangePush(__FUNCTION__);

	int time = glutGet(GLUT_ELAPSED_TIME);
	static int lastTime = 0;
	int delta = time - lastTime;
	lastTime = time;

	// check memory
	{
		static int nextStats = -1;
		if (nextStats < time)
		{
			MEMORYSTATUSEX memStatus;
			ZeroMemory(&memStatus, sizeof(MEMORYSTATUSEX));
			memStatus.dwLength = sizeof(MEMORYSTATUSEX);
			GlobalMemoryStatusEx(&memStatus);
			int totalVirtual = (memStatus.ullTotalVirtual / 1024) / 1024;
			int availVirtual = (memStatus.ullAvailVirtual / 1024) / 1024;
			int usedVirtual = totalVirtual - availVirtual;
			printf("Virtual memory info. Total: %dMb, Free: %dMb, Used: %dMb\n", totalVirtual, availVirtual, usedVirtual);
			nextStats = time + 3000;
		}
	}

	{
		static int nextAnim = -1;
		static int animPos = 0;
		const char *animation = "-\\|/-\\|/";

		if (nextAnim < time)
		{
			printf("\b\b%c ", animation[animPos]);
			animPos = (animPos+1) % (8);
			nextAnim = time + 60;
		}
	}

	nvtxRangePush("test::update()");
	test::update(delta);
	nvtxRangePop();

	glutPostWindowRedisplay(currentWindow);

	nvtxRangePop();
};

void visible(int vis)
{
	glutIdleFunc((vis == GLUT_VISIBLE) ? idle : NULL);
};

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_UP && button == 0)
	{
		nvtxRangePush("test::on_click()");
		test::on_click(x, y);
		nvtxRangePop();
	}
};

void initWindow(void)
{
	glutDisplayFunc(display);
	glutVisibilityFunc(visible);
	glutMouseFunc(mouse);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, test::SCREEN_WIDTH, 0, test::SCREEN_HEIGHT, 0, 40);
	glMatrixMode(GL_MODELVIEW); 
	glPointSize(3.0);

	currentWindow = glutGetWindow();
};

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize((int)test::SCREEN_WIDTH, (int)test::SCREEN_HEIGHT);
	originalWindow = glutCreateWindow("asteroids");
	initWindow();

	test::init();
	atexit(test::term);

	glutMainLoop();
	return 0;
}
