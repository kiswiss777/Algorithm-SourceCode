#include<vector>
#include<iostream>

using namespace std;

vector<int> arr, order; // 입력받는값 , 저장되어 있는 값
int testcase, N, input;

void moveArr(int n) { // 배열이동시켜주기 
	int at_index = order[n]; // 해당 인덱스
	int start = n - at_index; // n- index 부터 시작
	int at_value = arr[start]; // 해당 인덱스 값 저장
	for (int i = start; i < n ; i++)
		arr[i] = arr[i + 1]; // 이동시키기
	arr[n] = at_value; // 그자리에 at_value 넣으면 끝
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
		order.clear(); // 계속해서 입력받기때문에
		arr.clear(); 
		cout << endl;
	}
}