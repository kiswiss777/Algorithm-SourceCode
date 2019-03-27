#include<iostream>
#include <cstdio>
#include <cmath>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;


int n, m, A[100], B[100];
const long long NEGINF = numeric_limits<long long>::min();
int cache[101][101];
//min(A[indexA],B[indexB]),max(A[indexA],B[indexB])�� �����ϴ�
//��ģ ���� �κ� ������ �ִ� ���̸� ��ȯ�ϳ�.
//�� indexA==indexB==-1 Ȥ�� A[indexA] !=B[indexB] ��� �����Ѵ�.

int jlis(int indexA, int indexB) {
	//�޸����̼�
	int &ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	//A[indexA],B[indexB]�� �̹� �����ϹǷ� 2���� �׻� �ִ�.
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	//���� ���Ҹ� ã�´�.
	for (int nextA = indexA + 1; nextA < n; nextA++)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	for (int nextB = indexB + 1; nextB < m; nextB++)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	return ret;
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
		cout << jlis(-1, -1) - 2 << endl;
	}


	return 0;
}

