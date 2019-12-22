/*봉우리
핵심
4방으로 비교해서 큰게 하나라도 없으면 카운트
다 확인 거치고 나서 chk 변수가 변하지 않았으면 봉우리로 인지
*/
#include <iostream>
using namespace std;
int main() {
	int x[4] = { 1, 0, -1, 0 };
	int y[4] = { 0,1,0,-1 };
	int N, i = 0, j = 0, k = 0;
	int cnt = 0;	//봉우리 개수
	int a[55][55];
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	bool chk;	//봉우리 조건 위배 확인
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			chk = false;
			for (k = 0; k < 4; k++) {
				if (i + x[k] < 0 || i + x[k] >= N)		//가로 범위 초과 경우
					continue;
				if (j + y[k] < 0 || j + y[k] >= N)		//세로 범위 초과 경우
					continue;
				if (a[i + x[k]][j + y[k]] >= a[i][j]) {		//봉우리 조건 위배 경우
					chk = true;
					break;
				}
			}
			if (chk == false)
				cnt++;
		}
	}
	cout << cnt << endl;
}