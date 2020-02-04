//[쟁점] 매 토마토마다 새로운 배열로 초기화해야 하나? 주객전도x
//BFS에서 time_limit이 발생하는 이유는 ?

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int map[1005][1005];	//거리를 한꺼번에 표시. 0은 익지 않은 토마토인 동시에 방문하지 않은 토마토
queue<pair<int, int > > q;
int maxval = -2147000000;
int dis;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int untom;
int main() {
	//freopen("data.txt", "rt", stdin);
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {	//map 입력 및 토마토 위치 파악
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
			else if (map[i][j] == 0)
				untom++;
		}
	}
	pair<int, int> fr;
	while (!q.empty()) {
		fr = q.front();
		q.pop();
		dis = map[fr.first][fr.second];
		if (maxval < dis)
			maxval = dis;
		for (int i = 0; i < 4; i++) {
			int rr = fr.first + dr[i];
			int cc = fr.second + dc[i];
			if (rr < 0 || rr >= n || cc < 0 || cc >= m)
				continue;
			if (map[rr][cc] == 0) {
				untom--;
				map[rr][cc] = map[fr.first][fr.second] + 1;
				q.push(make_pair(rr, cc));
			}
		}
	}
	if (untom == 0)
		cout << maxval - 1 << endl;
	else
		cout << -1 << endl;
}