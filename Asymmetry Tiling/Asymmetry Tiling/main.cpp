#include<iostream>

using namespace std;

const int divNum = 1000000007;
int square[101] = { 0,1,2, };
int testcase, N;

int main()
{
	for (int i = 3; i <= 100; i++)
		square[i] = (square[i - 1] + square[i - 2]) % divNum;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		if (N <= 2)
			cout << 0 << endl;
		else {
			if (N % 2 == 0)
				cout << ((square[N] + divNum) - (square[N / 2] + square[N / 2 - 1]) % divNum) % divNum << endl;
			else
				cout << (square[N] - square[N / 2]) % divNum << endl;
		}
			
	}
	return 0;
}