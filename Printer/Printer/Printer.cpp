#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<list>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> que;
	priority_queue<int> priQue;
	for (int i = 0; i < priorities.size(); i++) {
		// ť�� <ó�� ����� ����, �۾� �߿䵵> push
		que.push(make_pair(i, priorities[i]));
		// �켱���� ť�� �۾� �߿䵵 push(�ڵ������� �������� ������ �Ǿ� �񱳿����� ����)
		priQue.push(priorities[i]);
	}
	while (!que.empty()) {
		// ���� �۾� ť�� front�� �켱���� ť�� �μ� �߿䵵�� ������ ���(��¼����� ���� ��)
		if (que.front().second == priQue.top()) {
			// �������� ��û�� ������ȣ�� ���� �۾� ť�� front.first �� �ִ� ����� ������ ��ġ �� ���
			if (que.front().first == location) {
				return answer + 1;
			}
			else {
				// ����۾� �� �۾� ť�� �켱���� ť���� ������ �ϳ��� pop
				answer++;
				que.pop();
				priQue.pop();
			}
		}
		else {
			// ��¼����� �ƴϹǷ� front�� �ִ� ���� ť�� �� �ڷ� �̵���Ű�� �۾�
			que.push(que.front());
			que.pop();
		}
	}
	return answer;
}