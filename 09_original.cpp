/*�����˰���
�迭 1�� ��� �ʱ�ȭ
1. ���Է�
2. 2�� ��� ��� 1����...3�� ��� ��� 1����...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
	int N, a[50005];
	cin >> N;
	fill_n(a, N + 1, 1);
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			a[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << a[i] << " ";
	}
}