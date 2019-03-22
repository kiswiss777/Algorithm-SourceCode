#include<iostream>
using namespace std;


int main()
{
	int coin_num;
	int coin_total;

	int coins[100];


	int min_coins_num[10001];

	cin >> coin_num >> coin_total;

	for (int i = 0; i < coin_num; i++) {
		cin >> coins[i];
	}

	min_coins_num[0] = 0;
	for (int i = 1; i <= coin_total; i++) {

		int min = 10001;
		for (int j = 0; j < coin_num; j++) {
			if (i - coins[j] < 0) continue;
			else {
				if (min_coins_num[i - coins[j]] < 0) continue;
				if (min_coins_num[i - coins[j]] + 1 < min) {
					min = min_coins_num[i - coins[j]] + 1;
				}
			}
		}
		if (min < 10001)
			min_coins_num[i] = min;
		else
			min_coins_num[i] = -1;
	}

	cout << min_coins_num[coin_total];
	return 0;
}