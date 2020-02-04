#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int a[25][25];
int chk[25][25];	//�ߺ� üũ �迭: ��ȯ ���� ����
int cnt;
int n;
int dr[8] = { 1, 0, -1, 0, 1, 1 , -1, -1 };
int dc[8] = { 0, 1,0 , -1, 1, -1, 1, -1 };
void dfs(int r, int c) {
	//basecase ����
	for (int i = 0; i < 8; i++) {	//8����
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (rr < 0 || rr >= n || cc < 0 || cc >= n)
			continue;
		if (chk[rr][cc] == 0 && a[rr][cc] == 1) {
			chk[rr][cc] = 1;
			dfs(rr, cc);
			//�湮�� ���� �� ä���� �ϹǷ� �湮 �������� ���� �ʴ´�.
		}
	}
}
int main() {
	//freopen("data.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j] == 0 && a[i][j] == 1) {
				chk[i][j] = 0;
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
