/*병합 정렬
두배열 합치기

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n;
int a[101];
int b[101];
int p1, p2, p3;
void dfs(int lt, int rt) {
	if (lt == rt) return;
	int mid = (lt + rt) / 2;
	dfs(lt, mid);
	dfs(mid + 1, rt);
	p1 = lt;
	p2 = mid + 1;
	p3 = lt;
	while (p1 <= mid && p2 <= rt) {
		if (a[p1] >= a[p2])
			b[p3++] = a[p2++];
		else
			b[p3++] = a[p1++];
	}
	while (p1 <= mid)
		b[p3++] = a[p1++];
	while (p2 <= rt)
		b[p3++] = a[p2++];
	for (int i = lt; i <= rt; i++) {
		a[i] = b[i];
	}
}
int main() {
	freopen("data.txt", "rt", stdin);
	cin >> n;
	int left = 0;
	int right = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(left, right);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}