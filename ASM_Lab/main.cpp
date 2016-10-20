#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;


// External procedure defined in asmfunctions.asm

extern "C" int FindSmallest(int* i, int count);
int MakeData();
int find(int* a,int c);

int main() {

	srand(time(NULL));
	const unsigned ARRAY_LENGTH = 35000000;

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


	int* ar1= new int[ARRAY_LENGTH];
	
	for (int j = 0; j < ARRAY_LENGTH; j++)
	{
		ar1[j] = { MakeData() };
	}

	//std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	int min;
	for (int j = 0; j < ARRAY_LENGTH; j++)
	{
		if (ar1[j] = -99)
		{
			min = ar1[j];
		}
	}
	//int small1 = find(ar1,ARRAY_LENGTH);
	end= std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds_C = end - start; 


	cout << "Smallest is " << smallest << " and the Asm code took " << elapsed_seconds.count() << " seconds" << endl;

	cout << "Smallest is " << min << " and it took the C code " << elapsed_seconds_C.count() << " seconds" << endl;

	cin.get();

	return 0;
}

int  MakeData() {
	return (rand() % 198) - 99;
}

/*
int find(int a[],int c)
{
	int min;
	for (int j = 0; j < c; j++)
	{
		if (a[j] = -99)
		{
			min = a[j];
		}
	}
	return min;
}
*/
