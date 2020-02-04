/*39. 두 배열 합치기
＊축약 코드 활용하기
1. 첫 번째 배열에 입력
2. 두 번째 배열에 입력
3. 세 번째 배열에 합치기

*/



#include<iostream>
using namespace std;
int main() {
	int N, M, i;
	int a[101], b[101], c[202];
	int p1 = 0, p2 = 0, p3 = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> b[i];
	}
	while (p1 < N && p2 < M) {
		if (a[p1] < b[p2])
			c[p3++] = a[p1++];
		else
			c[p3++] = b[p2++];
	}
	//나머지 남은 배열에 대해서 처리
	while (p1 < N) {
		c[p3++] = a[p1++];
	}
	while (p2 < M) {
		c[p3++] = b[p2++];
	}
	for (i = 0; i < p3; i++) {
		cout << c[i] << " ";
	}
}