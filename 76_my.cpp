//for���� �迭��
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

//��ͷ� ���丮���� ���ϰ�, ���� ���� ��꿡 Ȱ���ϱ�

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
////�޸������̼� ���� �ڵ�
//int n, r;
//int dfs(int n, int r) {
//	if (n == r || r == 0) return 1;
//	return dfs(n - 1, r - 1) + dfs(n - 1, r);
//}
//int main() {
//	cin >> n >> r;
//	cout << dfs(n, r) << endl;
//}


//�޸������̼� �ִ� �ڵ�
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


















