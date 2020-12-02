//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
int id[5000000+5];
struct Node{
    int size;          //��������Ϊ���������Ľ��������������������
    int rank;          //���ȼ�
    int key;           //��ֵ
    Node *son[2];     //son[0]�����, son[1]�Ҷ���
    bool operator < (const Node &a)const{return rank < a.rank;}
    int cmp(int x)const{
        if(x==key) return -1;
        return x<key?0:1;
    }
    void update(){     //����size
        size=1;
        if(son[0]!=NULL) size+= son[0]->size;
        if(son[1]!=NULL) size+= son[1]->size;
        }
};
void rotate(Node* &o,int d){    //d=0����ת��d=1����
        Node *k=o->son[d^1];      //d^1��1-d�ȼۣ����Ǹ���
        o->son[d^1]=k->son[d];
        k->son[d]=o;
        o->update();
        k->update();
        o=k;
    }
void insert(Node* &o,int x){   //��x���뵽����
        if(o==NULL){
            o=new Node();
            o->son[0]=o->son[1]=NULL;
            o->rank=rand();
            o->key=x;
            o->size=1;
        }
        else {
            int d=o->cmp(x);
            insert(o->son[d],x);
            o->update();
            if(o<o->son[d])
                rotate(o,d^1);
        }
    }
int kth(Node* o,int k){   //���ص�k�����
        if(o==NULL||k<=0||k>o->size)
            return -1;
        int s=o->son[1]==NULL?0:o->son[1]->size;
        if(k==s+1) return o->key;
        else if(k<=s) return kth(o->son[1],k);
        else return kth(o->son[0],k-s-1);
    }
int find(Node* o,int k){  //����Ԫ��k������
        if(o==NULL)
            return -1;
        int d=o->cmp(k);
        if(d==-1 )
            return o->son[1] ==NULL? 1: o->son[1]->size+1;
        else if(d==1) return find(o->son[d],k);
        else{
            int tmp=find(o->son[d],k);
            if(tmp==-1) return -1;
            else
                return o->son[1] ==NULL? tmp+1 : tmp+1+o->son[1]->size;
        }
    }
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        srand(time(NULL));
        int k,g;
        scanf("%d%d",&k,&g);
        Node *root=new Node();
        root->son[0]=root->son[1]=NULL;
        root->rank=rand(); root->key=g; root->size=1;
        id[g]=k;
        printf("%d %d\n",k,1);
        for(int i=2;i<=n;i++){
            scanf("%d%d",&k,&g);
            id[g]=k;
            insert(root,g);
            int t=find(root,g);   //�����º��е�����
            int ans1,ans2,ans;
            ans1=kth(root,t-1);   //ǰһ�����Ϻ���
            ans2=kth(root,t+1);   //��һ�����Ϻ���
            if(ans1!=-1&&ans2!=-1)
                ans= ans1-g >= g-ans2 ? ans2:ans1;
            else if(ans1==-1) ans=ans2;
            else ans=ans1;
            printf("%d %d\n",k,id[ans]);
        }
    }
    return 0;
}
