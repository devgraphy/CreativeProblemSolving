//for문과 배열로
//#include <iostream>
//using namespace std;
//int main() {
//	int N, R;
//	int a[22];
//	a[0] = 1;
//	a[1] = 1;
//	cin >> N >> R;
//	int temp;
//
//	for (int i = 2; i <= N; i++) {
//		a[i] = a[i - 1] * i;
//	}
//	cout << a[N] / a[N - R] /a[R] << endl;
//}

//재귀로 팩토리얼을 구하고, 조합 공식 계산에 활용하기

//#include<iostream>
//using namespace std;
//int n, r, res = 1;
//void dfs(int a, int fac) {
//	if (a == n) {
//		res = fac;
//		return;
//	}
//	dfs(a + 1, fac * (a+1));
//	if (a == r) {
//		res /= fac;
//	}
//	if (a == n - r) {
//		res /= fac;
//	}
//}
//
//int main() {
//	cin >> n >> r;
//	dfs(1, 1);
//	cout << res << endl;
//}

//#include <iostream>
//using namespace std;
//int n, r;
//
//int dfs(int tn, int tr) {
//	if (tr == 1) {
//		return tn;
//	}
//	if (tn == tr) {
//		return 1;
//	}
//
//	return dfs(tn - 1, tr - 1) + dfs(tn - 1, tr);
//}
//int main() {
//	cin >> n >> r;
//	cout << dfs(n, r) << endl;
//	
//}
//#include <iostream>
//using namespace std;
//int dy[21][21];
//int dfs(int n, int r) {
//	if (dy[n][r] > 0) return dy[n][r];
//	if (n == r || r == 0) return 1;
//	return dy[n][r] = dfs(n - 1, r - 1) + dfs(n - 1, r);
//}
//int main() {
//	int n, r;
//	cin >> n >> r;
//	cout << dfs(n, r) << endl;
//}

//=====================================================
////메모이제이션 없는 코드
//int n, r;
//int dfs(int n, int r) {
//	if (n == r || r == 0) return 1;
//	return dfs(n - 1, r - 1) + dfs(n - 1, r);
//}
//int main() {
//	cin >> n >> r;
//	cout << dfs(n, r) << endl;
//}


//메모이제이션 있는 코드
#include <iostream>
using namespace std;
int n, r;
int mem[22][22];
int dfs(int n, int r) {
	if (mem[n][r] > 0)
		return mem[n][r];
	if (n == r || r == 0) return 1;
	mem[n - 1][r - 1] = dfs(n - 1, r - 1);
	mem[n - 1][r] = dfs(n - 1, r);
	return mem[n - 1][r - 1] + mem[n - 1][r];
}
int main() {
	cin >> n >> r;
	cout << dfs(n, r) << endl;
}


















