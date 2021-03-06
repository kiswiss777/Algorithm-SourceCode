#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> korea, russia,answer;

int getAnswer(int player_num)//매개변수 굳이 필요없고
{
	int r_index = 0, k_index, start = 0; // multiset 알아보기
	int answer = 0;
	while (r_index < player_num) {
		k_index = player_num;
		for (int i = start; i < player_num; i++) {
			if (russia[r_index] <= korea[i]) { // 굳이 다돌필요없다.(while 거꾸로)
				if (k_index > i) 
					k_index = i; // lowerbound
			}
		}
		if (k_index != player_num) {
			korea[k_index] = -1;
			answer++;
		}
		else
			start++;
		r_index++;

	}
	return answer;
}

int main()
{
	int testcase,player_num,rating;
	cin >> testcase;
	while (testcase--) {
		cin >> player_num;
		for (int i = 0; i < player_num; i++) {
			cin >> rating;
			russia.push_back(rating);
		}
		for (int i = 0; i < player_num; i++) {
			cin >> rating;
			korea.push_back(rating);
		}
		sort(korea.begin(), korea.end());
		answer.push_back(getAnswer(player_num));
		korea.clear();
		russia.clear();
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	return 0;
}