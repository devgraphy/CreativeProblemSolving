/*�������� + �ι迭 ��ġ��
ȣ����������� �ƹ��͵� ������ ���� ������
�Լ� �� �۾� �ڵ带 if ���ȿ��� �����ϸ� �� ����� �ڵ尡 �ȴ�.

����. �� lt < rt���� �ƴ°�?
������ ����Լ� ���ᰡ ���� ����Լ� ȣ�� �� 
lt >= rt ������ ���̱� �����̴�.
����. lt: 0 rt: 1�� �� ���� �۾� ����?
0�� 1�� ������ �迭�� ���� �۾��� �����ϴ� ���̴�.

TIP. ���ǽĿ��� ++, -- ������ ���� �ʴ´�.
�񱳸��ߴµ� �� �����Ѵ�?
�׸��� �� ������ �´����� �𸥴�.
*/

#include <iostream>
using namespace std;
int N, i;
int a[101],merge[101];
void dfs(int lt, int rt) {
	int mid;		//��mid�� ���������� �����ϸ� �ٸ� ��� ���´�. ��?
	int p1, p2, p3;
	if (lt < rt) {
		mid = (lt + rt) / 2;
		dfs(lt, mid);
		dfs(mid + 1, rt);

		p1 = lt; //2 
		p2 = mid + 1; //3
		p3 = lt;

		while (p1 <= mid && p2 <= rt) {
			if (a[p1] < a[p2]) {
				merge[p3++] = a[p1++];
			}
			else
				merge[p3++] = a[p2++];
		}
		//������ ó��
		while (p1 <= mid) {
			merge[p3++] = a[p1++];
		}
		while (p2 <= rt) {
			merge[p3++] = a[p2++];
		}
		cout << "lt: " << lt << " rt: " << rt << endl;
		for (i = lt; i <= rt; i++) {
			a[i] = merge[i];
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
int main() {
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	int left = 0, right = N - 1;
	dfs(left, right);
	for (i = 0; i < N; i++) {
		cout << merge[i] << " ";
	}
}