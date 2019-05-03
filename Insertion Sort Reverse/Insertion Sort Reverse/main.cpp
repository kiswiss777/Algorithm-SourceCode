#include<vector>
#include<iostream>

using namespace std;

vector<int> arr, order; // �Է¹޴°� , ����Ǿ� �ִ� ��
int testcase, N, input;

void moveArr(int n) { // �迭�̵������ֱ� 
	int at_index = order[n]; // �ش� �ε���
	int start = n - at_index; // n- index ���� ����
	int at_value = arr[start]; // �ش� �ε��� �� ����
	for (int i = start; i < n ; i++)
		arr[i] = arr[i + 1]; // �̵���Ű��
	arr[n] = at_value; // ���ڸ��� at_value ������ ��
}


int main(){
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			order.push_back(input);
			arr.push_back(i + 1);
		}
		for (int i = N-1; i > 0; i--)
			moveArr(i);
		for (int i = 0; i < N; i++)
			cout << arr[i] << ' ';
		order.clear(); // ����ؼ� �Է¹ޱ⶧����
		arr.clear(); 
		cout << endl;
	}
}