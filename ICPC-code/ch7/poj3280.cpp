#include<iostream>
using namespace std;
int w[30],n,m,dp[2005][2005];
char s[2005], ch;
int main() {
    int x,y;
    while(cin>>n>>m) {           //n���õ����ַ�������m��s�ĳ���
       cin>>s;
       for(int i=0;i<n;i++) {
           cin>>ch>>x>>y;         //��ȡÿ���ַ��Ĳ����ɾ���Ļ���
           w[ch-'a']=min(x,y);   //ȡ���е���Сֵ
        }
        for(int i=m-1; i>=0; i--)         //i������������
            for(int j=i+1; j<m; j++) {    //j����������յ�
               if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i+1][j] + w[s[i]-'a'],
                                      dp[i][j-1] + w[s[j]-'a']);
            }
            cout<<dp[0][m-1]<<endl;
    }
    return 0;
}
