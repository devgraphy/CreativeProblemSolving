#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	freopen("data.txt", "rt", stdin);
	priority_queue<int> pq;
	int x;
	while (1) {
		cin >> x;
		if (x == -1) break;
		if (x == 0) {
			if (pq.empty())
				cout << "-1" << endl;
			else {
				cout << pq.top()<< endl;
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
}
