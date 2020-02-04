#include<iostream>
using namespace std;
int prince[1001];
int main() {
	int N, K;
	cin >> N >> K;
	int cnt=0;// 0~3까지 확인하는 수
	int i = 0;// 환형 배열 구현할 변수
	int rem = N;	//남은 왕자 수
	while (1) {
		if (prince[i] == 0) {	//빈 곳 체크
			cnt++;
		}
		if (cnt == K) {			//K번째 되는 지점
			prince[i] = 1;
			rem--;
			cnt = 0;
		}
		if (rem == 0) {			//그때가 마지막인지 체크
			cout << i + 1 << endl;
			exit(0);
		}
		i++;
		i = i%N;
	}
}