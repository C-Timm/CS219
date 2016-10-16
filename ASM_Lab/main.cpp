// Listing: Main.cpp
#include <iostream>
using namespace std;


// External procedure defined in asmfunctions.asm
extern "C" int FindSmallest(int* i, int count);

int MakeData();

int main() {
	

	const unsigned ARRAY_LENGTH = 10;

	int *arr = new int[ARRAY_LENGTH];
	arr[ARRAY_LENGTH] = { MakeData() };
	
		cout << "Smallest is " << FindSmallest(arr, ARRAY_LENGTH) << endl;

	cin.get();
	return 0;
}
int  MakeData() {
	return rand() % (100 - 99) + -99;
}
