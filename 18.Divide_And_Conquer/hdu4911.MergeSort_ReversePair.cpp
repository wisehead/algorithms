//ECUST luoyongjun
#include<bits/stdc++.h>
const int MAXN = 100005;
typedef  long  long  ll;
ll a[MAXN], b[MAXN], cnt;
void Merge(ll l, ll mid, ll r){
     ll i=l, j = mid+1, t=0;
     while(i <= mid && j <= r){
          if(a[i] > a[j]){
               b[t++] = a[j++];
               cnt += mid-i+1;                //��¼�����������
          }
          else b[t++]=a[i++];
     }
   //һ���������е������������ˣ���һ����û�У���ʣ�µ�ֱ�Ӹ��ƹ�����
while(i <= mid)   b[t++]=a[i++];
while(j <= r)      b[t++]=a[j++];
    for(i=0; i<t; i++)  a[l+i] = b[i];     //���ź����b[]���ƻ�a[]��
}
void Mergesort(ll l, ll r){
    if(l<r){
         ll  mid = (l+r)/2;                   //ƽ�ֳ�����������
         Mergesort(l, mid);
         Mergesort(mid+1, r);
         Merge(l, mid, r);                    //�ϲ�
    }
}
int main(){
    ll n,k;
    while(scanf("%lld%lld", &n, &k) != EOF){
        cnt = 0;
        for(ll i=0;i<n;i++)  scanf("%lld", &a[i]);
        Mergesort(0,n-1);                     //�鲢����
        if(cnt <= k) printf("0\n");
        else           printf("%I64d\n", cnt - k);
    }
    return 0;
}
