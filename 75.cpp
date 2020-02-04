/*최대 수입 스케줄(priority_queue응용문제)


*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool sortbyfirst(const pair<int, int>& a, const pair<int, int>&b) {
	return a.second > b.second;
}
int main() {
	int N, sum = 0;
	cin >> N;
	priority_queue<int> pq;
	pair<int, int> order[10001];
	for (int i = 0; i < N; i++) {
		cin >> order[i].first >> order[i].second;
	}
	sort(order, order + N, sortbyfirst);
	int maxday = order[0].second;
	int p = 0;
	/*for (int i = 0; i < N; i++) {
		cout << order[i].first << " " << order[i].second << endl;
	}*/
	while (maxday > 0) {
		while (maxday <= order[p].second) {
			pq.push(order[p++].first);
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
		maxday--;
	}
	cout << sum << endl;
}