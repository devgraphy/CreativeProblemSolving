/*이분검색
방법1.
-sort함수이용
-이분검색으로 찾기

방법2. <- 이 문제 요구 사항
-sort함수 사용x
-39번. 두 배열 합치기 풀이 적용
*/
//정석과 다름
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M;

	vector<int> a;
	cin >> N >> M;
	int left = 0;
	int right = N - 1;
	int mid;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());

	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] < M) {
			left = mid + 1;
		}
		else if (a[mid] > M) {
			right = mid - 1;
		}
		else {
			cout << mid + 1 << endl;
			break;
		}

	}
}
