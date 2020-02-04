/* 특정 수 만들기
앞서서 임의의 원소들이 들어왔을 때 부분집합의 합을 구하는 방법으로 구해보자.
*/
//정석과 같음
#include <iostream>
using namespace std;
int n, m;
int a[12];
int cnt;
void dfs(int L, int sum) {
	if (L == n) {
		if (sum == m) cnt++;
		return;
	}
	//삼진 트리 (3가지 경우의 수)
	dfs(L + 1, sum + a[L]);
	dfs(L + 1, sum - a[L]);
	dfs(L + 1, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << cnt << endl;
}