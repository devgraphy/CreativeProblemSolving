///*송아지 찾기
//예측. 뭔가 경우의 수 문제로 재귀로 풀 수 있을 거 같은데..
//그러나 base case를 알기 어려움
//여기에 dfs의 기본원리를 처음부터 적용했으면 dfs로는 빠지지 않았음
//dfs는 목표 지점을 찾을 때까지 연속적으로 처리
//*/
//
//#include<iostream>
//#include<queue>
//using namespace std;
//int S, E;
//int axis[10005];
//int chk[10005];
//int main() {
//	queue<int> q;
//	cin >> S >> E;
//	q.push(S);
//	chk[S] = 1;	//1번 정점 q에 push
//	int x; //pop 원소
//	while (!q.empty()) {
//		x = q.front();	//front pop
//		q.pop();
//		// 다음 세 작업은 병렬로 이루어진다.
//		if (x - 1 > 0 && x - 1 < 10001 && chk[x - 1] == 0) { //-1만큼 이동했을 때 q에 추가
//			chk[x - 1] = 1;
//			axis[x - 1] = axis[x] + 1;
//			q.push(x - 1);
//			if (x - 1 == E) {
//				cout << axis[x - 1];
//				exit(0);
//			}
//		}
//		if (x + 1 > 0 && x + 1 < 10001 && chk[x + 1] == 0) {	//+1만큼 이동했을 때 q에 추가
//			chk[x + 1] = 1;
//			axis[x + 1] = axis[x] + 1;
//			q.push(x + 1);
//			if (x + 1 == E) {
//				cout << axis[x + 1];
//				exit(0);
//			}
//		}
//		if (x + 5 > 0 && x + 5 < 10001 && chk[x + 5] == 0) {	//+5만큼 이동했을 때 q에 추가
//			chk[x + 5] = 1;
//			axis[x + 5] = axis[x] + 1;
//			q.push(x + 5);
//			if (x + 5 == E) {
//				cout << axis[x + 5];
//				exit(0);
//			}
//		}
//	}
//}

/*송아지 찾기
예측. 뭔가 경우의 수 문제로 재귀로 풀 수 있을 거 같은데..
그러나 base case를 알기 어려움
여기에 dfs의 기본원리를 처음부터 적용했으면 dfs로는 빠지지 않았음
dfs는 목표 지점을 찾을 때까지 연속적으로 처리
*/


// 다듬은 코드
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
			if (v + tree[i] > 0 && v + tree[i] < 10001 && dis[v + tree[i]] == -1) {	//배열의 범위를 넘지 않고 아직 방문 안 했다면
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