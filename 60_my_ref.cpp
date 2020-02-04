//정석과 같음
#include <iostream>
using namespace std;
int N;
int a[11];
int total = 0;
void DFS(int L, int sum) {
	if (L == N+1) {
		if (sum == (total - sum)) {
			cout << "YES" << endl;
			exit(0);
		}
		return;
	}
	DFS(L + 1, sum + a[L]);
	DFS(L + 1, sum);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		total += a[i];
	}
	DFS(1, 0);
	cout << "NO" << endl;
}