//ECUST luoyongjun
#include<stdio.h>
using namespace std;
const int Max = 10000;
struct{
    int l, r, len;      //  ��len�洢�����������ָ���������������ţ��������
}tree[4*Max];           //���￪4������Ϊ�߶����Ŀռ���Ҫ��
int pre[Max], ans[Max];
void BuildTree(int left, int right, int u){     // ������
    tree[u].l = left;
    tree[u].r = right;
    tree[u].len = right - left + 1;              //���½��u��ֵ
if(left == right)
return;
    BuildTree(left, (left+right)>>1, u<<1);    //�ݹ���������
    BuildTree(((left+right)>>1)+1, right, (u<<1)+1);    //�ݹ���������
}
int query(int u, int num){    //��ѯ+ά��������ֵΪ��ǰ����������num��Ԫ�ء�
    tree[u].len --;         //�Է��ʵ�������ά��len��������������ţ��������ȥһ��
    if(tree[u].l == tree[u].r)
        return tree[u].l;
//���1������������ţ�ĸ������������ѯ��������������num - tree[u<<1].len��Ԫ�ء�
    if(tree[u<<1].len < num)
        return query((u<<1)+1, num - tree[u<<1].len);
//���2������������ţ�ĸ����㹻�������ɲ�ѯ��������������num��Ԫ�ء�
    if(tree[u<<1].len >= num)
        return query(u<<1, num);
}
int main(){
    int n, i;
    scanf("%d", &n);
    pre[1] = 0;
    for(i = 2; i <= n; i ++)
        scanf("%d", &pre[i]);
    BuildTree(1, n, 1);
    for(i = n; i >= 1; i --)     //  �Ӻ���ǰ�ƶϳ�ÿ�����һ�����֡�
        ans[i] = query(1, pre[i]+1);
    for(i = 1; i <= n; i ++)
        printf("%d\n", ans[i]);
    return 0;
}
