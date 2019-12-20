/*������ ���ϱ�...test
���� ����� �� ���� �Ÿ��� �ִ�
> �ּҰŸ��� �ִ밡 �Ǵ� ����� �Ÿ�
�̺а˻��� �����˰��� Ȱ��

�ٽ� ����
1. two variable for calculating a value between dependent two position
2. binary search used in decision algorithm


Pseudo code
1. N C�Է�
2. N�� ������ ��ǥ �Է�
3. ������ ��ǥ ����
4. �̺а˻� �����˰���
(�� ���������� �ݺ��Ǵ� ���Ǵ� ���� �ʱ�ȭ ����)
5. ���������� ũ�ų� ���� ��, ���� ������ ��Ÿ���� cnt ����
6. �������� ���� ���� �Ÿ� ���� ������ ��Ÿ���� chk ǥ��
7. �ڿ� �ִ� �������� ���� ������ �տ� �ΰ�, ���� ������ �ϳ� ����
8. ���������� ���� �� �ռ������� ������ �ϳ� ����
9. cnt�� �Է¹��� ���� ������ C�� ���ų� ũ��(�Ÿ��� ���������� �ǹ�)
�̺а˻� left������ mid�� ��ܿ�
10. �̶� chk�� ǥ�õǾ� ������(�ش� �Ÿ��� �����Ѵٴ� �ǹ��̹Ƿ�)
������ ���� ans ���� �������� mid�� Ŭ ���
ans�� mid�� �Ҵ�
11. cnt�� C���� ���� ��쿣(�Ÿ��� ������ ���ٴ� �ǹ��̹Ƿ�)
�̺а˻� right������ mid�� ��ܿ�
12. ans ���
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, C, i;
	int p1 = 0, p2 = 1;	//���� ���� ������ �ε���
	int cnt, ans = 0;
	bool chk = false;
	int left, right, mid;
	int max = -217000000, min = 217000000;	//�Ÿ� ���� ���ϱ� ����
	cin >> N >> C;				//1.
	vector<int> a(N);
	for (i = 0; i < N; i++) {	//2.
		cin >> a[i];
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	left = 1;	// �� ������ ������ �ּ� �Ÿ��� 1���� ����
	right = max - min;	//�� ó���� �� �� ���̰� �ִ� �Ÿ�
	sort(a.begin(), a.end());	//3. 
	while (left <= right) {		//4.
		mid = (left + right) / 2;
		cnt = 1;
		p1 = 0;
		p2 = 1;
		chk = false;
		while (p2 < N) {
			if (a[p2] - a[p1] >= mid) {		//5.
				cnt++;
				if (a[p2] - a[p1] == mid)		//6.
					chk = true;
				p1 = p2;						//7.
				p2++;
			}
			else							//8.
				p2++;
		}
		if (cnt >= C) {						//9.
			left = mid + 1;
			if (chk == true) {					//10.
				if (ans < mid)
					ans = mid;
			}
		}
		else {								//11.
			right = mid - 1;
		}

	}
	cout << ans << endl;					//12.
}

/*�ش� �˰��򿡼� �����ؾ��� �κ�
����1. ���� ��C�� �����ϴ� ������ mid�� ������ ��,
��ÿ� chkǥ�ð� �� �Ǿ� �ִµ�, left�� mid�� ��½��ѵ�
���Ŀ� ��ǥ�� �����ϴ� mid��(chk�� ǥ�õ�)�� ���´ٰ� ������ �� �ִ°�?
��, ���� chk�� ǥ�õǾ������ʰ� C�� �����ϴ� mid�� ������ �� �ֳ�?

>>������ mid�� mid�� ���ų� ū �Ÿ��� ���ؼ� cnt�� �����������Ƿ�
��������� �ּ��� mid���̾���� �ϰų� mid������ ū ���� �ݵ�� �����ؾ� �Ѵ�.
*/