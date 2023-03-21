#include<iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;

const int N = 1000;
double sum[N];
double b[N][N], a[N];


void init(int n)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			b[i][j] = i + j;
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
	}
}//´´½¨


int main()
{
	long long head, tail, freq; // timers
	init(N);
	int n = 1000;
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER *) & freq);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER *) & head);

	int number = 100;
	while (number>0)
	{
		for (int i = 0; i < n; i++)
		{
			sum[i] = 0.0;
			for (int j = 0; j < n; j++)
			{
				sum[i] += b[j][i] * a[j];
			}
		}
		number--;
	}
	// end time
		QueryPerformanceCounter((LARGE_INTEGER *) & tail);
	cout << "Col: " << (tail - head) * 1000.0 / freq<<  endl;


	return 0;
}


