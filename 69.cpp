/*69. 이진트리 넓이우선탐색
무방향 그래프
큐 자료 구조.
front , back

배열

문제. 왜 vector와 queue는 전역변수로 선언하면 메서드를 사용할 수 없나?
*/

#include <iostream>
#include <vector>
using namespace std;
int chk[10];
int q[1]; // BFS구현하기 위한 큐
int main() {
	int x, y; //입력 변수
	vector<int> tree[10];	//연결리스트 구현

	for (int i = 0; i < 6; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);	//무방향 그래프
	}
	int front = -1;
	int back = -1;
	chk[1] = 1;
	q[++back] = 1;
	int pop;
	while (front < back) {
		pop = q[++front];//뽑아서
		for (int i = 0; i < tree[pop].size(); i++) { //연결된 만큼 순회
			if (chk[tree[pop][i]] == 0) {	//방문한 노드 확인
				chk[tree[pop][i]] = 1;
				q[++back] = tree[pop][i];	//큐에 push
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << q[i] << " ";
	}
}