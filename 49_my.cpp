/*블록의 최댓값

Pseudo code
1. 정면 높이 정보로 모든 행 초기화
2. 측면 높이 정보의 역순으로 각각 행을 비교하여
	둘중 작은값으로 갱신
(이 최소의 조건만 만족하면 최대의 높이가 설정됨)
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[11][11];
int main() {
	int N, i, j;
	int sum = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[0][i];
		for (j = 1; j < N; j++) {	//1
			a[j][i] = a[0][i];
		}
	}
	int temp;
	for (i = N-1; i >=0; i--) {		//2
		cin >> temp;
		for (j = 0; j < N; j++) {
			sum = sum + min(a[i][j], temp);
		}
	}
	cout << sum << endl;
}




