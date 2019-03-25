#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size());
	answer[0] = 0;
	for (int i = heights.size() - 1; i > 0; i--)
	{
		int temp = heights[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (temp < heights[j])
			{
				answer[i] = j + 1;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	int n,input;
	cin >> n;
	vector<int> heights(n);
	vector<int> answer;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		
	}

	answer = solution(heights);
	for (int i = 0; i < n; i++)
		cout << answer[i] << endl;
}