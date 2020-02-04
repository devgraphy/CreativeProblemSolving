#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>	//���� ����Ʈ ����� ����
using namespace std;
int n, m;
int chk[25];	//�ߺ� üũ �迭
int cnt;
vector<int> vList[25];
void dfs(int v) {
	if (v == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < vList[v].size(); i++) {
		if (chk[vList[v][i]] == 0) {
			chk[vList[v][i]] = 1;
			dfs(vList[v][i]);
			chk[vList[v][i]] = 0;
		}
	}

}
int main() {
	//freopen("data.txt", "rt", stdin);

	cin >> n >> m;
	int x, y;	//������, ����
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		vList[x].push_back(y);	//���� �׷���

	}
	chk[1] = 1;
	dfs(1);
	cout << cnt << endl;
}