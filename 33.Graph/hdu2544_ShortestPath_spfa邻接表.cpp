//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e6;
const int NUM = 105;
struct edge{
int from, to, w;
//�ߣ����from���յ�to��Ȩֵw��from��û���õ���e[i]��i����from
    edge(int a, int b,int c){from=a; to=b; w=c;}
};
vector<edge> e[NUM];       //e[i]�����i��������ӵ����еı�
int n, m;
int pre[NUM];
 //��¼ǰ����㡣pre[x]=y�������·���ϣ����x��ǰһ�������y
void print_path(int s,int t) {    //��ӡ��s��t�����·��
   ;       //������Bellman-Ford�����е�print_path()��ȫһ��
}
int spfa(int s){
    int dis[NUM];      //��¼���н�㵽���ľ���
    bool inq[NUM];     //inq[i] = true ��ʾ���i�ڶ�����
    int Neg[NUM];      //�жϸ�Ȧ,Negative loop
    memset(Neg, 0, sizeof(Neg));
    Neg[s] = 1;
    for(int i=1;i<=n;i++) { dis[i]=INF;  inq[i]=false; }   //��ʼ��
    dis[s] = 0;          //��㵽�Լ��ľ�����0
    queue<int> Q;
    Q.push(s);
    inq[s] = true;        //��������
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();           //��ͷ����
        inq[u] = false;
        for(int i=0; i < e[u].size(); i++) {    //�����u�������ھ�
            int v = e[u][i].to, w = e[u][i].w;
            if (dis[u]+w < dis[v])  {
//u�ĵ�i���ھ�v�������u����s����
               dis[v] = dis[u]+w; //���µ�i���ھӵ�s�ľ���
                pre[v] = u;        //�������Ҫ����¼·��
                if(!inq[v]) {
//��i���ھӸ���״̬�ˣ����������ڶ����У������Ž�����
                    inq[v] = true;
                    Q.push(v);
                    Neg[v]++;
                    if(Neg[v] > n) return 1;  //���ָ�Ȧ
                }
            }
        }
    }
    printf("%d\n",dis[n]);
    //print_path(s,n);   //�������Ҫ����ӡ·��
return 0;
}
int main(){
    while(~scanf("%d%d",&n,&m)) {
        if(n==0 && m==0)     return 0;
        for(int i=1; i<=n; i++)   e[i].clear();
        while(m--) {
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            e[a].push_back(edge(a,b,c));
//���a���ھӣ�������node[a]��
            e[b].push_back(edge(b,a,c));
        }
        spfa(1);    //�����1
    }
    return 0;
}
