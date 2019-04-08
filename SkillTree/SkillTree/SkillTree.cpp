#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	vector<int> orderSkill;
	int size , answer = 0;
	bool possible,exist;
	for (int i = 0; i < skill_trees.size(); i++) {//전체 도는거
		possible = false; //현재 문장이 가능한 문장인가
		orderSkill.clear();// 초기화
		size = skill_trees[i].size();//제일 큰 숫자로 잡는다.
		for (int j = 0; j < skill.size(); j++) { //현재문장의 길이만큼 돌기
			exist = false; // 선행문자가 존재체크
			for(int k=0;k<skill_trees[i].size();k++){
				if (skill[j] == skill_trees[i][k]) {
					exist = true;
					orderSkill.push_back(k);
					break;
				}
			}
			if (!exist) //존재하지 않으면 사이즈만큼 넣어버리기
				orderSkill.push_back(size++); // 전부다 없을 수도 있기때문
		}
		for (int j = orderSkill.size() - 1; j > 0; j--) {
			if (orderSkill[j] - orderSkill[j - 1] < 0) {// 이경우에는 불가능
				possible = false;
				break;
			}
			else
				possible = true;
		}
		if (possible)
			answer++;
	}
	return answer;
}
