#include iostream
#include algorithm
using namespace std;

int sTestcase;  �׽�Ʈ ���� �Է� �׽�Ʈ ����
int arr[501];  �迭������
int check[501] = { 1 }; �޸����̼� �������ؼ�

int checkMaxLength(int value, int index)
{
	int checkVisit = 0;
	int maxCount = 1;
	arr[index] = value;
	for (int i = 0; i index; i++)
	{
		if (arr[index]  arr[i])
		{
			checkVisit++;
			if (maxCount  check[i])maxCount = check[i];
		}
	}
	if (checkVisit != 0)
		check[index] = maxCount + 1;
	return check[index];
}

int main()
{
	int result[51];
	int bTestcase;
	int inputNum, length;
	int maxcount = 0;
	cin  bTestcase;
	for (int i = 0; i bTestcase; i++)
	{
		cin  sTestcase;
		for (int j = 0; j sTestcase; j++)
		{
			cin  inputNum;
			length = checkMaxLength(inputNum, j);
			if (length  maxcount)
				maxcount = length;
		}
		result[i] = maxcount;
		maxcount = 0;
		for (int k = 0; k sTestcase; k++)
			check[k] = 1;
	}
	for (int i = 0; i bTestcase; i++)
		cout  result[i]  endl;
	return 0;
}
