#include <string>
#include <vector>
#include <math.h>
#include<iostream>

using namespace std;

string solution(int n) {
	string answer = "";
	string list[3]{ "4", "1", "2" };

	while (n > 0) {
		int remain = n % 3;
		string tmp = list[remain];
		n /= 3;

		if (remain == 0) {
			n -= 1;
		}

		answer = tmp + answer;
	}
	return answer;
}

int main()
{
	int input;
	cin >> input;
	string answer = solution(input);
	cout << answer;
}