/*6������ 4���� ���� �������� dfs�� ����Ǵ� ��
*/
/*
��������1.
�� ������ ������? 0124 ���� 0125���� �ϴµ�
if (L < piz.size()) �� ������ �� ���߾���.
5��° üũ�ϰ� 6��°�� basecase���� ��
�׻� ���� ���ϱ�

��������2.
�Ÿ� ���� ������ �߸� ������.
������ �ּ� �Ÿ��� ���ؼ� ��ü �ּ� �Ÿ��� ������ �ϴ� �ſ���

��������2. �迭 ���տ����� time limit exceeded ����
�迭 ������ �κ����� ������ ����.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int n, m, i, j;
int temp;
vector<pair<int, int> > home;
vector<pair<int, int> > piz;
int chk[15];	//���� ����
int sum;
int dis;
int home_min = 2147000000;
int total;
int total_min = 2147000000;

void dfs(int L, int cnt) {
	if (L == piz.size()) {//basecase


		if (cnt == m) {	//���� �� m���� ������ ����
			total = 0;//��� ���� �ּ� �Ÿ� ��
			for (i = 0; i < home.size(); i++) {//�� ���� ���ؼ�
				home_min = 2147000000;
				for (j = 0; j < piz.size(); j++) {
					if (chk[j] == 1) {//���������� �Ÿ�
						dis = (abs(home[i].first - piz[j].first) + abs(home[i].second - piz[j].second));
						if (home_min > dis)
							home_min = dis;
					}
				}
				total += home_min;//������� �ּҰŸ� ��
				//�� ���� ���ؼ� �ּڰ� ã�� �����ϴ� ���� ��ü �ּҰ�
			}
			//�װ� ���ո��� ���ؾ���. m�� ������ ���� ã���� ��
			if (total_min > total)
				total_min = total;
		}



		return;
	}
	chk[L] = 1;
	dfs(L + 1, cnt + 1);
	chk[L] = 0;
	dfs(L + 1, cnt);
}

int main() {
	//freopen("data.txt", "rt", stdin);
	cin >> n >> m;
	for (i = 1; i <= n; i++) {	//�� �迭�� ���� �Է�
		for (j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 1)
				home.push_back(make_pair(i, j));
			else if (temp == 2)
				piz.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << total_min << endl;
}

