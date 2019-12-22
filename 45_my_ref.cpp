/*공주구하기
▣문제설명:
1번 왕자부터 N번 왕자까지 순서대로 시계 방향으로 돌아가며 동그랗게 앉게 한다.
그리고 1번 왕자부터 시계방향으로 돌아가며 1부터 시작하여 번호를 외치게 한다.
한 왕자가 K(특정 숫자)를 외치면 그 왕자는 공주를 구하러 가는데서 제외되고 원 밖으로 나오게 된다.
그리고 다음 왕자부터 다시 1부터 시작하여 번호를 외친다.
이렇게 해서 마지막까지 남은 왕자가 공주를 구하러 갈 수 있다.

3 6 1 5 2 8 4 왕자가 차례대로 제외되고 마지막까지 남게 된 7번 왕자가 공주를 구하러 간다.
▣ 입력설명
첫 줄에 자연수 N(5<=N<=1,000)과 K(2<=K<=9)가 주어진다.
▣ 출력설명
첫 줄에 마지막 남은 왕자의 번호를 출력합니다.
▣ 입력예제 1
8 3
▣ 출력예제 1
7

Psuedo code(조세퍼스 문제)
1.N K 입력 (temp = N 하나의 원소가 남은 상황을 캐치하기 위해)
2.while 1 순회하면서
	3. 원소값이 0이면 cnt 증가
	4. cnt가 3이면
		 1로 바꾸고 temp는 1 감소
		 cnt 초기화
	
	5. if temp가 1이면	
		0인 하나의 원소 찾아서 '인덱스+1'출력
		프로그램 종료
	6. i = (i+1)%N;
*/

#include<iostream>
using namespace std;
int main(){
	int N, K, i = 0;
	int cnt = 0;
	int temp;
	int a[1001];
	cin >> N >> K;			//1
	fill_n(a, N, 0);
	temp = N;

	while (1) {				//2
		if (a[i] == 0) {	//3
			cnt++;
		}
		if(cnt == K) {		//4
			a[i] = 1;		
			cnt = 0;
			temp--;
		}
		if (temp == 1) {	//5
			for (i = 0; i < N; i++) {
				if (a[i] == 0)
					cout << i + 1 << endl;
				
			}
			return 0;
		}
		i = (i + 1) % N;	//6
	}
}




