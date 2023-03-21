#include<iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;

const int N = 10000;
double a[N];
double sum1, sum2;
double sum;

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void solve2(int n)
{
	for (int i = 0; i < n; i += 2)
	{
		sum1+= a[i]; 
		sum2+= a[i + 1];
	}
	sum = sum1 + sum2;
	return;
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
	while (number--)
	{
		solve2(n);
		
	}


	// end time
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	cout << "Col: " << (tail - head) * 1000.0 / freq << endl;
	return 0;
}
