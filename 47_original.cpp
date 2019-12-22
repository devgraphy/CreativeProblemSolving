/*봉우리.
핵심
- 배열 전역 변수로 정의하여 0으로 초기화
- 격자판을 1부터 시작하여 배열 범위 초과하는 경우(out of range)를 피함
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[51][51];		//배열 전역변수 정의. 0 초기화
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int n, i, j, k, cnt = 0, flag;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {	//1부터 시작하여 out_of_range를 피함
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