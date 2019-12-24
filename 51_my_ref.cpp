/*����(territory)���� (large)
�ٽ�:
�ݺ������� ���Ǵ� �͵��� ��� Ƚ���� ���̱� ���� ������ ����ߴ� ���� �迭�� ������ �ξ��ٰ� ���߿� �����ϴ� ���
cin, cout ����� ���̺귯���� ���� time limit �ذ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
int a[705][705];
int mem[705][705];
int main() {
	int H, W, H2, W2, i, j;
	int tree = 0, max = -217000000;
	scanf("%d %d", &H, &W);
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			scanf("%d", &a[i][j]);
			mem[i][j] = a[i][j] + mem[i - 1][j] + mem[i][j - 1] - mem[i - 1][j - 1];//�Է°� ���ÿ� �޸������̼�
		}
	}
	scanf("%d %d", &H2, &W2);
	//���� �� ���ϱ�
	for (i = H2; i <= H; i++) {
		for (j = W2; j <= W; j++) {
			tree = mem[i][j] - (mem[i - H2][j] + mem[i][j - W2]) + mem[i - H2][j - W2];
			if (tree > max)
				max = tree;
		}
	}
	printf("%d\n", max);
}