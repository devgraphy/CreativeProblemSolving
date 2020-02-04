//[����] �� �丶�丶�� ���ο� �迭�� �ʱ�ȭ�ؾ� �ϳ�? �ְ�����x
//BFS���� time_limit�� �߻��ϴ� ������ ?

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int map[1005][1005];	//�Ÿ��� �Ѳ����� ǥ��. 0�� ���� ���� �丶���� ���ÿ� �湮���� ���� �丶��
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
	for (int i = 0; i < n; i++) {	//map �Է� �� �丶�� ��ġ �ľ�
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