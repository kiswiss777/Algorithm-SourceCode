#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	const int size = prices.size();

	for (int i = 0; i < size; i++) {

		int checkValue = prices[i]; // Check ����
		int predictStock = 0; // �ֽ� ����
		for (int j = i; j < size - 1; j++) {
			if (checkValue <= prices[j]) {
				predictStock++; // ������ũ�⶧���� �ȶ�������
			}
			else {
				break;
			}
		}
		answer.push_back(predictStock); //�������� ������� �ִ´�.
	}
	return answer;
}
