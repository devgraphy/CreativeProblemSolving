/*"61 Ư�� �� �����" �ܼ�ȭ�� ����
��Ʈ�� ������ ����ȭ ���Ѻ���
�������� �������� ���� �δ� ���� �ݺ��ؾ� ��
*/
#include <iostream>
using namespace std;
int N;
int cnt;
void dfs(int L, int sum) {
	if (sum >= N) {	//���⼭�� ������ ������ ���ؼ� �ð� ������ ��� �Ұ�
		if (sum == N)//�����̸� ����, ������ ����غ���
			cnt++;
		return;
	}
	dfs(L + 1, sum + L);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N / 2; i++) {
		dfs(i, 0);
	}
	cout << cnt << endl;
}