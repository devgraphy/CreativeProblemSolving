/*���츮.
�ٽ�
- �迭 ���� ������ �����Ͽ� 0���� �ʱ�ȭ
- �������� 1���� �����Ͽ� �迭 ���� �ʰ��ϴ� ���(out of range)�� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[51][51];		//�迭 �������� ����. 0 �ʱ�ȭ
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int n, i, j, k, cnt = 0, flag;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {	//1���� �����Ͽ� out_of_range�� ����
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			flag = 0;
			for (k = 0; k < 4; k++) {
				if (a[i][j] <= a[i + dx[k]][j + dy[k]]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				cnt++;
		}
	}
	printf("%d\n", cnt);
}