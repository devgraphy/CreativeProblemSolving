#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > pz;
vector<pair<int, int> > hs;
int ch[20], m, res = 2147000000, x1, y1, x2, y2, dis, sum = 0;

void dfs(int L, int cnt) {
	if (L > pz.size()) return;
	if (cnt == m) {
		sum = 0;
		for (int i = 0; i < hs.size(); i++) {
			x1 = hs[i].first;
			y1 = hs[i].second;
			dis = 2147000000;
			for (int j = 0; j < m; j++) {
				x2 = pz[ch[j]].first;
				y2 = pz[ch[j]].second;
				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));	//note
			}
			sum = sum + dis;
		}
		if (sum < res) res = sum;
	}
	else {
		ch[cnt] = L;
		dfs(L + 1, cnt + 1);
		dfs(L + 1, cnt);

	}
}
int main() {
	int n, i, j, a;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> a;
			if (a == 1) hs.push_back(make_pair(i, j));
			else if (a == 2) pz.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << res << endl;
}