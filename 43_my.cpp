/*뮤직비디오(이분검색 응용)

문제 설명
N개의 곡을 입력 순서대로 M개의 DVD에 수록할 때 DVD의 최소 크기
(DVD는 모두 같은 크기)
▣ 입력설명
첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다.
다음 줄에는 라이브에서 부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다.
부른 곡의 길이는 10,000분을 넘지 않는다고 가정하자.
▣ 출력설명
첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.

▣ 입력예제 1
9 3
1 2 3 4 5 6 7 8 9
▣ 출력예제 1
17



핵심
- 이분검색으로 결정값을 정해서 앞에부터 채워보는 것임
- 그 크기가 최소가 되는 값을 찾아야 함

Pseudo code
1. N M 입력
2. N개의 수 입력
3. 이분 검색으로 값 결정(1부터 N개의 수 총합)
	(변수 초기화)
	4. 배열 순회하면서
		5. 하나의 DVD에 누적하되, 결정값보단 작으면 누적
		6. 누적값이 결정값보다 크면 그 값으로 갱신, cnt(dvd 개수) 증가
		
	7. 그 카운트가 M과 같거나 작으면
		기존의 결정값보다 작으면 대체
		RIGHT = MID - 1;
	8. 그 카운트가 M보다 크면
		LEFT = MID + 1;
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, M, i, cnt = 1;
	int a[1001];
	int dvd = 0;
	int left = 1, right = 0, mid;
	int ans = 217000000;
	cin >> N >> M;					//1.
	for (i = 0; i < N; i++) {		//2.
		cin >> a[i];
		right += a[i];
	}
	while (left <= right) {		
		mid = (left + right) / 2;	//3
		cnt = 1;
		dvd = 0;
		for (i = 0; i < N; i++) {	//4
			if (dvd + a[i] <= mid)		//5
				dvd += a[i];
			else {						//6
				dvd = a[i];
				cnt++;
			}
		}
		if (cnt <= M) {				//7
			if (ans > mid)
				ans = mid;
			right = mid - 1;
		}
		else						//8
			left = mid + 1;
	}
	cout << ans << endl;
}


/*숙지
문제1. pivot을 기존에서 -1, +1 미처리할 경우 무한 루프
이 문제에서 pivot을 옮기는 기준이 단순히 배열의 수와 상관없는 cnt와 M을 비교하는 것이다.
이때 조건만 만족하면 계속 반복수행하게 되는데
예를 들어 6, 7의 경우 pivot을 계산하면 6이다. 이때 else 조건에 걸려 left는 계속 같은 값으로
유지하게되어 같아지는 경우가 없게 된다.

- while (left != right)인 경우
right = pivot 만 써도됨 (캐스팅 연산이 이루어지면서 left = right인 경우가 발생, -1 처리해도 상관 없음)
- while(left <= right)인 경우
right = pivot -1까지 써야함(같아지는 경우까지 처리해주고 역전 현상일어날때 종료)
(-1쓰지 않으면 인덱스가 같은 것에서 무한 루프)
*/