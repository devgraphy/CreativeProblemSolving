//for문으로 조합 구하기 : 'n-i진 트리 조합'으로 명명

#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[55][55];
int chk[15];	//중복 체크 필요
vector<pair<int, int> > hs;
int select[15];
vector<pair<int, int> > pz;
int mindis = 2147000000;
int sum;
int minsum = 2147000000;
void dfs(int L, int idx) {	//m단계에 걸쳐 무조건 1개는 선택됨. for문 필요
	if (L == m) {//조합에 대해서 모든 피자집과의 거리를 계산
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
				hs.push_back(make_pair(i, j));	//집 위치 추가
			else if (map[i][j] == 2)
				pz.push_back(make_pair(i, j));	//피자 위치 추가
		}
	}

	dfs(0, 0);	//L
	cout << minsum << endl;
}