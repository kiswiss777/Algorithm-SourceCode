#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	vector<int> orderSkill;
	int size , answer = 0;
	bool possible,exist;
	for (int i = 0; i < skill_trees.size(); i++) {//��ü ���°�
		possible = false; //���� ������ ������ �����ΰ�
		orderSkill.clear();// �ʱ�ȭ
		size = skill_trees[i].size();//���� ū ���ڷ� ��´�.
		for (int j = 0; j < skill.size(); j++) { //���繮���� ���̸�ŭ ����
			exist = false; // ���๮�ڰ� ����üũ
			for(int k=0;k<skill_trees[i].size();k++){
				if (skill[j] == skill_trees[i][k]) {
					exist = true;
					orderSkill.push_back(k);
					break;
				}
			}
			if (!exist) //�������� ������ �����ŭ �־������
				orderSkill.push_back(size++); // ���δ� ���� ���� �ֱ⶧��
		}
		for (int j = orderSkill.size() - 1; j > 0; j--) {
			if (orderSkill[j] - orderSkill[j - 1] < 0) {// �̰�쿡�� �Ұ���
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
