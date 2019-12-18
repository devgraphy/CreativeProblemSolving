#include <iostream>
#include <vector> //sort함수 사용하기 위함
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {	//2. N개 수 입력
		cin >> v[i];
	}
	sort(v.begin(), v.end());		//3. 정렬
	int left = 0, right = N - 1;	//4. 초기화
	int pivot;
	while (left != right) {			//5. 이분 탐색
		pivot = (left + right) / 2;
		if (v[pivot] < M) {
			left = pivot;
		}
		else if (v[pivot] > M) {
			right = pivot;
		}
		else if (v[pivot] == M) {
			cout << pivot+1 << endl;
			break;
		}
	}
}

