/*
���� ���� �κ�����
���� Ʈ���� ����(59���� ���� ����)
���ϰų� �� ���ϰų� �� ����̱� ������, üũ �迭���� ���ϰ� ��ͷ� ���ذ���.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n;
int a[11];	//59���� �޸� �ұ�Ģ�� ���� ���´�.
int total;
void dfs(int L, int sum) {
	if (L == n) {
		if (total - sum == sum) {
			cout << "YES" << endl;
			exit(0);
		}
		return;
	}
	//���� Ʈ�� (O,X) [����] ���� Ʈ���� ������?
	dfs(L + 1, sum + a[L]);
	dfs(L + 1, sum);
}
int main() {
	//freopen("data.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	dfs(0, 0);	//[����] ���ڴ� � �������� ���߳�?
	cout << "NO" << endl;

}
