//ECUST luoyongjun
#include <algorithm>
typedef long long LL;
int main(){
		int num, n, K, odd;
		scanf("%d", &num);
		for(int i = 1; i <= num; ++i){
			scanf("%d%d", &n, &K);
     	if(n % 2)
            	odd = 0; //n��������ÿһ�㶼������ߵ���
        	else {
		odd = 1; //n��ż����ת��Ϊ����С1�������������һ��ȡ�ұߵ���
            	n--;
        	}
        	LL pp=(LL)pow(2,K)-1;
//��������Ϊȫ1����������K=5ʱ��pp=31����������11111
	        	LL kk = pp-(pp-n)/2;  //kk�Ķ����Ʊ�ʾ������һ�����е�·����
								//����Ϊ1����'+'��Ϊ0����'-'��ԭ������ĵ�֤����
        	LL pos = 0;   //��ǰ�������ӹ����Ķ��㿪ʼ��
			printf("Case #%d:\n", i);
  		while(kk > 1) 	{	 //���������һ�㣬���һ������ż���⡣
         	  if(kk & 1) 		 //���������ĸ�λ���ǵ�ǰ�Ĳ㡣
								 //���λ����'1'����ʾҪ�ӡ�
                printf("%lld %c\n", (LL)pow(2,pos), '+');
           else        //���������ĸ�λ����'0'����ʾҪ��
                printf("%lld %c\n", (LL)pow(2,pos), '-');
           kk = kk >> 1; //������������һ�Σ��Ѵ���������ߡ�
							 //�µĸ�λ������һ�㡣
            pos++;
        }
//���洦�����һ�㡣���n��ż�������һ��ȡ�ұߡ�
        if(kk & 1)
             printf("%lld %c\n", (LL)pow(2,pos)+odd, '+');
        else
             printf("%lld %c\n", (LL)pow(2,pos)+odd, '-');
		}
		return 0;
}
