/*
��������Ʈ

������ ����ġ�� vector�� ���ҷ� ���µ�
�� ���Ҵ� pair���̴�.
pair�� ������ �� ���������� �������� ����
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