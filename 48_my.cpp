/*각 행의 평균과 가장 가까운 값
핵심
<= 조건 수행식 안에서 == 조건만 수행하는 코드 안에 일반 범위의 수행코드를 넣으면
논리적으로 틀린 코드를 작성하는 실수를 하지 않도록 주의한다.
이땐 < 와 ==로 구분하여 코드를 작성한다.

*/
#include<iostream>
using namespace std;
int main() {
	int a[10][10];
	int i, j;
	double sum = 0;
	int avg = 0;
	int adj = -200;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		avg = (int)round(sum / 9);
		cout << avg << " ";
		for (j = 0; j < 9; j++) {
			if (abs(a[i][j] - avg) < abs(adj - avg)) {
					adj = a[i][j];
			}
			else if (abs(a[i][j] - avg) < abs(adj - avg)) {
				if (a[i][j] > adj)
					a[i][j] = adj;
			}
		}
		cout << adj << endl;
		adj = -200;
		sum = 0;
	}
}