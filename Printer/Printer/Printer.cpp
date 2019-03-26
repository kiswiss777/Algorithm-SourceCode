#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0, maxNum = 0,j;
	vector<int> ascending = priorities;
	sort(ascending.begin(), ascending.end());
	vector<int> current_priorities;
	for (int i = 0; i < priorities.size(); i++)
	{
		for (j = i; j < priorities.size(); j++)
		{
			if (ascending[i] == priorities[j])
			{
				answer++;
				break;
			}
		}
	}

	return answer;
}