//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int N = 300;
int sum[N], n;
int Minval() {
    int dp[N][N];
    for(int i=1; i <= n; i++)
        dp[i][i] = 0;
    for(int len=1; len < n; len++)       //len��i��j֮��ľ���
        for(int i=1; i <= n-len; i++) {  //�ӵ�i�ѿ�ʼ
            int j = i + len;               //����j�ѽ���
            dp[i][j] = INF;
            for(int k=i; k<j; k++)         //i��j֮�䣬��k���зָ�
           dp[i][j]=min(dp[i][j],
                       dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
        }
    return dp[1][n];
}
int main() {
    while(cin>>n) {
        sum[0]=0;
        for(int i=1; i<= n; i++) {
int x;
            cin >> x;
            sum[i] = sum[i-1]+x;       //sum[i,j]��ֵ���� sum[j]-sum[i-1]
        }
        cout << Minval() << endl;
    }
    return 0;
}
