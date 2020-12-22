//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int NUM = 103;
int S[NUM];                                         //���鼯
struct Edge {int u, v, w;} edge[NUM*NUM];     //�����
bool cmp(Edge a, Edge b)  { return a.w < b.w; }
int find(int u) { return S[u] == u ? u : find(S[u]); }
              //��ѯ���鼯������u�ĸ����
int n, m;        //�㣬��
int kruskal() {
        int ans = 0;
        for(int i=1; i<=n; i++)
S[i]=i;                //��ʼ������ʼʱÿ����ׯ���ǵ����ļ�
        sort(edge+1, edge+1+m, cmp);
        for(int i = 1; i <= m; i++) {
            int b = find(edge[i].u);    //�ߵ�ǰ�˵�u�����ĸ�����
            int c = find(edge[i].v);    //�ߵĺ�˵�v�����ĸ�����
            if(b == c) continue;         //������Ȧ�����������
            S[c] = b;                      //�ϲ�
            ans += edge[i].w;            //����MST
        }
        return ans;
}
int main() {
    while(scanf("%d", &n), n) {
        m = n*(n-1)/2;
        for(int i = 1; i <= m; i++)     //��Ŀ�У���ı�Ŵ�1��ʼ
            scanf("%d%d%d",&edge[i].u, &edge[i].v, &edge[i].w);
        printf("%d\n", kruskal());
    }
    return 0;
}
