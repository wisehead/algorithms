//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int COIN = 101;                   //��ĿҪ�󲻳���100��Ӳ��
const int MONEY = 251;                  //��Ŀ������Ǯ��������250
int dp[MONEY][COIN] = {0};              // DPת�ƾ���
int type[5] = {1, 5, 10, 25, 50};      //5����ֵ
void solve() {                             // DP
    dp[0][0] = 1;
    for(int i=0; i<5; i++)
        for(int j=1; j<COIN; j++)
            for(int k = type[i]; k < MONEY; k++)
                dp[k][j] += dp[k-type[i]][j-1];
}
int main() {
    int s;
    int ans[MONEY] = {0};
    solve();                          //��DP����������ת�ƾ���
    for(int i=0; i< MONEY; i++)   //��ÿ���������ж�������Ϸ��������
        for(int j=0; j<COIN; j++)  //��0��ʼ��ע�� dp[0][0]=1
            ans[i] += dp[i][j];
    while(cin >> s)
        cout << ans[s] << endl;
    return 0;
}
