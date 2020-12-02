//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int s[maxn];
int height[maxn];
void init_set(){
   for(int i = 1; i <= maxn; i++){
        s[i] = i;
        height[i]=0;                     //���ĸ߶�
   }
}

int find_set(int x){
    if(x != s[x]) s[x] = find_set(s[x]);   //·��ѹ��
    return s[x];
}
void union_set(int x, int y){         //�Ż��ϲ�����
    x = find_set(x);
    y = find_set(y);
    if (height[x] == height[y]) {
        height[x] = height[x] + 1;      //�ϲ������ĸ߶ȼ�һ
        s[y] = x;
    }
    else{                            //�Ѱ������������ϣ��ߵ����ĸ߶Ȳ���
        if (height[x] < height[y])  s[x] = y;
        else   s[y] = x;
    }
}



int main (){
    int t, n, m, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init_set();
        for(int i = 1; i <= m; i++){
            cin >> x >> y;
            union_set(x, y);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)   //ͳ���ж��ٸ���
            if(s[i] == i)
                ans++;
        cout << ans <<endl;
    }
    return 0;
}
