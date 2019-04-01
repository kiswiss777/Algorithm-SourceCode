#include <iostream>
#include<string>
using namespace std;

int main()
{
	int input;
	int result = 0;
	cin >> input;
	if (input < 3 || input >5000)
		return -1;
	else
	{
		int n1 = input / 5;
		for (int i = 0; i <= n1; i++)
		{
			int temp = input - 5 * i;
			if (temp % 3 == 0)
				result = temp / 3 + i;
		}
		if (result == 0)
			cout << -1;
		else
			cout << result;
	}
	return 0;
}
