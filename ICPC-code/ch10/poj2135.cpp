//ECUST luoyongjun
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1010;
int dis[N], pre[N], preve[N];
//dis[i]��¼��㵽i����̾��롣pre�� preve������ע��
int n, m;
struct edge{
    int to, cost, capacity, rev;        //rev���ڼ�¼ǰ����
    edge(int to_,int cost_,int c,int rev_){
          to=to_; cost=cost_; capacity=c; rev=rev_;}
};
vector<edge> e[N];           //e[i]�����i��������ӵ����еı�
void addedge(int from,int to,int cost,int capacity){//��1��������ٷ�Ϊ2��
    e[from].push_back(edge(to, cost, capacity, e[to].size()));
    e[to].push_back(edge(from, -cost, 0, e[from].size()-1));
}
bool spfa(int s, int t, int cnt){          //��SPFAģ��
    bool inq[N];
    memset(pre, -1, sizeof(pre));
    for(int i = 1; i <= cnt; ++i) { dis[i]=INF; inq[i]=false; }
    dis[s] = 0;
    queue <int> Q;
    Q.push(s);
    inq[s] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for(int i=0; i < e[u].size(); i++)
            if(e[u][i].capacity > 0){
                int v = e[u][i].to, cost = e[u][i].cost;
                if(dis[u]+cost < dis[v]){
                    dis[v] = dis[u]+cost;
                    pre[v] = u;        //v��ǰ������u
                    preve[v] = i;      // u�ĵ�i��������v��
                    if(!inq[v]){
                        inq[v] = true;
                        Q.push(v);
                    }
                }
            }
    }
    return dis[t] != INF;   //s��t����̾��루������С���ã���dis[t]
}
int mincost(int s, int t, int cnt){      //���������������ģ��
    int cost = 0;
    while(spfa(s, t, cnt)){
        int v = t, flow = INF;        //ÿ�����ӵ�����
        while(pre[v] != -1){          //��������·��������·������
            int u = pre[v], i = preve[v];
                     //u��v��ǰ���㣬u�ĵ�i��������v
            flow = min(flow, e[u][i].capacity);
                     //���бߵ���С������������·����
            v = u;                   //���ݣ�ֱ��Դ��
        }
        v = t;
        while(pre[v] != -1){                      //���²�������
            int u = pre[v], i = preve[v];
            e[u][i].capacity -= flow;            //�����
            e[v][e[u][i].rev].capacity += flow;//����ӣ�ע��rev������
            v = u;                                   //���ˣ�ֱ��Դ��
        }
        cost += dis[t]*flow;
                        //�����ۼӡ����������Ҫ�����������������ۼ�flow
    }
    return cost;                //�����ܷ���
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < N; i++)  e[i].clear();   //��մ���
        for(int i = 1; i <= m; ++i){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w, 1);        //��1������߷�Ϊ2�������
            addedge(v, u, w, 1);
        }
        int s = n+1, t = n+2;
        addedge(s, 1, 0, 2);           //���Դ��
        addedge(n, t, 0, 2);           //��ӻ��
        printf("%d\n", mincost(s, t, n+2));
    }
    return 0;
}
