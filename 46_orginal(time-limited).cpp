
#include<iostream>
using namespace std;
int main() {
	int n, k, i, p = 0, cnt = 0, tot = 0;
	int a[2001];
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	cin >> k;
	if (k >= tot) {
		cout << -1 << endl;
		return 0;
	}
	while (1) {
		p++;
		if (p > n) p = 1;
		if (a[p] == 0) continue;
		a[p]--;
		cnt++;
		if (cnt == k)break;
	}
	while (1) {
		p++;
		if (p > n) p = 1;
		if (a[p] != 0) break;
	}
	cout << p << endl;
}