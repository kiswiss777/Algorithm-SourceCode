#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> str;

int get_answer()
{
	int answer = 0;
	while (str.size() != 1) {
		sort(str.begin(), str.end());
		answer += str[0] + str[1];
		str[0] = str[0] + str[1];
		str.erase(str.begin() + 1);
	}
	return answer;
}

int main()
{
	int testcase, str_l, input;
	cin >> testcase;
	while (testcase--) {
		cin >> str_l;
		for (int i = 0; i < str_l; i++) {
			cin >> input;
			str.push_back(input);
		}
		cout << get_answer() << endl;
		str.clear();
	}
}