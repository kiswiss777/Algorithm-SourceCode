#include<iostream>
using namespace std;

int main()
{
	int cycle, input, one, zero, temp;
	cin >> cycle;
	for (int i = 0; i < cycle; i++)
	{
		cin >> input;
		one = 0;
		zero = 1;
		for (int j = 0; j < input; j++)
		{
			temp = one;
			one += zero;
			zero = temp;
		}
		cout << zero << " " << one << endl;
	}
	return 0;
}