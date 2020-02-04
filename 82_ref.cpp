#include <iostream>
using namespace std;
int n, r;
int a[20];
int chk[20];		//중복 체크 배열
int perm[20];
int cnt;
void dfs(int L) {
	if (L == r) {
		cnt++;
		for (int i = 0; i < L; i++) {
			cout << perm[i] << " ";
		}
		cnt++;
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) { //4가지 갈래
		if (chk[i] == 0) {
			perm[L] = a[i];
			chk[i] = 1;
			dfs(L + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << cnt << endl;
}



/*82. 순열 구하기
DFS 전 고려 사항
1. N진 트리
2. 누적 정보:
cnt를 사용해서 중복 체크 배열을 안 쓰려고 했지만
순열 문제는 방문 순서도 모두 다른 경우로 취급해야 하기 때문에
중복 체크 배열과 동시에 cnt로 방문 원소를 따로 담아야 한다.
(cf. 중복 체크 배열은 순서 정보가 담겨 있지 않다)

3. L과 cnt 는 모두 0
4. L이 배열 크기에 이르렀을 때
5. 중복 체크 배열 필요함
*/


//200128 review code
//#include <iostream>
//using namespace std;
//int n, r;
//int a[20];
//int b[20];
//int chk[20];
//int num;
//void dfs(int L, int cnt) {
//	//[쟁점] BASECASE를 배열 처음부터 끝까지 설정해야 하나?
//	if (L == n) return;			//이 조건이 추가되지 않으면 무슨 문제 발생?
//	if (cnt == r) {
//		for (int i = 0; i < r; i++) {
//			cout << b[i] << " ";
//		}
//		num++;
//		cout << endl;
//		return;
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (chk[i] == 0) {
//			chk[i] = 1;
//			b[cnt] = a[i];			//L과 비동기로 작동
//			dfs(L + 1, cnt + 1);	//현재 레벨에서 추가
//			dfs(L + 1, cnt);		//현재 레벨에서 미추가
//			chk[i] = 0;	//[쟁점] 왜 맨 마지막에 쓰였는지
//		}
//	}
//}
//
//int main() {
//	cin >> n >> r;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	dfs(0, 0);
//	cout << num << endl;
//}