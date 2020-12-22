//ECUST luoyongjun
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 10005;
int cnt;                            // ǿ��ͨ�����ĸ���
int low[N], num[N], dfn;
int sccno[N], stack[N], top;     // ��stack[]����ջ��top��ջ��
vector<int> G[N];
void dfs(int u){
    stack[top++] = u;              //u��ջ
    low[u]= num[u]= ++dfn;
    for(int i=0; i<G[u].size(); ++i){
        int v = G[u][i];
        if(!num[v]){                //δ���ʹ��ĵ㣬����dfs
            dfs(v);                  //dfs����ײ㣬�����һ��SCC
            low[u]= min( low[v], low[u] );
        }
        else if(!sccno[v])        //������˱�
            low[u]= min( low[u], num[v] );
    }
    if(low[u] == num[u]){        //ջ�׵ĵ���SCC�����ȣ�����low = num
        cnt++;
        while(1){
            int v = stack[--top];     //v����ջ
            sccno[v]= cnt;
            if(u==v) break;            //ջ�׵ĵ���SCC������
        }
    }
}
void Tarjan(int n){
        cnt = top = dfn = 0;
        memset(sccno,0,sizeof(sccno));
        memset(num,0,sizeof(num));
        memset(low,0,sizeof(low));
        for(int i=1; i<=n; i++)
            if(!num[i])
                dfs(i);
}
int main(){
    int n,m,u,v;
    while(scanf("%d%d", &n, &m), n != 0 || m != 0) {
        for(int i=1; i<=n; i++){ G[i].clear();}
        for(int i=0; i<m; i++){
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        Tarjan(n);
        printf("%s\n", cnt == 1 ? "Yes" : "No" );
    }
    return 0;
}
