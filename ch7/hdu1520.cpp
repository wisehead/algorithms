//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int N = 6000+5;
int value[N], dp[N][2], father[N], n;
vector <int> tree[N];
void dfs(int u){
    dp[u][0] = 0;                          //����ֵ�����μ����
    dp[u][1] = value[u];                  //����ֵ���μ����
    for(int i=0;i<tree[u].size();i++){  //��һ�������������ÿ���ӽ��
        int son = tree[u][i];
        dfs(son);                            //�����ӽ��
        dp[u][0] += max(dp[son][1], dp[son][0]);
						                 //����㲻ѡ���ӽ���ѡ�ɲ�ѡ
        dp[u][1] += dp[son][0];           //�����ѡ���ӽ�㲻ѡ
   }
}
int main(){
    while(~scanf("%d",&n)) {
      for(int i=1;i<=n;i++)  {
          scanf("%d",&value[i]);
          tree[i].clear();
          father[i] = -1;                 //����ֵ����δ������ϵ
      }
      while(1) {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==0&&b==0)  break;
        tree[b].push_back(a);         //���ڽӱ���
        father[a]=b;                    //���ӹ�ϵ
      }
      int t = 1;
      while(father[t] != -1)          //�������ĸ����
        t = father[t];
      dfs(t);                            //�Ӹ���㿪ʼ����dfs����������
      printf("%d\n", max(dp[t][1], dp[t][0]));
    }
    return 0;
}
