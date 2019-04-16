#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

const int INF = 999999999;
int dp[10001];
using namespace std;

int getThreePoint(int num, string piArr) // 3개 짜리 경우
{
	int point = 10;
	int one = piArr.at(num - 2) - '0';
	int two = piArr.at(num - 1) - '0';
	int three = piArr.at(num) - '0';
	if ((one == two) && (two == three))
		point = 1;
	else if ((one + 2 == two + 1) && (two + 1 == three))
		point = 2;
	else if ((one == two + 1) && (two + 1 == three + 2))
		point = 2;
	else if (one == three)
		point = 4;
	else if (one - two == two - three)
		point = 5;
	return point;
}

int getFourPoint(int num, string piArr) //4개 짜리 경우
{
	int point = 10;
	int one = piArr.at(num - 3) - '0';
	int two = piArr.at(num - 2) - '0';
	int three = piArr.at(num - 1) - '0';
	int four = piArr.at(num) - '0';
	if ((one == two) && (two == three) && (three == four))
		point = 1;
	else if ((one + 3 == two + 2) && (two + 2 == three + 1) && (three + 1 == four))
		point = 2;
	else if ((one == two + 1) && (two + 1 == three + 2) && (three + 2 == four + 3))
		point = 2;
	else if ((one == three) && (two == four))
		point = 4;
	else if ((one - two == two - three) && (two - three == three - four))
		point = 5;
	return point;
}

int getFivePoint(int num, string piArr) //5개 짜리 경우
{
	int point = 10;
	int one = piArr.at(num - 4) - '0';
	int two = piArr.at(num - 3) - '0';
	int three = piArr.at(num - 2) - '0';
	int four = piArr.at(num - 1) - '0';
	int five = piArr.at(num) - '0';
	if ((one == two) && (two == three) && (three == four) && (four == five))
		point = 1;
	else if ((one + 4 == two + 3) && (two + 3 == three + 2) && (three + 2 == four + 1) && (four + 1 == five))
		point = 2;
	else if ((one == two + 1) && (two + 1 == three + 2) && (three + 2 == four + 3) && (four + 3 == five + 4))
		point = 2;
	else if ((one == three) && (three == five) && (two == four))
		point = 4;
	else if ((one - two == two - three) && (two - three == three - four) && (three - four == four - five))
		point = 5;
	return point;
}

int main()
{
	string piArr;
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin >> piArr;
		dp[0] = dp[1] = INF;
		dp[2] = getThreePoint(2, piArr);
		dp[3] = getFourPoint(3, piArr);
		dp[4] = getFivePoint(4, piArr);
		dp[5] = dp[2] + getThreePoint(5, piArr);
		dp[6] = dp[2] + getFourPoint(6, piArr) < dp[3] + getThreePoint(6, piArr) ? dp[2] + getFourPoint(6, piArr) : dp[3] + getThreePoint(6, piArr); // for문 전작업
		for (int j = 7; j < piArr.size(); j++)
		{
			int temp = min(dp[j - 3] + getThreePoint(j, piArr), dp[j - 4] + getFourPoint(j, piArr));
			temp = min(temp, dp[j - 5] + getFivePoint(j, piArr));
			dp[j] = temp;
		}
		cout << dp[piArr.size() - 1] << endl;
	}

	return 0;
}