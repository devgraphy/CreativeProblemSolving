/*정석알고리즘
배열 1로 모두 초기화
1. 수입력
2. 2의 배수 모두 1증가...3의 배수 모두 1증가...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
	int N, a[50005];
	cin >> N;
	fill_n(a, N + 1, 1);
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			a[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << a[i] << " ";
	}
}