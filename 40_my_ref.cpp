/*������(������Ʈ �˰��� Ȱ��)
�� ���� ���� �� ������Ʈ �˰��� ����
����. �� �� ����Ʈ �˰����� �����ϴ°�?
����. �� ����Ʈ �˰����� ���ǽ���?
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[30001], b[30001], c[10001];
	int N, M, i;
	int p1 = 0, p2 = 0, p3 = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> b[i];
	}
	sort(a, a + N);
	sort(b, b + M);
	while (p1 < N&& p2 < M) {
		if (a[p1] < b[p2])
			p1++;
		else if (a[p1] > b[p2])
			p2++;
		else {
			c[p3++] = a[p1++];
			p2++;
		}
	}
	for (i = 0; i < p3; i++) {
		cout << c[i] << " ";
	}
	
}