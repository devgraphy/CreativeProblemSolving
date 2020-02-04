/*최단 거리 문제
방향 그래프
1. BFS로 풀어보기
2. DFS로 풀어보기
*/
#include <iostream>
#include <vector>
//using namespace std;
//int N, M;
//int chk[22];	//방문한 노드 확인
//int q[22];
//int dis[22];	//level 계산하기 위한 1차원 배열
//int main() {
//	vector<int> graph[22];	//연결리스트로 그래프 구현
//	int x, y;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> x >> y;
//		graph[x].push_back(y);
//	}
//	int front = -1;
//	int back = -1;	//큐를 구현하기 위한 두 개의 포인터
//	q[++back] = 1;	//큐에 1 삽입, 1부터 시작
//	chk[1] = 1;		//1번 방문
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

/*BFS 복습
70. 그래프 최단거리
연결리스트 + 큐를 이용한 bfs
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>//연결리스트를 위한 벡터의 배열
#include<queue>//bfs구현하기 위한 큐
using namespace std;
int main() {
	freopen("data.txt", "rt", stdin);
	int N, M;// 정점수, 간선 수
	vector<int> map[22];
	queue<int> q;
	int chk[22];	// 최소 이동을 알기 위한 방문 확인 배열
	fill_n(chk, 22, -1);
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x].push_back(y);	//방향 그래프
	}
	chk[1] = 0;
	q.push(1);	//root 노드 삽입
	int v;
	while (!q.empty()) {
		v = q.front();	//한 원소에 대해서
		q.pop();
		for (int i = 0; i < map[v].size(); i++) {
			if (chk[map[v][i]] == -1) {	//아직 방문 안했으면
				chk[map[v][i]] = chk[v] + 1;
				q.push(map[v][i]);
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << i << " : " << chk[i] << endl;
	}
}