#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	vector<int> answer; // 정답을 담을 배열
	int square[101] = { 0,1,2, }; // 사각형 N마다 가능한 경우의 수
	int testcase, N;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> N;
		for (int j = 3; j <= N; j++)
			square[j] = (square[j - 1] + square[j - 2]) % 1000000007; //점화식 문제에 1000000007로 나눈 나머지라는 말이 있다.

		answer.push_back(square[N]); // 결과값을 answer에 담는다
	}
	for (int i = 0; i < testcase; i++)
		cout << answer[i] << endl;

	return 0;
}