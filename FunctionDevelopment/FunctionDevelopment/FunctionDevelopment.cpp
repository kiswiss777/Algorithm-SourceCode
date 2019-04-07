#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer, temp; // 정답,임시공간
	int progress, distribute_period, answer_index = 0; //현재진행상황
	for (int i = 0; i < progresses.size(); i++) {
		progress = progresses[i];
		distribute_period = 0;
		while (progress < 100) {
			progress += speeds[i];
			distribute_period++;
		}
		temp.push_back(distribute_period);
	}
	int maxValue, count_Day = 1;// 큰값을 계속해서 가지면서 큰날에 배포하는 작업수 증가, count_Day 로 체크
	if (temp.size() != 0) { // 첫번째는넣고 시작
		maxValue = temp[0];
		answer.push_back(count_Day);
	}
	for (int i = 1; i < temp.size(); i++) { // 그 이후의 작업들
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