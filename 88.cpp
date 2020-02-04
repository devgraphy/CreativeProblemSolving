//bfs에서는 어떻게 정보를 누적하지?
//q에 푸시할 때 해당 좌표의 값을 갱신

#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
int a[20][20];
int chk[20][20];
int dr[4] = { 1, 0 , -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int main() {
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			cin >> a[i][j];
		}
	}
	q.push(make_pair(1, 1));
	chk[1][1] = 1;
	pair<int, int> fr;
	while (!q.empty()) {
		fr = q.front();
		q.pop();
		//4방향 확인
		for (int i = 0; i < 4; i++) {
			int rr = fr.first + dr[i];
			int cc = fr.second + dc[i];
			if (rr < 1 || rr > 7 || cc < 1 || cc> 7)
				continue;
			if (chk[rr][cc] == 0 && a[rr][cc] == 0) {	//먼저 방문한 곳은 최소값이 보장됨
				chk[rr][cc] = chk[fr.first][fr.second] + 1;
				q.push(make_pair(rr, cc));
			}
		}
	}
	cout << chk[7][7] - 1 << endl;
}