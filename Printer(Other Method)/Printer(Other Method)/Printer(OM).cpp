#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<list>
#include<iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> sortlist = priorities;
	queue<int> pri;
	sort(sortlist.begin(), sortlist.end(),greater<int>());
	for (int i = 0; i < priorities.size(); i++)
		pri.push(priorities[i]);
	int sort_index = 0;
	while (true) {

		int first = pri.front();
		if (first == sortlist[sort_index]) {
			answer++;
			if (location == 0)
				break;
			else
				location--;
			sort_index++;
			pri.pop();
		}
		else {
			while (first != sortlist[sort_index])
			{
				if (location == 0)
					location = pri.size() - 1;
				else
					location--;
				int temp = pri.front();
				pri.pop();
				pri.push(temp);
				first = pri.front();
			}
		}
	}
	return answer;
}

int main() {
	int location, n;
	cin >> n >> location;
	vector<int> pri;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		pri.push_back(input);
	}
	int answer = solution(pri, location);
	cout << answer;
	return -1;
}