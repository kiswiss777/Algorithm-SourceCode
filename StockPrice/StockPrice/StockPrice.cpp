#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	const int size = prices.size();

	for (int i = 0; i < size; i++) {

		int checkValue = prices[i]; // Check 가격
		int predictStock = 0; // 주식 예측
		for (int j = i; j < size - 1; j++) {
			if (checkValue <= prices[j]) {
				predictStock++; // 내보다크기때문에 안떨어진다
			}
			else {
				break;
			}
		}
		answer.push_back(predictStock); //예측값을 결과값에 넣는다.
	}
	return answer;
}
