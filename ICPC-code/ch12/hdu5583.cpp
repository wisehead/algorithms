//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
#define square(x)  (x)*(x)
void solve() {
    	int i, j=1, k=1;
    	char s[N];
    	int n;
    	long long a[N]={0};
		long long maxsum, oldsum=0;
		scanf("%s", s + 1);
		n = strlen(s + 1);
   	for(i=2; i<=n; i++){   //�ѱ�ʾ�������еġ�01���ַ����ĳ����֣�����
			 //��000011001���ĳ�����4221�������������a[]�У������������ӱ��
        if(s[i]==s[i-1])
            j++;
        else {
           a[k]=j;
           k++;
           j=1;
        }
   	}
    	a[k]=j;
    	for(i=1; i<=k; i++){  //����ı���ɫǰ�ĺ�����
        oldsum = oldsum + a[i]*a[i];
    	}
    	maxsum = oldsum;
		for(i=1; i<=k; i++){    //�ı�1ֻ���ܵ���ɫ�Ժ�����Ӱ�죬
								 //ֻ��Ҫ��������2�����
        if(a[i]==1)           //���������1��˵����ֻ�����ǹ����ģ�
							     //�ı�������ɫ�󣬿��Ժ����Һϲ���
							     //���硱00100�����ϲ��ɡ�00000����
           maxsum = max(maxsum, oldsum+square(a[i-1]+a[i]+a[i+1])
-square(a[i-1])-square(a[i])-square(a[i+1]));
        if(a[i]>=2){  	 //������ȴ��ڵ���2�����Է�2�θı���ɫ��
				//(1)�ı�����ߵģ�����ߵ��ھӺϲ������硱0110�����ĳɡ�0010����
				//(2)�ı����ұߵģ����ұߵ��ھӺϲ������硱0110�����ĳɡ�0100����
				//������ȴ��ڵ���3���ı��м�ģ�ֻ���С������
				//���Բ��ÿ��ǣ����硱01110�����ĳɡ�01010����������С��
          maxsum = max(maxsum, oldsum+square(a[i-1]+1)+square(a[i]-1)
-square(a[i-1])-square(a[i])); //�����
          maxsum = max(maxsum, oldsum+square(a[i+1]+1)+square(a[i]-1)
-square(a[i+1])-square(a[i])); //���ұ�
        }
     }
		printf("%lld\n", maxsum);
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
