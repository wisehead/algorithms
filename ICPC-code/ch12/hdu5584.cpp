//ECUST luoyongjun
#include <bits/stdc++.h>
int solve(long long ex, long long ey) {
  int ans = 1;
  long long t;
  while (true) {
		if (ex > ey)
std::swap(ex, ey);
    	t = std::__gcd(ex, ey);
                 //p = ex / t;  q= ey/(ex+t);   //������p��q��δ�õ���
    	if ((ey % (ex+t)) == 0 ) {  //�ж�q�Ƿ�������t��p�϶������������жϡ�
      	ey = ey*t/(ex+t);
      	ans++;
    }
    else
      	break;
  }
  return ans;
}
int main() {
		int T;
		long long ex, ey;
		scanf("%d", &T);
		for (int cas = 1; cas <= T; cas++) {
    		scanf("%lld%lld", &ex, &ey);
		    printf("Case #%d: %d\n", cas, solve(ex, ey));
		}
  	return 0;
}
