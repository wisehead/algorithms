//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
int n, tot = 0;
int col[12] = {0};
bool check(int c, int r) {              //����Ƿ���Ѿ��źõĻʺ��ͻ
    for(int i = 0; i < r; i++)
        if(col[i] == c || (abs(col[i]-c) == abs(i -r))) //ȡ����ֵ
            return false;
    return true;
}
void  DFS(int r) {                   //һ��һ�еطŻʺ���һ���ǵ�r��
    if(r == n) {             //���лʺ󶼷ź��ˣ��ݹ鷵��
       tot++;                  //ͳ�ƺϷ�����ָ���
       return;
    }
    for(int c = 0; c < n; c++)      //��ÿһ�зŻʺ�
        if(check(c, r)){              //����Ƿ�Ϸ�
            col[r] = c;                //�ڵ�r�е�c�зŻʺ�
            DFS(r+1);                   //��������һ�лʺ�
        }
}
int main() {
    int ans[12]={0};
    for(n = 0; n <= 10; n++){      //�������n�ʺ�Ĵ𰸡��ȴ��Ȼ�ᳬʱ
        memset(col,0,sizeof(col)); //��գ�׼��������һ��N�ʺ�����
        tot = 0;
        DFS(0);
        ans[n] = tot;                //���
    }
    while(cin >> n) {
        if(n==0)
           return 0;
        cout << ans[n] << endl;
    }
    return 0;
}
