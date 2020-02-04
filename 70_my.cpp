/*�ִ� �Ÿ� ����
���� �׷���
1. BFS�� Ǯ���
2. DFS�� Ǯ���
*/
#include <iostream>
#include <vector>
//using namespace std;
//int N, M;
//int chk[22];	//�湮�� ��� Ȯ��
//int q[22];
//int dis[22];	//level ����ϱ� ���� 1���� �迭
//int main() {
//	vector<int> graph[22];	//���Ḯ��Ʈ�� �׷��� ����
//	int x, y;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> x >> y;
//		graph[x].push_back(y);
//	}
//	int front = -1;
//	int back = -1;	//ť�� �����ϱ� ���� �� ���� ������
//	q[++back] = 1;	//ť�� 1 ����, 1���� ����
//	chk[1] = 1;		//1�� �湮
//	int pop;
//	while (front < back) {
//		pop = q[++front];	//pop
//		for (int i = 0; i < graph[pop].size(); i++) {
//			if (chk[graph[pop][i]] == 0) {
//				chk[graph[pop][i]] = 1;
//				q[++back] = graph[pop][i];
//				dis[graph[pop][i]] = dis[pop] + 1;
//			}
//		}
//	}
//	for (int i = 2; i <= N; i++) {
//		cout << i << " : " << dis[i] << endl;
//	}
//	
//}

/*BFS ����
70. �׷��� �ִܰŸ�
���Ḯ��Ʈ + ť�� �̿��� bfs
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>//���Ḯ��Ʈ�� ���� ������ �迭
#include<queue>//bfs�����ϱ� ���� ť
using namespace std;
int main() {
	freopen("data.txt", "rt", stdin);
	int N, M;// ������, ���� ��
	vector<int> map[22];
	queue<int> q;
	int chk[22];	// �ּ� �̵��� �˱� ���� �湮 Ȯ�� �迭
	fill_n(chk, 22, -1);
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x].push_back(y);	//���� �׷���
	}
	chk[1] = 0;
	q.push(1);	//root ��� ����
	int v;
	while (!q.empty()) {
		v = q.front();	//�� ���ҿ� ���ؼ�
		q.pop();
		for (int i = 0; i < map[v].size(); i++) {
			if (chk[map[v][i]] == -1) {	//���� �湮 ��������
				chk[map[v][i]] = chk[v] + 1;
				q.push(map[v][i]);
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << i << " : " << chk[i] << endl;
	}
}