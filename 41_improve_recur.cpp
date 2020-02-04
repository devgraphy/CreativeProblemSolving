/*"61 특정 수 만들기" 단순화한 문제
◆트리 구조를 형상화 시켜보기
레벨마다 시작점을 새로 두는 것을 반복해야 함
*/
#include <iostream>
using namespace std;
int N;
int cnt;
void dfs(int L, int sum) {
	if (sum >= N) {	//여기서는 지나온 과정에 대해서 시간 순으로 출력 불가
		if (sum == N)//역순이면 가능, 개수만 출력해보자
			cnt++;
		return;
	}
	dfs(L + 1, sum + L);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N / 2; i++) {
		dfs(i, 0);
	}
	cout << cnt << endl;
}