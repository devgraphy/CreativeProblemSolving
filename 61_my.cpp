/* Ư�� �� �����
�ռ��� ������ ���ҵ��� ������ �� �κ������� ���� ���ϴ� ������� ���غ���.
*/
//������ ����
#include <iostream>
using namespace std;
int n, m;
int a[12];
int cnt;
void dfs(int L, int sum) {
	if (L == n) {
		if (sum == m) cnt++;
		return;
	}
	//���� Ʈ�� (3���� ����� ��)
	dfs(L + 1, sum + a[L]);
	dfs(L + 1, sum - a[L]);
	dfs(L + 1, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << cnt << endl;
}