#include <string>
#include <stack>
using namespace std;

int solution(string arr) {
	int answer = 0;
	stack<int> sign; // ��ȣ �ִ� ���
	char atArr;
	for (int i = 0; i < arr.size(); i++)
	{
		atArr = arr[i];
		if (atArr == '(')// �����°��� ������ Ǫ��
			sign.push(1);
		else
		{
			sign.pop(); // ������ ������ ��
			if (arr[i - 1] == '(') //�������̴ϱ� ���� �����ŭ ���ϱ�
				answer += sign.size();
			else //�ڱ��ڽ��� �����°��ϱ� 1����
				answer++;
		}
	}
	return answer; // ����
}