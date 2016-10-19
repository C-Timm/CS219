// Listing: Main.cpp

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;


// External procedure defined in asmfunctions.asm

extern "C" int FindSmallest(int* i, int count);
int MakeData();

int main() {
	srand(time(NULL));
	const unsigned ARRAY_LENGTH = 350000000;

	int* arr = new int[ARRAY_LENGTH];

	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		arr[i] = { MakeData() };
	}

	//cout << "Smallest is " << FindSmallest(arr, ARRAY_LENGTH) << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();  //starts timer
	int smallest = FindSmallest(arr, ARRAY_LENGTH);
	end = std::chrono::system_clock::now();		//ends timer
	std::chrono::duration<double> elapsed_seconds = end - start;
	
	cout << "Smallest is " << smallest << " and took " << elapsed_seconds.count() << " seconds"  << endl;
	cin.get();

	return 0;
}

int  MakeData() {
	return (rand() % 198) - 99;
}
