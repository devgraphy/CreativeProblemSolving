#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int chk[1001];	// �湮 Ȯ�� �迭-���� ����, �ִ� �ð� ����
int main() {
	//freopen("data.txt", "rt", stdin);
	int n, m;
	int x, y;
	vector<int> a[1001];
	queue<int> q;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(y);	//���Ḯ��Ʈ ����
		a[y].push_back(x);
	}
	cin >> x >> y;
	q.push(x);
	chk[x] = 1;
	int front;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = 0; i < a[front].size(); i++) {
			if (chk[a[front][i]] == 0) {
				chk[a[front][i]] = 1;
				if (a[front][i] == y) {
					cout << "YES" << endl;
					exit(0);
				}
				q.push(a[front][i]);
			}
		}
	}
	cout << "NO" << endl;
}