//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e6;
const int NUM = 105;
struct edge{
    int from, to, w;
//�ߣ���㣬�յ㣬Ȩֵ�����from��û���õ���e[i]��i����from
    edge(int a, int b,int c){from=a; to=b; w=c;}
};
vector<edge>e[NUM];  		 //���ڴ洢ͼ
struct s_node{
    int id, n_dis;           //id����㣻n_dis�������㵽���ľ���
    s_node(int b,int c){id=b; n_dis=c;}
    bool operator < (const s_node & a) const
    { return n_dis > a.n_dis;}
};
int n,m;
int pre[NUM]; //��¼ǰ�����
void print_path(int s,int t)  {   //��ӡ��s��t�����·��
   ;         //������Bellman-Ford�����е�print_path()��ȫһ��
}
void dijkstra(){
int s = 1;             //���s��1
    int  dis[NUM];         //��¼���н�㵽���ľ���
    bool done[NUM]; //done[i]=true��ʾ�����i�����·���Ѿ��ҵ�
    for (int i=1;i<=n;i++) {dis[i]=INF; done[i]=false; }    //��ʼ��
    dis[s]=0;                           //��㵽�Լ��ľ�����0
    priority_queue <s_node> Q;       //���ȶ��У�������Ϣ
    Q.push(s_node(s, dis[s]));       //��������
    while (!Q.empty())   {
        s_node u = Q.top();           //pop�������s������С�Ľ��u
        Q.pop();
        if(done[u.id])
//�����Ѿ��ҵ����·���Ľ�㡣������A�еĽ��
            continue;
        done[u.id]= true;
        for (int i=0; i<e[u.id].size(); i++) {  //�����u�������ھ�
            edge y = e[u.id][i];         //u.id�ĵ�i���ھ���y.to
            if(done[y.to])                //�����Ѿ��ҵ����·�����ھӽ��
                continue;
            if (dis[y.to] > y.w + u.n_dis) {
                dis[y.to] = y.w + u.n_dis;
                Q.push(s_node(y.to, dis[y.to]));
     //��չ�µ��ھӣ��ŵ����ȶ�����
                pre[y.to]=u.id;  //�������Ҫ����¼·��
            }
        }
    }
    printf("%d\n", dis[n]);
    // print_path(s,n);         //�������Ҫ����ӡ·��
}
int main(){
    while(~scanf("%d%d",&n,&m)) {
        if(n==0 && m==0) return 0;
        for (int i=1;i<=n;i++)
            e[i].clear();
        while (m--) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            e[a].push_back(edge(a,b,c));
//���a���ھӣ�������node[a]��
            e[b].push_back(edge(b,a,c));
        }
        dijkstra();
    }
}
