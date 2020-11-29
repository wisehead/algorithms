//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX / 10;
const int NUM = 1000005;     //һ�������,һ�������
struct Edge{   //�ߣ�edge[i]��i������㣬�յ�to��Ȩֵw����һ����next
int to, next, w;
}edge[NUM];
int n, m, cnt;
int head[NUM];
int dis[NUM];            //��¼���н�㵽���ľ���
bool inq[NUM];           //inq[i] = true ��ʾ���i�ڶ�����
int Neg[NUM];            //�жϸ�Ȧ(Negative loop)
int pre[NUM];             //��¼ǰ����㡣
void print_path(int s,int t) {   //��ӡ��s��t�����·��
   ;         //������Bellman-Ford�����е�print_path()��ȫһ��
}
void init(){
    for(int i = 0; i < NUM; ++i){
        edge[i].next = -1;
        head[i] = -1;
    }
    cnt = 0;
}
void addedge(int u, int v, int w){      //ǰ���Ǵ�ͼ
   edge[cnt].to = v;
   edge[cnt].w = w;
   edge[cnt].next = head[u];
   head[u] = cnt++;
}
int spfa(int s) {
    memset(Neg, 0, sizeof(Neg));
    Neg[s] = 1;
    for(int i=1; i<=n; i++) { dis[i]=INF;  inq[i]=false; }   //��ʼ��
    dis[s] = 0;             //��㵽�Լ��ľ�����0
    queue<int> Q;
    Q.push(s);
    inq[s] = true;           //��������

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();    //��ͷ����
        inq[u] = false;
        for(int i=head[u]; ~i; i = edge[i].next) {//~iҲ����д�� i!=-1
            int v = edge[i].to, w = edge[i].w;
            if (dis[u]+w < dis[v]) {
//u�ĵ�i���ھ�v�������u����s����
                dis[v] = dis[u]+w;   //���µ�i���ھӵ�s�ľ���
                pre[v] = u;           //�������Ҫ����¼·��
                if(!inq[v]) {
            //�ھ�v����״̬�ˣ����������ڶ����У������Ž�����
                    inq[v] = true;
                    Q.push(v);
                    Neg[v]++;
                    if(Neg[v] > n) return 1;    //���ָ�Ȧ
                }
            }
        }
    }
    printf("%d\n",dis[n]);  //��s��n����̾���
    // print_path(s,n);     //�������Ҫ����ӡ·��
    return 0;
}
int main() {
    while(~scanf("%d%d",&n,&m)) {
init();
       	if(n==0 && m==0) return 0;
       	while(m--) {
            int u,v,w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u,v,w);
            addedge(v,u,w);
       	}
       	spfa(1);
    }
    return 0;
}
