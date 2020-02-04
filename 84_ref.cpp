#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n;
int a[2][25];
int memory[25];
int max = -2147000000;

void dfs(int L, int sum) {
	if (L >= n + 1) {
		for (int i = 1; i <= n; i++) {
			if (memory[i] == 1)
				cout << i << " ";
		}
		cout << endl;
		if (max < sum) {
			max = sum;
		}
		return;
	}
	if (L + a[L][0] <= n + 1) {
		memory[L] = 1;
		dfs(L + a[L][0], sum + a[L][1]);
		memory[L] = 0;
	}
	dfs(L + 1, sum);	
}

int main() {
	//freopen("data.txt", "rt", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}

	dfs(1, 0);
	cout << max << endl;
}

