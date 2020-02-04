/*송아지 찾기 복습(bfs:상태 트리 탐색)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int dis[10001];
int tree[3] = { 1, -1, 5 };
int main() {
	freopen("data.txt", "rt", stdin);
	int S, E;
	queue<int> q;
	cin >> S >> E;
	fill_n(dis, 10001, -1);
	dis[S] = 0;
	q.push(S);
	int v;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {	//3가지 경우에 대해서
			if (v+tree[i] > 0 && v+tree[i] < 10001 && dis[v + tree[i]] == -1) {	//배열의 범위를 넘지 않고 아직 방문 안 했다면
				if (v + tree[i] == E) {		//그곳이 목적지 라면
					cout << dis[v] + 1 << endl;
					exit(0);
				}
				else {						//목적지가 아니라면
					dis[v + tree[i]] = dis[v] + 1;
					q.push(v + tree[i]);
				}
			}
		}
	}
}