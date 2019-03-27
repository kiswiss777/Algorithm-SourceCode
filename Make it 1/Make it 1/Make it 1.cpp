#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n+1]; // 동적 배열 생성
	arr[1] = 0;
	for (int i = 2; i <= n; i++) // DP 방식을 이용해서 계속해서 Check
	{
		arr[i] = arr[i-1] + 1; // 그전꺼에서 무조건 -1만하면가능하기때문에 +1후 체크
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1); // 둘중에 최솟값으로 저장
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