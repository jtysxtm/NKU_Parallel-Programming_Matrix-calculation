#include<iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;

const int N = 10000;
double sum;
double a[N];




void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}



int main()
{
	long long head, tail, freq; // timers
	int n = 10000;
	int number = 3000;
	init(n);
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	while (number > 0)
	{
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		number--;
	}

	// end time
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	cout << "Col: " << (tail - head) * 1000.0 / freq  << endl;
	return 0;
}
