#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n+1]; // ���� �迭 ����
	arr[1] = 0;
	for (int i = 2; i <= n; i++) // DP ����� �̿��ؼ� ����ؼ� Check
	{
		arr[i] = arr[i-1] + 1; // ���������� ������ -1���ϸ鰡���ϱ⶧���� +1�� üũ
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1); // ���߿� �ּڰ����� ����
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}
	cout << arr[n];
	return 0;
}

/*
int caculate(int n, int answer)
{
	if (n == 1)
		return answer;
	answer++;
	if (n % 3 == 0)
		caculate(n / 3,answer);
	else if (n % 3 == 1)
		caculate(n - 1,answer);
	else if (n % 2 == 0)
		caculate(n / 2,answer);
	else
		caculate(n - 1,answer);

}

int main()
{
	int n;
	cin >> n;
	int answer = 0;
	answer = caculate(n,answer);
	cout << answer;

	return 0;
}
*/