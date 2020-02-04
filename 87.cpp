#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int a[25][25];
int chk[25][25];	//중복 체크 배열: 순환 막기 위함
int cnt;
int n;
int dr[8] = { 1, 0, -1, 0, 1, 1 , -1, -1 };
int dc[8] = { 0, 1,0 , -1, 1, -1, 1, -1 };
void dfs(int r, int c) {
	//basecase 설정
	for (int i = 0; i < 8; i++) {	//8방향
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (rr < 0 || rr >= n || cc < 0 || cc >= n)
			continue;
		if (chk[rr][cc] == 0 && a[rr][cc] == 1) {
			chk[rr][cc] = 1;
			dfs(rr, cc);
			//방문한 곳을 다 채워야 하므로 방문 재해제를 하지 않는다.
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
