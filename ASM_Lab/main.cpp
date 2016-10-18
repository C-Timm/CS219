// Listing: Main.cpp
#include <iostream>
#include <ctime>
using namespace std;


// External procedure defined in asmfunctions.asm
extern "C" int FindSmallest(int* i, int count);

int MakeData();


int main() {

	srand(time(NULL));
	const unsigned ARRAY_LENGTH = 10000000;

	int* arr = new int[ARRAY_LENGTH];

	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		arr[i] = { MakeData() };
	
	}
	cout << "Smallest is " << FindSmallest(arr, ARRAY_LENGTH) << endl;

	cin.get();
	return 0;
}
int  MakeData() {
	
	return (rand() % 198) -99;
}
