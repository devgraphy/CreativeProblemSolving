//for������ ���� ���ϱ� : 'n-i�� Ʈ�� ����'���� ���

#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[55][55];
int chk[15];	//�ߺ� üũ �ʿ�
vector<pair<int, int> > hs;
int select[15];
vector<pair<int, int> > pz;
int mindis = 2147000000;
int sum;
int minsum = 2147000000;
void dfs(int L, int idx) {	//m�ܰ迡 ���� ������ 1���� ���õ�. for�� �ʿ�
	if (L == m) {//���տ� ���ؼ� ��� ���������� �Ÿ��� ���
		for (int i = 0; i < m; i++)
			cout << select[i] << " ";
		cout << endl;
		for (int i = 0; i < hs.size(); i++) {
			for (int j = 0; j < m; j++) {
				int dis = abs(hs[i].first - pz[select[j]].first) + abs(hs[i].second - pz[select[j]].second);
				if (mindis > dis)
					mindis = dis;
			}
			sum += mindis;
			mindis = 2147000000;
		}

		if (minsum > sum)
			minsum = sum;
		sum = 0;
		return;
	}
	for (int i = idx; i < pz.size(); i++) {
			select[L] = i;
			dfs(L + 1, i + 1);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1)
				hs.push_back(make_pair(i, j));	//�� ��ġ �߰�
			else if (map[i][j] == 2)
				pz.push_back(make_pair(i, j));	//���� ��ġ �߰�
		}
	}

	dfs(0, 0);	//L
	cout << minsum << endl;
}