//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
struct node{
    char name[35];
    int price;
};
vector<node> List[N];                    //���ڽ����ͻ
unsigned int BKDRHash(char *str)  {    //��ϣ����
    unsigned int seed = 31,key = 0;
    while(*str)
        key = key*seed+(*str++);
    return key & 0x7fffffff;
}
int main(){
    int n, m, key, add, memory_price, rank, len;
    int p[N];
    char s[35];
    node t;
    while(cin>>n){
        for(int i=0; i<N; i++)
            List[i].clear();
        for(int i=0;i<n;i++){
            cin>>t.name;
            key = BKDRHash(t.name) % N;  //����hashֵ��������
            List[key].push_back(t);    //hashֵ���ܳ�ͻ���ѳ�ͻ�Ĺ�ϣֵ��������
        }
        cin>>m;
        while(m--){
            rank = len = 0;
            for(int i=0; i<n; i++){
                cin>>add>>s;
                key = BKDRHash(s) % N;                   //����hashֵ
                for(int j=0; j<List[key].size(); j++)    //�����ͻ����
                    if(strcmp(List[key][j].name, s)==0){
                        List[key][j].price += add;
                        if(strcmp(s,"memory") == 0)
                            memory_price = List[key][j].price;
                        else
                            p[len++] = List[key][j].price;
                        break;
                    }
            }
            for(int i=0; i<len; i++)
                if(memory_price < p[i])
                    rank++;
            cout<<rank+1<<endl;
        }
    }
    return 0;
}
