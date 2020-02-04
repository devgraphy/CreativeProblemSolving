/*병합정렬 + 두배열 합치기
호출종료시점에 아무것도 수행할 것이 없으면
함수 내 작업 코드를 if 문안에서 수행하면 더 깔끔한 코드가 된다.

쟁점. 왜 lt < rt인지 아는가?
역으로 재귀함수 종료가 다음 재귀함수 호출 후 
lt >= rt 조건일 때이기 때문이다.
쟁점. lt: 0 rt: 1일 때 무슨 작업 수행?
0과 1을 각각의 배열로 보고 작업을 수행하는 것이다.

TIP. 조건식에선 ++, -- 연산을 쓰지 않는다.
비교만했는데 뭘 증가한다?
그리고 그 조건이 맞는지도 모른다.
*/

#include <iostream>
using namespace std;
int N, i;
int a[101],merge[101];
void dfs(int lt, int rt) {
	int mid;		//◆mid를 전역변수로 선언하면 다른 결과 나온다. 왜?
	int p1, p2, p3;
	if (lt < rt) {
		mid = (lt + rt) / 2;
		dfs(lt, mid);
		dfs(mid + 1, rt);

		p1 = lt; //2 
		p2 = mid + 1; //3
		p3 = lt;

		while (p1 <= mid && p2 <= rt) {
			if (a[p1] < a[p2]) {
				merge[p3++] = a[p1++];
			}
			else
				merge[p3++] = a[p2++];
		}
		//나머지 처리
		while (p1 <= mid) {
			merge[p3++] = a[p1++];
		}
		while (p2 <= rt) {
			merge[p3++] = a[p2++];
		}
		cout << "lt: " << lt << " rt: " << rt << endl;
		for (i = lt; i <= rt; i++) {
			a[i] = merge[i];
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
int main() {
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	int left = 0, right = N - 1;
	dfs(left, right);
	for (i = 0; i < N; i++) {
		cout << merge[i] << " ";
	}
}