/*
인접리스트

정점과 가중치는 vector의 원소로 담기는데
그 원소는 pair형이다.
pair형 선언할 때 주의할점은 문법상의 문제
ox 
*/

#include<iostream>
using namespace std;
int N, M;
int a[11];
int cnt = 0;
void dfs(int n, int sum) {
	if (n > N) {
		if (sum == M) {
		cnt++;
		}
		return;
	}
	dfs(n + 1, sum + a[n]);
	dfs(n + 1, sum - a[n]);
	dfs(n + 1, sum);
}
int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}
	dfs(1, 0);
	cout << cnt << endl;
}