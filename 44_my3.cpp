/*마구간 정하기...test
가장 가까운 두 말의 거리가 최대
> 최소거리가 최대가 되는 경우의 거리
이분검색과 결정알고리즘 활용

핵심 개념
1. two variable for calculating a value between dependent two position
2. binary search used in decision algorithm


Pseudo code
1. N C입력
2. N개 마구간 좌표 입력
3. 마구간 좌표 정렬
4. 이분검색 결정알고리즘
(각 결정값마다 반복되는 사용되는 변수 초기화 수행)
5. 결정값보다 크거나 같을 때, 말의 개수를 나타내는 cnt 증가
6. 결정값과 같을 때는 거리 존재 유무를 나타내는 chk 표시
7. 뒤에 있던 포지션을 앞의 포지션 앞에 두고, 앞의 포지션 하나 증가
8. 결정값보다 작을 때 앞서나가는 포지션 하나 증가
9. cnt가 입력받은 말의 개수인 C와 같거나 크면(거리가 여유있음을 의미)
이분검색 left변수를 mid로 당겨옴
10. 이때 chk가 표시되어 있으면(해당 거리가 존재한다는 의미이므로)
기존의 답인 ans 보다 결정값인 mid가 클 경우
ans에 mid값 할당
11. cnt가 C보다 작을 경우엔(거리가 여유가 없다는 의미이므로)
이분검색 right변수를 mid로 당겨옴
12. ans 출력
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, C, i;
	int p1 = 0, p2 = 1;	//최초 비교할 마구간 인덱스
	int cnt, ans = 0;
	bool chk = false;
	int left, right, mid;
	int max = -217000000, min = 217000000;	//거리 구간 구하기 위함
	cin >> N >> C;				//1.
	vector<int> a(N);
	for (i = 0; i < N; i++) {	//2.
		cin >> a[i];
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	left = 1;	// 두 마구간 사이의 최소 거리는 1부터 시작
	right = max - min;	//맨 처음과 맨 끝 사이가 최대 거리
	sort(a.begin(), a.end());	//3. 
	while (left <= right) {		//4.
		mid = (left + right) / 2;
		cnt = 1;
		p1 = 0;
		p2 = 1;
		chk = false;
		while (p2 < N) {
			if (a[p2] - a[p1] >= mid) {		//5.
				cnt++;
				if (a[p2] - a[p1] == mid)		//6.
					chk = true;
				p1 = p2;						//7.
				p2++;
			}
			else							//8.
				p2++;
		}
		if (cnt >= C) {						//9.
			left = mid + 1;
			if (chk == true) {					//10.
				if (ans < mid)
					ans = mid;
			}
		}
		else {								//11.
			right = mid - 1;
		}

	}
	cout << ans << endl;					//12.
}

/*해당 알고리즘에서 증명해야할 부분
문제1. 말의 수C를 만족하는 결정값 mid가 나왔을 때,
당시에 chk표시가 안 되어 있는데, left를 mid로 상승시켜도
이후에 좌표상에 존재하는 mid값(chk가 표시된)이 나온다고 보장할 수 있는가?
즉, 만약 chk가 표시되어있지않고 C를 만족하는 mid가 유일할 수 있나?

>>결정값 mid는 mid와 같거나 큰 거리에 대해서 cnt를 증가시켰으므로
결과적으로 최소한 mid값이었어야 하거나 mid값보다 큰 수가 반드시 존재해야 한다.
*/