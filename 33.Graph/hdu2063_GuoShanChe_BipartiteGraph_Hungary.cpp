//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
int G[510][510];
int match[510], reserve_boy[510];     //ƥ������match[]��
int k, m_girl, n_boy;
bool dfs(int x){       //��һ������·��������Ů��x��һ������к�
     for(int i=1; i<=n_boy; i++)
         if(!reserve_boy[i] && G[x][i]){
            reserve_boy[i] = 1;      // Ԥ���к�i��׼���ָ�Ů��x
            if(!match[i] || dfs(match[i])){
         //�����������(1)����к�i��û��ԣ��ͷָ�Ů��x��
         //            (2)����к�i�Ѿ���ԣ�������dfs()����ԭ��Ů�������ڳ�λ�ø�Ů��x
                match[i] = x;
          //��Գɹ������ԭ������ԣ������ɹ��������к�i����Ů��x
                return true;
            }
         }
     return false;      //Ů��xû��ϲ�����к������߸������ɹ�
}
int main(){
    while(scanf("%d",&k)!=EOF && k){
        scanf("%d%d",&m_girl,&n_boy);
        memset(G,0,sizeof(G));
        memset(match,0,sizeof(match));
        for(int i=0;i<k;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a][b]=1;
        }
        int sum=0;
        for(int i=1; i<=m_girl; i++){         //Ϊÿ��Ů�������
            memset(reserve_boy,0,sizeof(reserve_boy));
            if(dfs(i))  sum++;
   //��i��Ů����Գɹ��������Ժ�����ܸ��������Ǳ�֤�������
        }
        printf("%d\n",sum);
    }
    return 0;
}
