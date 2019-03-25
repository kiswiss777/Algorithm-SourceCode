#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;

	int total_weight=0, total_movie=0;//무게랑 이동 거리 0으로 초기화 

	for (int i = 0; i < truck_weights.size(); i++) { // 차 갯수만큼만 돌면 된다.
		int current_car_weight = truck_weights[i];

		while (true) {

			if (q.empty()) { //비었을 경우에는 그냥 넣는다
				q.push(current_car_weight);
				total_movie++; // 한칸 이동
				total_weight += current_car_weight;
				break;
			}
			else if (q.size() == bridge_length) { // 길이가 같으면 팝해야한다.
				total_weight -= q.front(); q.pop();
			}
			else {

				if (total_weight + current_car_weight > weight) { // 더 이상 넣지못한다면 0으로 채운다
					q.push(0);
					total_movie++; // 이동
				}
				else {
					q.push(current_car_weight);
					total_movie++; //이동
					total_weight += current_car_weight; //무게를 더한다
					break;
				}
			}
		}
	}
	return total_movie + bridge_length;//마지막 자동차를 다리길이만큼 이동
}
