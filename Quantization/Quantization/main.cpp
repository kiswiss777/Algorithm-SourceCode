#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF = 987654321;
vector<int> sequenceArr;
vector<int> pSum;
vector<int> pSqSum;
int cache[101][11];
int sequenceLength;

void precalc() // 미리 부분합 + 정렬
{
	sort(sequenceArr.begin(), sequenceArr.end());
	pSum.push_back(sequenceArr[0]);
	pSqSum.push_back(sequenceArr[0] * sequenceArr[0]);
	for (int i = 1; i < sequenceLength; i++) {
		pSum.push_back(pSum[i - 1] + sequenceArr[i]);
		pSqSum.push_back(pSqSum[i - 1] + sequenceArr[i] * sequenceArr[i]);
	}
}

int minError(int lo, int hi) // 구간 계산을 통해서 가장적은 오류의 값을 계산한다.
{
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m *sum + m * m *(hi - lo + 1);
	return ret;
}

int quantize(int from, int parts) // 양자화
{
	if (from == sequenceLength) return 0;
	if (parts == 0) return INF;
	int &ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	for (int partSize = 1; from + partSize <= sequenceLength; partSize++)
		ret = min(ret, minError(from, from + partSize - 1)
			+ quantize(from + partSize, parts - 1));
	return ret;
}

int main()
{
	int testcase, to_use_Number, input;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		for (int j = 0; j < 101; j++)
			memset(cache[j], -1, sizeof(int) * 11);
		cin >> sequenceLength >> to_use_Number;
		for (int j = 0; j < sequenceLength; j++)
		{
			cin >> input;
			sequenceArr.push_back(input);
		}
		precalc();
		cout << quantize(0, to_use_Number) << endl;
		sequenceArr.clear();
		pSum.clear();
		pSqSum.clear();
	}
	return 0;
}