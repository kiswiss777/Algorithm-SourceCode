#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
	bool result[1000001] = { false, }; // Bool언으로 체크
	long long min, max, answer, count = 0;
	cin >> min >> max;
	for (long long i = 2; i * i <= max; i++) { 
		long long square = i * i; // 제곱
		long long start = min; // 시작지점
		if (start % square != 0) { // 나머지가 0인경우 수정해서 시작
			start = (start / square + 1) * square;
		}

		for (long long next = start; next <= max; next += square) {
			if (!result[next - min]) {
				result[next - min] = true;
				count++;
			}
		}
	} 
	cout << max - min + 1 - count;
	return 0;
}