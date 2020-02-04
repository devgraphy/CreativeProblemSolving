/*���� ���ϱ�
ť�� Ȱ���� ȯ�� Ž�� ���� ����
*/

//#include <iostream>
//#include <queue>
//using namespace std;
//int main() {
//	int N, K;
//	int cnt = 0;
//	queue<int> q;
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++) {
//		q.push(i);	//q�� 1~N���� push
//	}
//	while (q.size() > 1) {	//�ϳ� ������ �� front ����ϰ� ����
//		cnt++;
//		if (cnt == K) {
//			q.pop();
//			cnt = 0;
//		}
//		else {
//			q.push(q.front());
//			q.pop();
//		}
//	}
//	cout << q.front() << endl;
//	
//}
//�� if�� Ȱ��
//while�� ���� ���� �ڵ�: for�� Ȱ��

#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N, K, i;
	queue<int> q;
	cin >> N >> K;
	for (i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
		if (q.size() == 1) {
			cout << q.front() << endl;
		}


	}
}