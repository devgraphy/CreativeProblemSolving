/*����(territory) ����
Pseudo code
1. 2���� �迭�� ��ȸ�ϸ鼭
	�� ���Ҹ� ��������6���� �迭�� ��ȸ�ϸ� ���� ����
*/
#include <iostream>
using namespace std;
int a[55][55];
int main() {
	int H1, W1, i, j, m, n;
	int H2, W2;
	int sum = 0;
	int ans = -217000000;
	cin >> H1 >> W1;
	
	for (i = 0; i < H1; i++) {
		for (j = 0; j < W1; j++) {
			cin >> a[i][j];
		}
	}
	cin >> H2 >> W2;
	for (i = 0; i < H1; i++) {
		for (j = 0; j < W1; j++) {
			sum = 0;
			for (m = i; m < i + H2 && m < H1; m++) {
				for (n = j; n < j + W2 && n < W1; n++) {
					sum = sum + a[m][n];
				}
			}
			if (sum > ans)
				ans = sum;
		}
	}
	cout << ans << endl;
}