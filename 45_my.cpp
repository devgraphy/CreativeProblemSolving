#include<iostream>
using namespace std;
int prince[1001];
int main() {
	int N, K;
	cin >> N >> K;
	int cnt=0;// 0~3���� Ȯ���ϴ� ��
	int i = 0;// ȯ�� �迭 ������ ����
	int rem = N;	//���� ���� ��
	while (1) {
		if (prince[i] == 0) {	//�� �� üũ
			cnt++;
		}
		if (cnt == K) {			//K��° �Ǵ� ����
			prince[i] = 1;
			rem--;
			cnt = 0;
		}
		if (rem == 0) {			//�׶��� ���������� üũ
			cout << i + 1 << endl;
			exit(0);
		}
		i++;
		i = i%N;
	}
}