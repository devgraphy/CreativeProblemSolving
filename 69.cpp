/*69. ����Ʈ�� ���̿켱Ž��
������ �׷���
ť �ڷ� ����.
front , back

�迭

����. �� vector�� queue�� ���������� �����ϸ� �޼��带 ����� �� ����?
*/

#include <iostream>
#include <vector>
using namespace std;
int chk[10];
int q[1]; // BFS�����ϱ� ���� ť
int main() {
	int x, y; //�Է� ����
	vector<int> tree[10];	//���Ḯ��Ʈ ����

	for (int i = 0; i < 6; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);	//������ �׷���
	}
	int front = -1;
	int back = -1;
	chk[1] = 1;
	q[++back] = 1;
	int pop;
	while (front < back) {
		pop = q[++front];//�̾Ƽ�
		for (int i = 0; i < tree[pop].size(); i++) { //����� ��ŭ ��ȸ
			if (chk[tree[pop][i]] == 0) {	//�湮�� ��� Ȯ��
				chk[tree[pop][i]] = 1;
				q[++back] = tree[pop][i];	//ť�� push
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << q[i] << " ";
	}
}