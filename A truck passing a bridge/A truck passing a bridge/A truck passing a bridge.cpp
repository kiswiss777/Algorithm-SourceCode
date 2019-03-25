#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;

	int total_weight=0, total_movie=0;//���Զ� �̵� �Ÿ� 0���� �ʱ�ȭ 

	for (int i = 0; i < truck_weights.size(); i++) { // �� ������ŭ�� ���� �ȴ�.
		int current_car_weight = truck_weights[i];

		while (true) {

			if (q.empty()) { //����� ��쿡�� �׳� �ִ´�
				q.push(current_car_weight);
				total_movie++; // ��ĭ �̵�
				total_weight += current_car_weight;
				break;
			}
			else if (q.size() == bridge_length) { // ���̰� ������ ���ؾ��Ѵ�.
				total_weight -= q.front(); q.pop();
			}
			else {

				if (total_weight + current_car_weight > weight) { // �� �̻� �������Ѵٸ� 0���� ä���
					q.push(0);
					total_movie++; // �̵�
				}
				else {
					q.push(current_car_weight);
					total_movie++; //�̵�
					total_weight += current_car_weight; //���Ը� ���Ѵ�
					break;
				}
			}
		}
	}
	return total_movie + bridge_length;//������ �ڵ����� �ٸ����̸�ŭ �̵�
}
