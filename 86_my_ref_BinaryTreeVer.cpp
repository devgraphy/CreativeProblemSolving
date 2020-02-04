// 2진 트리 형식

#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[55][55];
int comb[15];
int mindis = 2147000000;
int sum;
int minsum = 2147000000;
vector<pair<int, int> > hs;
vector<pair<int, int> > pz;

void dfs(int L, int cnt) { //L: 조합배열 위치, cnt: 조합을 담는 배열 위치
	if (L == pz.size()) {
		if (cnt == m) {
			for (int i = 0; i < m; i++)
				cout << comb[i] << " ";
			cout << endl;
			for (int i = 0; i < hs.size(); i++) {
				for (int j = 0; j < m; j++) {
					int dis = abs(hs[i].first - pz[comb[j]].first) + abs(hs[i].second - pz[comb[j]].second);
					if (mindis > dis)
						mindis = dis;
				}
				sum += mindis;
				mindis = 2147000000;
			}
			if (minsum > sum)
				minsum = sum;
			sum = 0;
		}
		return;
	}
		
	comb[cnt] = L;
	dfs(L + 1, cnt + 1);
	dfs(L + 1, cnt);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				hs.push_back(make_pair(i, j));
			if (map[i][j] == 2)
				pz.push_back(make_pair(i, j));

		}
	}
	dfs(0, 0);		// L , cnt
	cout << minsum << endl;
}