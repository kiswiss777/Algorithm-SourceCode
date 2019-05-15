#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX_SIZE 51

double dp[101][MAX_SIZE] = {0,};
double probability[MAX_SIZE][MAX_SIZE] = { 0, };
int village[MAX_SIZE][MAX_SIZE];
int testcase, vilage_count, day, prison_number, probability_count, vilage_index, result_count;

void clearArr()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 51; j++)
			dp[i][j] = 0;
	for(int i=0;i<51;i++)
		for (int j = 0; j < 51; j++)
			probability[i][j] = 0;
}

void calProbabilty()
{
	double sum = 0;
	for (int d = 1; d <= day; d++)
	{
		for (int i = 0; i < vilage_count; i++)
		{
			for (int j = 0; j < vilage_count; j++)
				sum += dp[d - 1][j] * probability[j][i];
			dp[d][i] = sum;
			sum = 0;
		}
	}
}

void outputHandler(int result_count)
{
	for (int i = 0; i < result_count; i++)
	{
		int vilage_index;
		cin >> vilage_index;
		cout << fixed;
		cout.precision(8);
		cout << dp[day][vilage_index] << " ";
	}
	cout << endl;
}

void inputHandler() // ioHandler
{
	for (int i = 0; i < vilage_count; i++)
	{
		int cnt = 0;
		for (int j = 0; j < vilage_count; j++)
		{
			cin >> village[i][j];
			if (village[i][j])
				cnt++;
		}
		for (int j = 0; j < vilage_count; j++)
		{
			if (village[i][j])
				probability[i][j] = (double)1 / (double)cnt;
		}
	}
}

int main()
{
	cin >> testcase;
	while (testcase--)
	{
		clearArr();
		cin >> vilage_count >> day >> prison_number;
		inputHandler();
		dp[0][prison_number] = 1;
		calProbabilty();
		cin >> result_count;
		outputHandler(result_count);
	}
	return 0;
}