/*마구간 정하기. 풀이 전략
두개의 변수로 위치를 각각 독립적으로 이동하면서 거리를 구한다.
이분검색으로 구한 결정된 답이 될 수 있는 지 확인한다.
답보다 거리가 더 작으면 앞 서가는 변수를 하나 더 이동
답과 거리가 같거나 크면 뒤에 있던 변수를 앞선 변수의 위치로 가져다 놓고 앞선 변수를 한칸 이동한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, C;		//마구간 개수, 말 수
	int p1 = 0, p2 = 1;		//좌표상에 p1  p2 순으로 놓여짐
	int ans = 0;
	int left = 1, right;	//left는 마구간의 거리를 나타냄. right는 좌표의 최댓값-최솟값
	int max = -217000000;
	int min = 217000000;
	cin >> N >> C;
	vector<int> axis(N);
	
	for (int i = 0; i < N; i++) {
		cin >> axis[i];
		if (max < axis[i]) max = axis[i];
		if (min > axis[i]) min = axis[i];
	}
	right = max - min;
	int mid;
	int cnt= 1;
	bool chk;
	sort(axis.begin(), axis.end());
	
	while (left <= right) {//이분검색으로 결정알고리즘
		mid = (left + right) / 2;	//가답
		cnt = 1;
		chk = false;
		p1 = 0;
		p2 = 1;
		while (p2 < N) {	
			if (axis[p2] - axis[p1] >= mid) {
				cnt++;
				//cout << "p2: " << p2 << " p1: " << p1 << endl;
				if (axis[p2] - axis[p1] == mid)	//좌표 이동하기 전에 확인
					chk = true;					//해당 거리mid가 좌표상에 존재한다면
				p1 = p2;	
				p2++;
			}
			else {
				p2++;
			}
		}
		// 말 수 확인 및 거리 존재 확인, 이분검색 재조정
		if (cnt >= C) {		//말의 수가 더 많은 것은 상관 없다. 하지만 더 간격을 넓힐 수 있는 가능성이 있다.
			left = mid + 1;
			if (chk == true) {	//해당 거리가 좌표상에 존재한다면
				if (ans < mid)
					ans = mid;
			}
		}
		else
			right = mid - 1;

	}
	cout << ans << endl;

}