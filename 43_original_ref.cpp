/*뮤직비디오(이분검색 응용) 설명
N개의 곡을 입력 순서대로 M개의 DVD에 수록할 때 DVD의 최소 크기
DVD는 모두 같은 크기

방법: 앞에서부터 차곡차곡 최대로 채우는 것
예를 들어 1~9분짜리의 곡을 수록한다면
총 45분이므로 개수에 따라 최소 1부터 최대 45분 크기의 DVD에 넣을 수 있음
이때 1부터 45분까지 순서대로 확인할 수도 있지만 이분 검색과 결정알고리즘으로
답을 빠르게 얻을 수 있다.

▣ 입력설명
첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다. 다음 줄에는 조영필이 라이브에서
부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다. 부른 곡의 길이는 10,000분을
넘지 않는다고 가정하자.
▣ 출력설명
첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.

▣ 입력예제 1
9 3
1 2 3 4 5 6 7 8 9
▣ 출력예제 1
17
*/

/*슈도 코드
1. N, M입력
2. N개 수 입력
3. 1 ~ N의 총합 내에서 이분 검색 수행하여 답을 결정해놓고
		배열 순회하면서 DVD에 곡 수록
			pivot 내에 모두 나눠 넣었을 때, cnt가 M과 같으면 ans 갱신
			(pivot초과할 때마다 cnt변수 증가)
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, M, i, dvd, cnt, ans = 0, sum = 0;
	cin >> N >> M;				//1.
	vector<int> a(N);
	for (i = 0; i < N; i++) {	//2.
		cin >> a[i];
		sum += a[i];
	}
	int left = 1;
	int right = sum;
	while (left != right) {		//3. != 와 <= 구분
		dvd = 0;	//수록할 공간
		cnt = 1;	//DVD 개수
		int pivot = (left + right)/ 2;
		//cout << left << " " << right << " " << pivot << endl;
		for (i = 0; i < N; i++) {
			if (dvd + a[i] <= pivot) {
				dvd = dvd + a[i];

			}
			else {
				cnt++;
				dvd = a[i];
			}
		}
		if (cnt <= M) {			//DVD개수 확인 작업
			ans = pivot;
			right = pivot;	//더 작은 크기의 DVD로 가능할 수 도 있기 때문에
		}
		else {
			left = pivot+1;	//더 작은 크기의 DVD로는 더 이상 불가능하기 때문에
		}					//정수 캐스팅때문에 left와 right가 안 같아질 수도 있음!
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