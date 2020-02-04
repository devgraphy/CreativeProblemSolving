/*최소비용(DFS:인접행렬) - 정석과 같음
경로탐색 문제에서 비용만 더해서 최솟값을 계속 갱신
*/
int N, M;
int min = 217000000;
int map[22][22];
int chk[22];
void dfs(int v, int sum) {
	if (v == N) {
		if (sum < min)
			min = sum;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (map[v][i] > 0 && chk[i] == 0) {
			chk[i] = 1;
			dfs(i, sum + map[v][i]);
			chk[i] = 0;
		}
	}
}

#include <iostream>
using namespace std;
int main() {
	cin >> N >> M;
	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		map[x][y] = z;
	}
	chk[1] = 1;
	dfs(1, 0);
	cout << min << endl;
}