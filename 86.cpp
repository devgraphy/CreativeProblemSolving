/*6개에서 4개를 고르는 과정에서 dfs가 적용되는 것
*/
/*
미흡한점1.
왜 조합을 못하지? 0124 다음 0125여야 하는데
if (L < piz.size()) 로 설정을 잘 못했었음.
5번째 체크하고 6번째가 basecase여야 함
항상 설계 잘하기

미흡한점2.
거리 갱신 시점을 잘못 인지함.
각각의 최소 거리를 합해서 전체 최소 거리를 만들어야 하는 거였음

미흡한점2. 배열 조합에서의 time limit exceeded 문제
배열 조합은 부분집합 문제와 같음.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int n, m, i, j;
int temp;
vector<pair<int, int> > home;
vector<pair<int, int> > piz;
int chk[15];	//피자 조합
int sum;
int dis;
int home_min = 2147000000;
int total;
int total_min = 2147000000;

void dfs(int L, int cnt) {
	if (L == piz.size()) {//basecase


		if (cnt == m) {	//피자 집 m개를 만족할 때만
			total = 0;//모든 집의 최소 거리 합
			for (i = 0; i < home.size(); i++) {//각 집에 대해서
				home_min = 2147000000;
				for (j = 0; j < piz.size(); j++) {
					if (chk[j] == 1) {//피자집과의 거리
						dis = (abs(home[i].first - piz[j].first) + abs(home[i].second - piz[j].second));
						if (home_min > dis)
							home_min = dis;
					}
				}
				total += home_min;//모든집의 최소거리 합
				//각 집에 대해서 최솟값 찾고 누적하는 것이 전체 최소값
			}
			//그게 조합마다 비교해야함. m개 원소의 조합 찾았을 때
			if (total_min > total)
				total_min = total;
		}



		return;
	}
	chk[L] = 1;
	dfs(L + 1, cnt + 1);
	chk[L] = 0;
	dfs(L + 1, cnt);
}

int main() {
	//freopen("data.txt", "rt", stdin);
	cin >> n >> m;
	for (i = 1; i <= n; i++) {	//두 배열에 각각 입력
		for (j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 1)
				home.push_back(make_pair(i, j));
			else if (temp == 2)
				piz.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << total_min << endl;
}

