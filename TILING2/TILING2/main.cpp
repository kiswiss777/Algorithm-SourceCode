#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	vector<int> answer; // ������ ���� �迭
	int square[101] = { 0, }; // �簢�� N���� ������ ����� ��
	square[1] = 1; // 1 = 1
	square[2] = 2; // 2 = 2
	int testcase, N;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> N;
		for (int j = 3; j <= N; j++)
			square[j] = (square[j - 1] + square[j - 2]) % 1000000007; //��ȭ�� ������ 1000000007�� ���� ��������� ���� �ִ�.

		answer.push_back(square[N]); // ������� answer�� ��´�
	}
	for (int i = 0; i < testcase; i++)
		cout << answer[i] << endl;

	return 0;
}