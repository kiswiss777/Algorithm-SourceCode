#include<iostream>
#include<cstdio>
#include<cstring>

int poly[101][101] = { 0 };
const int MOD = 10000000;

using namespace std;

int getPOLY(int nums, int down)
{
	int& ret = poly[nums][down];

	if (nums == down)
	{
		return ret = 1;
	}

	if (ret != -1) return ret;

	ret = 0;

	int blocks = nums - down;
	for (int i = 1; i <= blocks; i++)
	{
		ret += (i + down - 1) * getPOLY(blocks, i);
		ret %= MOD;
	}

	return ret;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 102; i++)
			for (int j = 0; j < 102; j++)
				poly[i][j] = -1;

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res += getPOLY(n, i);
			res %= MOD;
		}

		cout << res << endl;
	}

	return 0;
}
