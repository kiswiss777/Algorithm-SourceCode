#include<iostream>
#include <cstdio>
#include <cmath>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;


int n, m, A[100], B[100];
const long long NEGINF = numeric_limits<long long>::min(); //최소표현 가능한 int를 리턴
int cache[101][101];
//min(A[indexA],B[indexB]),max(A[indexA],B[indexB])로 시작하는
//합친 증가 부분 수열의 최대 길이를 반효ㅑㄴ.

int JLIS(int indexA, int indexB) {
	int len = cache[indexA + 1][indexB + 1];
	if (len != -1) return len; // 인덱스가 존재하지안으면 리턴
	len = 2;//항상 최소 2의 길이는 가진다
	long long a = (indexA == -1 ? NEGINF : A[indexA]); // 처음에 들어왓을떄 최소값을 주기위함
	long long b = (indexB == -1 ? NEGINF : B[indexB]); // 처음에 들어왓을떄 최소값을 주기위함
	long long maxElement = max(a, b);
	//다음 원소를 찾는다.
	for (int nextA = indexA + 1; nextA < n; nextA++)
		if (maxElement < A[nextA])
			len = max(len, JLIS(nextA, indexB) + 1);
	for (int nextB = indexB + 1; nextB < m; nextB++)
		if (maxElement < B[nextB])
			len = max(len, JLIS(indexA, nextB) + 1);
	return len;
}


int main(void) {
	int cases;
	cin >> cases;
	while (cases--) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int j = 0; j < m; j++)
			cin >> B[j];
		cout << JLIS(-1, -1) - 2 << endl;
	}


	return 0;
}

