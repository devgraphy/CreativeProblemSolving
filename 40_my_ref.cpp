/*교집합(투포인트 알고리즘 활용)
두 집합 정렬 후 투포인트 알고리즘 적용
쟁점. 왜 투 포인트 알고리즘을 적용하는가?
쟁점. 투 포인트 알고리즘의 조건식은?
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[30001], b[30001], c[10001];
	int N, M, i;
	int p1 = 0, p2 = 0, p3 = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> b[i];
	}
	sort(a, a + N);
	sort(b, b + M);
	while (p1 < N&& p2 < M) {
		if (a[p1] < b[p2])
			p1++;
		else if (a[p1] > b[p2])
			p2++;
		else {
			c[p3++] = a[p1++];
			p2++;
		}
	}
	for (i = 0; i < p3; i++) {
		cout << c[i] << " ";
	}
	
}