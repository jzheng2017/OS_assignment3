/**
  * Assignment: memory
  * Operating Systems
  */

// function/class definitions you are going to use
#include <sys/resource.h>
#include <sys/time.h>

#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// although it is good habit, you don't have to type 'std::' before many objects by including this line
using namespace std;

// size of the image
const int SIZE = 1048577;

int main(int argc, char* argv[]) {
	float* res = new float[SIZE * SIZE];  // result of mean filter
	float* img = new float[SIZE * SIZE];

	auto start = std::chrono::steady_clock::now();

	// fill with dummy data
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			img[j * SIZE + i] = (2 * j + i) % 8196;
		}
	}

	// do the filter
	for (int i = 1; i < SIZE - 1; i++) {
		for (int j = 1; j < SIZE - 1; j++) {
			res[j * SIZE + i] = 0;
			for (int k = -1; k < 2; k++) {
				for (int l = -1; l < 2; l++) {
					res[j * SIZE + i] += img[(j + l) * SIZE + i + k];
				}
			}
			res[j * SIZE + i] /= 9;
		}
	}
	auto finish = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << "image of size " << SIZE << " took " << elapsed.count() << " ms" << std::endl;

	delete[] img;
	delete[] res;

	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);

	std::cout << usage.ru_minflt << std::endl;
	std::cout << usage.ru_maxrss << std::endl;
	std::cout << usage.ru_nvcsw << std::endl;
	std::cout << usage.ru_nivcsw << std::endl;
	// ...
	return 0;
}
