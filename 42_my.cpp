#include <iostream>
#include <vector> //sort�Լ� ����ϱ� ����
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {	//2. N�� �� �Է�
		cin >> v[i];
	}
	sort(v.begin(), v.end());		//3. ����
	int left = 0, right = N - 1;	//4. �ʱ�ȭ
	int pivot;
	while (left != right) {			//5. �̺� Ž��
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

