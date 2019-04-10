#include <string>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0; // 정답
	int strike = 0; // strike 비교
	int ball = 0; // ball 비교
	int passCount = 0; // 통과된 횟수 (모든 케이스에 부합하는 확인하기 위함)
	int size = baseball.size(); // size
	string num1 = "";
	string num2 = "";
	for (int i = 123; i <= 987; i++)
	{
		passCount = 0;
		num1 = to_string(i);
		if (num1[0] == num1[1] || num1[0] == num1[2] || num1[1] == num1[2])
			continue;
		else if (num1[0] == '0' || num1[1] == '0' || num1[2] == '0')
			continue;
		for (int j = 0; j < size; j++) {
			strike = 0;
			ball = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					num2 = to_string(baseball[j][0]);
					if (k == l && num1[k] == num2[l])
					{
						strike++;
						continue;
					}
					if (k != l && num1[k] == num2[l]) {
						ball++;
						continue;
					}
				}
			}
			if (baseball[j][1] == strike && baseball[j][2] == ball)
				passCount++;
		}
		if (size == passCount)
			answer++;
	}
	return answer;
}