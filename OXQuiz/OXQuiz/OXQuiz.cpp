#include <iostream>
#include <string>

using namespace std;

int main()
{
	int input;
	cin >> input;
	string ox;
	int count;
	int result[10000];
	int add;
	int temp;
	for (int i = 0; i < input; i++)
	{
		count = 0;
		add = 0;
		cin >> ox;
		for (int j = 0; j < ox.length() + 1; j++)
		{
			char cr = ox[j];
			switch (cr)
			{
			case 'O':
				count++;
				break;
			case 'X':
				temp = 0;
				for (int i = 0; i < count; i++)
				{
					temp += i + 1;
				}
				add += temp;
				count = 0;
				break;
			default:
				temp = 0;
				for (int i = 0; i < count; i++)
				{
					temp += i + 1;
				}
				add += temp;
			}
		}
		result[i] = add;
	}
	for (int i = 0; i < input; i++)
		printf("%d\n", result[i]);

	return 0;
}
