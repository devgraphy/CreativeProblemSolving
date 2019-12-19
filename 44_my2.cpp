/*������ ���ϱ�. Ǯ�� ����
�ΰ��� ������ ��ġ�� ���� ���������� �̵��ϸ鼭 �Ÿ��� ���Ѵ�.
�̺а˻����� ���� ������ ���� �� �� �ִ� �� Ȯ���Ѵ�.
�亸�� �Ÿ��� �� ������ �� ������ ������ �ϳ� �� �̵�
��� �Ÿ��� ���ų� ũ�� �ڿ� �ִ� ������ �ռ� ������ ��ġ�� ������ ���� �ռ� ������ ��ĭ �̵��Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, C;		//������ ����, �� ��
	int p1 = 0, p2 = 1;		//��ǥ�� p1  p2 ������ ������
	int ans = 0;
	int left = 1, right;	//left�� �������� �Ÿ��� ��Ÿ��. right�� ��ǥ�� �ִ�-�ּڰ�
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
	
	while (left <= right) {//�̺а˻����� �����˰���
		mid = (left + right) / 2;	//����
		cnt = 1;
		chk = false;
		p1 = 0;
		p2 = 1;
		while (p2 < N) {	
			if (axis[p2] - axis[p1] >= mid) {
				cnt++;
				//cout << "p2: " << p2 << " p1: " << p1 << endl;
				if (axis[p2] - axis[p1] == mid)	//��ǥ �̵��ϱ� ���� Ȯ��
					chk = true;					//�ش� �Ÿ�mid�� ��ǥ�� �����Ѵٸ�
				p1 = p2;	
				p2++;
			}
			else {
				p2++;
			}
		}
		// �� �� Ȯ�� �� �Ÿ� ���� Ȯ��, �̺а˻� ������
		if (cnt >= C) {		//���� ���� �� ���� ���� ��� ����. ������ �� ������ ���� �� �ִ� ���ɼ��� �ִ�.
			left = mid + 1;
			if (chk == true) {	//�ش� �Ÿ��� ��ǥ�� �����Ѵٸ�
				if (ans < mid)
					ans = mid;
			}
		}
		else
			right = mid - 1;

	}
	cout << ans << endl;

}