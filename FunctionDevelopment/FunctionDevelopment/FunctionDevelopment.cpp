#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer, temp; // ����,�ӽð���
	int progress, distribute_period, answer_index = 0; //���������Ȳ
	for (int i = 0; i < progresses.size(); i++) {
		progress = progresses[i];
		distribute_period = 0;
		while (progress < 100) {
			progress += speeds[i];
			distribute_period++;
		}
		temp.push_back(distribute_period);
	}
	int maxValue, count_Day = 1;// ū���� ����ؼ� �����鼭 ū���� �����ϴ� �۾��� ����, count_Day �� üũ
	if (temp.size() != 0) { // ù��°�³ְ� ����
		maxValue = temp[0];
		answer.push_back(count_Day);
	}
	for (int i = 1; i < temp.size(); i++) { // �� ������ �۾���
		if (temp[i] > maxValue) {
			maxValue = temp[i];
			answer_index++;
			count_Day = 1;
			answer.push_back(count_Day);
		}
		else {
			count_Day++;
			answer[answer_index] = count_Day;
		}

	}
	return answer;
}