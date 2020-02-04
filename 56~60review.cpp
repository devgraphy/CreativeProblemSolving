#include<iostream>
using namespace std;
int a[11];
int N;
void dfs(int n) {
	if (n > N) {
		for (int i = 1; i <= N; i++) {
			if(a[i] == 1)
				cout << i <<" ";
		}
		cout << endl;
		return;
	}
	a[n] = 1;
	dfs(n + 1);
	a[n] = 0;
	dfs(n + 1);

}

int main() {
	cin >> N;
	dfs(1);

}