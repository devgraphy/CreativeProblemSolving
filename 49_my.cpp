/*����� �ִ�

Pseudo code
1. ���� ���� ������ ��� �� �ʱ�ȭ
2. ���� ���� ������ �������� ���� ���� ���Ͽ�
	���� ���������� ����
(�� �ּ��� ���Ǹ� �����ϸ� �ִ��� ���̰� ������)
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[11][11];
int main() {
	int N, i, j;
	int sum = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[0][i];
		for (j = 1; j < N; j++) {	//1
			a[j][i] = a[0][i];
		}
	}
	int temp;
	for (i = N-1; i >=0; i--) {		//2
		cin >> temp;
		for (j = 0; j < N; j++) {
			sum = sum + min(a[i][j], temp);
		}
	}
	cout << sum << endl;
}




