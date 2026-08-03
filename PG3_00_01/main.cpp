#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
uint32_t current_turn = 1;

void PrintThread(uint32_t num) {

	unique_lock<mutex> lock(mtx);
	cv.wait(lock, [num] { return current_turn == num; });

	cout << "thread" << num << endl;

	current_turn++;
	cv.notify_all();
}

int main() {

	thread t1(PrintThread, 1);
	thread t2(PrintThread, 2);
	thread t3(PrintThread, 3);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}