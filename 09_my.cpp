#include <iostream>
using namespace std;
int main() {
	int N;
	int cnt;
	cin >> N;
	cout << 1 << " " << 2 << " ";
	bool chk = false;
	for (int i = 3; i <= N; i++) {
		cnt = 0;
		for (int j = 2; j * j<= i; j++) {
			if (i % j == 0)
				cnt+=2;
			if (j * j == i)
				cnt--;
		}

		cout << cnt+2 << " ";
	}
}