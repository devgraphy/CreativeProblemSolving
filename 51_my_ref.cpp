/*영지(territory)선택 (large)
핵심:
반복적으로 계산되는 것들의 계산 횟수를 줄이기 위해 이전에 계산했던 값은 배열에 저장해 두었다가 나중에 재사용하는 기법
cin, cout 입출력 라이브러리로 인한 time limit 해결
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
			mem[i][j] = a[i][j] + mem[i - 1][j] + mem[i][j - 1] - mem[i - 1][j - 1];//입력과 동시에 메모이제이션
		}
	}
	scanf("%d %d", &H2, &W2);
	//나무 수 구하기
	for (i = H2; i <= H; i++) {
		for (j = W2; j <= W; j++) {
			tree = mem[i][j] - (mem[i - H2][j] + mem[i][j - W2]) + mem[i - H2][j - W2];
			if (tree > max)
				max = tree;
		}
	}
	printf("%d\n", max);
}