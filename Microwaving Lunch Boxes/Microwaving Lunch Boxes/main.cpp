#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

const int MAX = 10000; 
int boxNum;
vector<int> eat_t, micro_t;

int microwave(void)
{
	vector<pair<int, int>> order;
	for (int i = 0; i < boxNum; i++)
		order.push_back(make_pair(-eat_t[i], i));
	
	sort(order.begin(), order.end());
	
	int answer = 0, start_e= 0;  
	for (int i = 0; i < boxNum; i++)
	{
		int box = order[i].second;
		start_e += micro_t[box];
		answer = max(answer, start_e + eat_t[box]);
	}
	return answer;
}

int main(void)
{
	int test_case, input;
	cin >> test_case;

	while(test_case--)
	{
		cin >> boxNum;
		for (int j = 0; j < boxNum; j++) {
			cin >> input;
			micro_t.push_back(input);
		}
		for (int j = 0; j < boxNum; j++) {
			cin >> input;
			eat_t.push_back(input);
		}
		cout << microwave() << endl;
		micro_t.clear();
		eat_t.clear();
	}
	return 0;
}