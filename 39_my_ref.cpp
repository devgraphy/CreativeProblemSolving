/*39. �� �迭 ��ġ��
����� �ڵ� Ȱ���ϱ�
1. ù ��° �迭�� �Է�
2. �� ��° �迭�� �Է�
3. �� ��° �迭�� ��ġ��

*/



#include<iostream>
using namespace std;
int main() {
	int N, M, i;
	int a[101], b[101], c[202];
	int p1 = 0, p2 = 0, p3 = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> b[i];
	}
	while (p1 < N && p2 < M) {
		if (a[p1] < b[p2])
			c[p3++] = a[p1++];
		else
			c[p3++] = b[p2++];
	}
	//������ ���� �迭�� ���ؼ� ó��
	while (p1 < N) {
		c[p3++] = a[p1++];
	}
	while (p2 < M) {
		c[p3++] = b[p2++];
	}
	for (i = 0; i < p3; i++) {
		cout << c[i] << " ";
	}
}