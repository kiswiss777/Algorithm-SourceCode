#include <string>
#include <stack>
using namespace std;

int solution(string arr) {
	int answer = 0;
	stack<int> sign; // 부호 넣는 방법
	char atArr;
	for (int i = 0; i < arr.size(); i++)
	{
		atArr = arr[i];
		if (atArr == '(')// 열리는경우는 무조건 푸쉬
			sign.push(1);
		else
		{
			sign.pop(); // 닫히면 무조건 팝
			if (arr[i - 1] == '(') //레이저이니깐 앞의 사이즈만큼 더하기
				answer += sign.size();
			else //자기자신이 닫히는경우니깐 1개만
				answer++;
		}
	}
	return answer; // 정답
}