#include <iostream>
using namespace std;
int main() {
	int N, temp, temp2, ans, max= -2147000000;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		temp2 = temp;
		int sum = 0;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (max < sum) {
			max = sum;
			ans = temp2;
		}
	}
	cout << ans << endl;
}

