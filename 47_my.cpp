/*���츮
�ٽ�
4������ ���ؼ� ū�� �ϳ��� ������ ī��Ʈ
�� Ȯ�� ��ġ�� ���� chk ������ ������ �ʾ����� ���츮�� ����
*/
#include <iostream>
using namespace std;
int main() {
	int x[4] = { 1, 0, -1, 0 };
	int y[4] = { 0,1,0,-1 };
	int N, i = 0, j = 0, k = 0;
	int cnt = 0;	//���츮 ����
	int a[55][55];
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	bool chk;	//���츮 ���� ���� Ȯ��
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			chk = false;
			for (k = 0; k < 4; k++) {
				if (i + x[k] < 0 || i + x[k] >= N)		//���� ���� �ʰ� ���
					continue;
				if (j + y[k] < 0 || j + y[k] >= N)		//���� ���� �ʰ� ���
					continue;
				if (a[i + x[k]][j + y[k]] >= a[i][j]) {		//���츮 ���� ���� ���
					chk = true;
					break;
				}
			}
			if (chk == false)
				cnt++;
		}
	}
	cout << cnt << endl;
}