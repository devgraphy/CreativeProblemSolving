/*���Ž��(dfs)
���� �׷���
*/
//���� ���������� ����ϴ� �ڵ� + ����
#include<iostream>
using namespace std;
int a[22][22];
int chk[22];
int N, M;
int cnt;
void dfs(int vertex) {
	if (vertex == N) {
		//for (int k = 1; k <= N; k++) {	//�Ʒ��� ���� ������ ����ϱ� ������ ���������� ����ؾ���
		//	if (chk[k] == 1)
		//		cout << k << " ";
		//}
		//cout << endl;
		cnt++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (a[vertex][i] == 1 && chk[i] == 0) {
			chk[i] = 1;
			dfs(i);
			chk[i] = 0;
		}
	}
}
int main() {
	int x, y;
	cin >> N >> M;;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	//for (i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	chk[1] = 1;
	dfs(1);	//������
	cout << cnt << endl;
}