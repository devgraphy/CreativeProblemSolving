/*�۾��� ã�� ����(bfs:���� Ʈ�� Ž��)
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
		for (int i = 0; i < 3; i++) {	//3���� ��쿡 ���ؼ�
			if (v+tree[i] > 0 && v+tree[i] < 10001 && dis[v + tree[i]] == -1) {	//�迭�� ������ ���� �ʰ� ���� �湮 �� �ߴٸ�
				if (v + tree[i] == E) {		//�װ��� ������ ���
					cout << dis[v] + 1 << endl;
					exit(0);
				}
				else {						//�������� �ƴ϶��
					dis[v + tree[i]] = dis[v] + 1;
					q.push(v + tree[i]);
				}
			}
		}
	}
}