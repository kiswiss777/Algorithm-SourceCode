#include<iostream>

using namespace std;

int main()
{
	int n,num,answer=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		num = i;
		while (num >= 10) {
			if (num % 10 == 8) {
				answer++;
				num /= 10;
			}
			else {
				num /= 10;
				continue;
			}
		}
		if (num == 8)
			answer++;
	}
	cout << answer;
	return 0;
}