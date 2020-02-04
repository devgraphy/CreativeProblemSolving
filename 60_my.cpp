/*
합이 같은 부분집합
이진 트리로 구현(59번과 같은 구조)
더하거나 안 더하거나 두 경우이기 때문에, 체크 배열보다 편하게 재귀로 더해간다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n;
int a[11];	//59번과 달리 불규칙한 수가 들어온다.
int total;
void dfs(int L, int sum) {
	if (L == n) {
		if (total - sum == sum) {
			cout << "YES" << endl;
			exit(0);
		}
		return;
	}
	//이진 트리 (O,X) [쟁점] 이진 트리의 기준은?
	dfs(L + 1, sum + a[L]);
	dfs(L + 1, sum);
}
int main() {
	//freopen("data.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	dfs(0, 0);	//[쟁점] 인자는 어떤 기준으로 정했나?
	cout << "NO" << endl;

}
