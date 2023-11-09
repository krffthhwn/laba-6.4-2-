#include<iostream>
#include<iomanip>
#include <time.h>

using namespace std;

void Input(double* q, const int size, int i)
{
	cout << "q[" << i << "] = ";
	cin >> q[i];
	if (i < size - 1)
		Input(q, size, i + 1);
	else
		cout << endl;
}
void Print(double* q, const int size, int i)
{
	cout << setw(8) << fixed << setprecision(3) << q[i];
	if (i < size - 1)
		Print(q, size, i + 1);
	else
		cout << endl;
}
double Max(double* q, const int size, int i, double max)
{
	if (fabs(q[i]) > fabs(max))
		max = q[i];
	if (i < size - 1)
		return Max(q, size, i + 1, max);
	else
		return max;
}
int Find(double* q, const int size, int i)
{
	if (i >= size) {
		return -1;
	}
	else
	{
		if (q[i] > 0) {
			return i;
		}
		return Find(q, size, i + 1);
	}
}
double Sum(double* q, const int size, int first, int second, int i, double v)
{
	if (i < size) 
	{
		if (i > first && i < second) 
		{
			v += q[i];
		}
		return Sum(q, size, first, second, i + 1, v);
	}
	return v;
}
void Sort(double* q, const int size, int i, int j, int& c)
{ 
	if (q[j] == 0) 
	{ 
		int tmp = q[j];
		q[j] = q[j + 1];
		q[j + 1] = tmp;
		c = 1;
	}
	if (j < size - i - 1) 
		Sort(q, size, i, j + 1, c); 
	if (c == 0) 
		return; 
	if (i < size - 1) 
	{
		c = 0; 
		Sort(q, size, i + 1, 0, c); 
	}
}
int main()
{
	int s;
	cout << "s = "; cin >> s;
	double* d = new double[s];
	int c = 0;
	Input(d, s, 0);

	cout << "q[s] =";
	Print(d, s, 0);
	cout << "module max = " << Max(d, s, 0, d[0]) << endl;
	int first = Find(d, s, 0);
	int second = Find(d, s, first + 1);

	cout << "S = " << Sum(d, s, first, second, 0, 0) << endl;

	Sort(d, s, 1, 0, c);
	cout << "d[s] =";
	Print(d, s, 0);
	delete[] d;
	return 0;
}