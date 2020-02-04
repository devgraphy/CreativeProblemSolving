#include <iostream>
using namespace std;
int n, r;
int a[20];
int chk[20];		//�ߺ� üũ �迭
int perm[20];
int cnt;
void dfs(int L) {
	if (L == r) {
		cnt++;
		for (int i = 0; i < L; i++) {
			cout << perm[i] << " ";
		}
		cnt++;
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) { //4���� ����
		if (chk[i] == 0) {
			perm[L] = a[i];
			chk[i] = 1;
			dfs(L + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << cnt << endl;
}



/*82. ���� ���ϱ�
DFS �� ��� ����
1. N�� Ʈ��
2. ���� ����:
cnt�� ����ؼ� �ߺ� üũ �迭�� �� ������ ������
���� ������ �湮 ������ ��� �ٸ� ���� ����ؾ� �ϱ� ������
�ߺ� üũ �迭�� ���ÿ� cnt�� �湮 ���Ҹ� ���� ��ƾ� �Ѵ�.
(cf. �ߺ� üũ �迭�� ���� ������ ��� ���� �ʴ�)

3. L�� cnt �� ��� 0
4. L�� �迭 ũ�⿡ �̸����� ��
5. �ߺ� üũ �迭 �ʿ���
*/


//200128 review code
//#include <iostream>
//using namespace std;
//int n, r;
//int a[20];
//int b[20];
//int chk[20];
//int num;
//void dfs(int L, int cnt) {
//	//[����] BASECASE�� �迭 ó������ ������ �����ؾ� �ϳ�?
//	if (L == n) return;			//�� ������ �߰����� ������ ���� ���� �߻�?
//	if (cnt == r) {
//		for (int i = 0; i < r; i++) {
//			cout << b[i] << " ";
//		}
//		num++;
//		cout << endl;
//		return;
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (chk[i] == 0) {
//			chk[i] = 1;
//			b[cnt] = a[i];			//L�� �񵿱�� �۵�
//			dfs(L + 1, cnt + 1);	//���� �������� �߰�
//			dfs(L + 1, cnt);		//���� �������� ���߰�
//			chk[i] = 0;	//[����] �� �� �������� ��������
//		}
//	}
//}
//
//int main() {
//	cin >> n >> r;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	dfs(0, 0);
//	cout << num << endl;
//}