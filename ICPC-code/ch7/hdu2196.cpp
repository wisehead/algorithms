//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int N = 10100;
struct Node{
    int id;                  //�ӽ��ı��
    int cost;
};
vector<Node> tree[N];
int dp[N][3];
int n;
void init_read(){
    for(int i=1; i<=n; i++)
       tree[i].clear();
    memset(dp, 0, sizeof(dp));
    for(int i=2; i<=n; i++) {
       int x,y;
       scanf("%d%d",&x,&y);
       Node tmp;
       tmp.cost = y;
       tmp.id=i;              //i��x���ӽ��
       tree[x].push_back(tmp);
    }
}
void dfs1(int father) {     //dfs���ȴ����ӽ�㣬�ٴ������
    int one=0, two=0;
    for(int i=0; i<tree[father].size(); i++) {
                                 //�������father�������ӽ��
        Node child = tree[father][i];
        dfs1(child.id);       //�ݹ��ӽ�㣬ֱ����ײ�
        int cost = dp[child.id][0] + child.cost;
        if(cost >= one) {    //��one��¼��father�����ߵ������
            two = one;         //ԭ���������one����ɵ�2������two��¼
            one = cost;
        }
        if(cost < one && cost >two)     //��two��¼��2���ľ���
            two = cost;
    }
    dp[father][0] = one;  //�õ���fatherΪ���������������
    dp[father][1] = two;  //�õ���fatherΪ���������ĵ�2������
}
void dfs2(int father) {    //�ȴ�����㣬�ٴ����ӽ��
    for(int i=0; i<tree[father].size(); i++) {
        Node child = tree[father][i];
        if(dp[child.id][0]+ child.cost == dp[father][0])
                                //child��������������
            dp[child.id][2] = max(dp[father][2],
                                       dp[father][1]) + child.cost;
        else                    //child����������������
            dp[child.id][2] = max(dp[father][2],
                                       dp[father][0]) + child.cost;
        dfs2(child.id);
    }
}
int main(){
    while(~scanf("%d", &n)) {
        init_read();          //��ʼ����������
        dfs1(1);               //����dp[][0]��dp[][1]
        dp[1][2]=0;
        dfs2(1);               //����dp[][2]
        for(int i=1; i<=n; i++)
            printf("%d\n", max(dp[i][0], dp[i][2]));
    }
    return 0;
}
