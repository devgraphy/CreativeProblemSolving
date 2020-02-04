////발전 쟁점 고려 코드
//#include <iostream>
//using namespace std;
//int n, m;
//int a[12];
//int memory[12];
//int cnt;
//void dfs(int L, int sum) {
//	if (L == n) {
//		if (sum == m) {
//			int i = 0;
//			while (memory[i] != 1 && memory[i] != 2) { i++; }
//			if (memory[i] == 1)
//				cout << a[i];
//			else if (memory[i] == 2)
//				cout << "-" << a[i];
//			i++;
//			for (; i < n; i++) {
//				if (memory[i] == 1)
//					cout << " + " << a[i];
//				else if (memory[i] == 2)
//					cout << " - " << a[i];
//			}
//			cout << endl;
//			cnt++;
//		}
//		return;
//	}
//	memory[L] = 1;
//	dfs(L + 1, sum + a[L]);
//	memory[L] = 2;
//	dfs(L + 1, sum - a[L]);
//	memory[L] = 0;
//	dfs(L + 1, sum);
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	dfs(0, 0);
//	cout << cnt << endl;
//}




#include <iostream>
using namespace std;
int N, M;
int a[11];
int cnt;
void dfs(int L, int sum) {
	if (L == N + 1) {
		if (sum == M)
			cnt++;
		return;
	}
	dfs(L + 1, sum + a[L]);
	dfs(L + 1, sum - a[L]);
	dfs(L + 1, sum);
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	dfs(1, 0);
	if (cnt > 0)
		cout << cnt << endl;
	else
		cout << -1 << endl;
}

