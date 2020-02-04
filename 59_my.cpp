/*부분집합*/

#include <iostream>
using namespace std;
int n;
int chk[11];
void dfs(int L) {
	if (L == n + 1) {
		for (int i = 1; i <= n; i++) {
			if (chk[i] == 1)
				cout << i << " ";
		}
		cout << endl;
		return;
	}

	//이진트리 전위 순회 방식
	chk[L] = 1;
	dfs(L + 1);
	chk[L] = 0;
	dfs(L + 1);
}
int main() {
	cin >> n;
	dfs(1);
}