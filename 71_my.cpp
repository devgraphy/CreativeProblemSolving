///*�۾��� ã��
//����. ���� ����� �� ������ ��ͷ� Ǯ �� ���� �� ������..
//�׷��� base case�� �˱� �����
//���⿡ dfs�� �⺻������ ó������ ���������� dfs�δ� ������ �ʾ���
//dfs�� ��ǥ ������ ã�� ������ ���������� ó��
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
//	chk[S] = 1;	//1�� ���� q�� push
//	int x; //pop ����
//	while (!q.empty()) {
//		x = q.front();	//front pop
//		q.pop();
//		// ���� �� �۾��� ���ķ� �̷������.
//		if (x - 1 > 0 && x - 1 < 10001 && chk[x - 1] == 0) { //-1��ŭ �̵����� �� q�� �߰�
//			chk[x - 1] = 1;
//			axis[x - 1] = axis[x] + 1;
//			q.push(x - 1);
//			if (x - 1 == E) {
//				cout << axis[x - 1];
//				exit(0);
//			}
//		}
//		if (x + 1 > 0 && x + 1 < 10001 && chk[x + 1] == 0) {	//+1��ŭ �̵����� �� q�� �߰�
//			chk[x + 1] = 1;
//			axis[x + 1] = axis[x] + 1;
//			q.push(x + 1);
//			if (x + 1 == E) {
//				cout << axis[x + 1];
//				exit(0);
//			}
//		}
//		if (x + 5 > 0 && x + 5 < 10001 && chk[x + 5] == 0) {	//+5��ŭ �̵����� �� q�� �߰�
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

/*�۾��� ã��
����. ���� ����� �� ������ ��ͷ� Ǯ �� ���� �� ������..
�׷��� base case�� �˱� �����
���⿡ dfs�� �⺻������ ó������ ���������� dfs�δ� ������ �ʾ���
dfs�� ��ǥ ������ ã�� ������ ���������� ó��
*/


// �ٵ��� �ڵ�
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
			if (v + tree[i] > 0 && v + tree[i] < 10001 && dis[v + tree[i]] == -1) {	//�迭�� ������ ���� �ʰ� ���� �湮 �� �ߴٸ�
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