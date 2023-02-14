
#include <thread>
#include <mutex>
#include <atomic>

#include "./nvToolsExt.h"

#include "test.h"


// Just some hints on implementation
// You could remove all of them

static std::atomic_int globalTime;
static std::atomic_bool workerMustExit = false;


// some code

void WorkerThread(void)
{
	while (!workerMustExit)
	{
		nvtxRangePush(__FUNCTION__);

		static int lastTime = 0;
		const int time = globalTime.load();
		const int delta = time - lastTime;
		lastTime = time;

		if (delta > 0)
		{
			// some code
		}

		static const int MIN_UPDATE_PERIOD_MS = 10;
		if (delta < MIN_UPDATE_PERIOD_MS)
			std::this_thread::sleep_for(std::chrono::milliseconds(MIN_UPDATE_PERIOD_MS - delta));

		nvtxRangePop();
	}
}


void test::init(void)
{
	// some code

	std::thread workerThread(WorkerThread);
	workerThread.detach(); // Glut + MSVC = join hangs in atexit()

	// some code
}

void test::term(void)
{
	// some code

	workerMustExit = true;

	// some code
}

void test::render(void)
{
	// some code

	// for (size_t i=0; i< .... ; ++i)
	//	platform::drawPoint(x, y, r, g, b, a);

	// some code
}

void test::update(int dt)
{
	// some code

	globalTime.fetch_add(dt);

	// some code
}

void test::on_click(int x, int y)
{
	// some code
}