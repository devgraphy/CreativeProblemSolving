#include<iostream>
using namespace std;
int n;
int a[20];
int op[4];
int max = -2147000000;
int min = 2147000000;
void dfs(int L, int res) {
	if (L == n) {
		if (max < res)
			max = res;
		if (min > res)
			min = res;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			--op[i];
			switch (i) {
			case 0:
				dfs(L + 1, res + a[L]);
				++op[i];
				break;
			case 1:
				dfs(L + 1, res - a[L]);
				++op[i];
				break;
			case 2:
				dfs(L + 1, res * a[L]);
				++op[i];
				break;
			case 3:				
				dfs(L + 1, res / a[L]);
				++op[i];
				break;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(1, a[0]);	//수와 수 사이에 연산자가 들어가므로
	cout << max << endl << min << endl;
}