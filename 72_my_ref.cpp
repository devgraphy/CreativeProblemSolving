/*공주 구하기
큐를 활용해 환형 탐색 구현 문제
*/

//#include <iostream>
//#include <queue>
//using namespace std;
//int main() {
//	int N, K;
//	int cnt = 0;
//	queue<int> q;
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++) {
//		q.push(i);	//q에 1~N까지 push
//	}
//	while (q.size() > 1) {	//하나 남았을 때 front 출력하고 종료
//		cnt++;
//		if (cnt == K) {
//			q.pop();
//			cnt = 0;
//		}
//		else {
//			q.push(q.front());
//			q.pop();
//		}
//	}
//	cout << q.front() << endl;
//	
//}
//난 if문 활용
//while문 내부 수행 코드: for문 활용

#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N, K, i;
	queue<int> q;
	cin >> N >> K;
	for (i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
		if (q.size() == 1) {
			cout << q.front() << endl;
		}


	}
}