//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
int trie[1000010][26];    //���鶨���ֵ������洢��һ���ַ���λ��
int num[1000010]={0};     //��ĳһ�ַ���Ϊǰ׺�ĵ��ʵ�����
int pos = 1;

void Insert(char str[]){    //���ֵ����в���ĳ������
    int c = 0;
    for(int i=0;str[i];i++){
        int n = str[i]-'a';
        if(trie[c][n]==0)    //�����Ӧ�ַ���û��ֵ
            trie[c][n] = pos++;
        c = trie[c][n];
        num[c]++;
    }
}
int Find(char str[]){    //������ĳ���ַ���Ϊǰ׺�ĵ��ʵ�����
    int c = 0;
    for(int i=0;str[i];i++){
        int n = str[i]-'a';
        if(trie[c][n]==0)
            return 0;
        c = trie[c][n];
    }
    return num[c];
}

int main(){
    char str[11];
    while(gets(str)){
        if ( !strlen(str) )  break;  //������һ������
        Insert(str);
    }
    while( gets(str))  cout << Find(str) << endl;
    return 0;
}
int main1(){
    char str[11];
    while(gets(str)){
        if ( !strlen(str) )  break;  //������һ������
        Insert(str);
    }
    while( gets(str))  printf("%d\n",Find(str));
    return 0;
}
