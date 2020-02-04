/*미로탐색(DFS)*/
#include<iostream>
using namespace std;
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[8][8];
int N, cnt = 0;
void dfs(int x, int y) {
	if (x == 7 && y == 7) {
		cnt++;
		return;
	}
	int xx, yy;
	for (int i = 0; i < 4; i++) {	//4방향 탐색
		xx = x + dx[i];
		yy = y + dy[i];
		if (map[xx][yy] == 1)	//이미 방문했거나 벽일 경우
			continue;
		if (xx < 1 || xx > 7 || yy < 1 || yy > 7) //x, y 축이 배열 범위 초과할 경우
			continue;

		map[xx][yy] = 1;
		dfs(xx, yy);
		map[xx][yy] = 0;
	}

}
int main() {
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			cin >> map[i][j];
		}
	}
	map[1][1] = 1;
	dfs(1, 1);
	cout << cnt << endl;
}