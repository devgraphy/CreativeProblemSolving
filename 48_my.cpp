/*�� ���� ��հ� ���� ����� ��
�ٽ�
<= ���� ����� �ȿ��� == ���Ǹ� �����ϴ� �ڵ� �ȿ� �Ϲ� ������ �����ڵ带 ������
�������� Ʋ�� �ڵ带 �ۼ��ϴ� �Ǽ��� ���� �ʵ��� �����Ѵ�.
�̶� < �� ==�� �����Ͽ� �ڵ带 �ۼ��Ѵ�.

*/
#include<iostream>
using namespace std;
int main() {
	int a[10][10];
	int i, j;
	double sum = 0;
	int avg = 0;
	int adj = -200;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		avg = (int)round(sum / 9);
		cout << avg << " ";
		for (j = 0; j < 9; j++) {
			if (abs(a[i][j] - avg) < abs(adj - avg)) {
					adj = a[i][j];
			}
			else if (abs(a[i][j] - avg) < abs(adj - avg)) {
				if (a[i][j] > adj)
					a[i][j] = adj;
			}
		}
		cout << adj << endl;
		adj = -200;
		sum = 0;
	}
}