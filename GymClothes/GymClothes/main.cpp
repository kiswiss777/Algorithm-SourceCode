#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for(int i=0;i<lost.size();i++)
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j]) {
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
			}
		}
	answer = n - lost.size();
	for (int i = 0; i < lost.size(); i++)
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] - reserve[j] == 1 || lost[i] - reserve[j] == -1)
			{
				reserve.erase(reserve.begin() + j);
				answer++;
			}
		}
	return answer;
}