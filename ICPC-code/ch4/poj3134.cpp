//ECUST: luoyongjun
#include <iostream>
using namespace std;
int val[1010];                           //��һ������·����ÿһ���ļ�����
int pos, n;
bool ida(int now, int depth){
    if(now > depth)  return false;     //IDDFS�����ڵ�ǰ�趨��DFS��ȣ��˳�
    if(val[pos] << (depth - now) < n)
return false;                //���ۺ����������ı����������ܵ���n���˳�
    if(val[pos] == n)  return true;    //��ǰ�������n����������
    pos ++ ;
    for(int i = 0 ; i < pos ; i ++) {
        val[pos] = val[pos-1] + val[i]; //��һ������ǰ�����е������
        if(ida(now + 1, depth))   return true;
        val[pos] = abs(val[pos-1] - val[i]);//��һ������ǰ�����е������
        if(ida(now + 1, depth))   return true;
    }
    pos -- ;
    return false;
}
int main(){
    int t;
    while(cin>>n && n){
        int depth;
        for(depth = 0 ; ; depth ++){ //ÿ��ֻDFS�����depth
            val[pos = 0] = 1;          //��ʼֵ��1
            if(ida(0, depth)) break; //ÿ�ζ���0�㿪ʼDFS����depth��
        }
        cout << depth << endl;
    }
    return 0;
}
