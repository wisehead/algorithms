//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char s[N];
void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int ans = -1;
	for(int i = 0; i < n; ++ i) {  //��ͷ��β����ַ�����i�ǵ�ǰλ��
		for(int j = 1; j <= 26 && i - j >= 0; ++ j) {
			 	//��֦���ɣ�����Сд�ַ�һ����26���������ַ�����������
				//ͬ�ַ�����С���벻�����26��ֻ��Ҫ���iǰ���26���ַ�
			if(s[i] == s[i - j]) {
				//j��1��ʼ���������Ӿ���i������ַ���ʼ��飬
				//�������ͬ�ַ�����break������δ���ľ�����󣬲��ü�����顣
				if(ans == -1 || j < ans) {
					ans = j;
				}
				break;
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++ i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
