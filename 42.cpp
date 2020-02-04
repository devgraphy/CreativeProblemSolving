/*�̺а˻�
���1.
-sort�Լ��̿�
-�̺а˻����� ã��

���2. <- �� ���� �䱸 ����
-sort�Լ� ���x
-39��. �� �迭 ��ġ�� Ǯ�� ����
*/
//������ �ٸ�
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
