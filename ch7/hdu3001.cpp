//ECUST luoyongjun
#include<iostream>
#include<cstring>
const int INF = 0x3f3f3f3f;
using namespace std;
int n,m;
int bit[12]={0,1,3,9,27,81,243,729,2187,6561,19683,59049};
                          //������ÿһλ��Ȩֵ��������Ƶ�0, 1, 2, 4, 8...����
int tri[60000][11];
int dp[11][60000];
int graph[11][11];                  //��ͼ
void make_trb(){                  //��ʼ���������п��ܵ�·��
    for(int i=0;i<59050;++i){   //��3^10=59050��״̬
       int t=i;
       for(int j=1; j<=10; ++j){tri[i][j]=t%3; t/=3;}
   }
}
int comp_dp(){
        int ans = INF;
        memset(dp, INF, sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][bit[i]]=0;          //bit[i]�ǵ�i�����С�����������
        for(int i=0;i<bit[n+1];i++){
            int flag=1;                 //���еĳ��ж�������1������
            for(int j=1;j<=n;j++){    //ѡһ���յ�
                if(tri[i][j]== 0){     //�ж��յ�λ�Ƿ�Ϊ0
                    flag=0;              //��û�о������е�
                    continue;
                }
                if(i==j) continue;
                for(int k=1; k<=n; k++)                {
                    int l=i-bit[j];          //i״̬�ĵ�jλ��0
                    if(tri[i][k]==0) continue;
                    dp[j][i]=min(dp[j][i],dp[k][l]+graph[k][j]);
                }
            }
            if(flag)                          //����С����
                for(int j=1; j<=n; j++)
                    ans = min(ans,dp[j][i]);
        }
        return ans;
}
int main(){
    make_trb();
    while(cin>>n>>m){
        memset(graph,INF,sizeof(graph));
        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            if(c<graph[a][b])  graph[a][b]=graph[b][a]=c;
        }
        int ans = comp_dp();
        if(ans==INF) cout<<"-1"<<endl;
        else         cout<<ans<<endl;
    }
    return 0;
}
