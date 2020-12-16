//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000+5;
char str[MAXN], pattern[MAXN];
int Next[MAXN];
int cnt;
int getFail(char *p, int plen){
                //Ԥ����Next[]������ʧ�������£��õ�j���ݵ�λ��
    Next[0]=0; Next[1]=0;
    for(int i=1; i < plen; i++){
        int j = Next[i];
        while(j && p[i] != p[j])   j = Next[j];
        Next[i+1] = (p[i]==p[j]) ? j+1 : 0;
    }
}
int kmp(char *s, char *p) {      //��s����p
   int last = -1;
    int slen=strlen(s), plen=strlen(p);
    getFail(p, plen);              //Ԥ����Next[]����
    int j=0;
    for(int i=0; i<slen; i++) {  //ƥ��S��P��ÿ���ַ�
        while(j && s[i]!=p[j])  j=Next[j];  //ʧ���ˣ���Next[]��j�Ļ���λ��
        if(s[i]==p[j])  j++;      //��ǰλ�õ��ַ�ƥ�䣬����
        if(j == plen) {           //��ȫƥ��
           	//���ƥ�䣬��S�е������i+1-plen��ĩβ��i��������Ҫ���Դ�ӡ��
           	// printf("at location=%d, %s\n", i+1-plen,&s[i+1-plen]);
            //-------------------�������뱾����صĹ���
            if( i-last >= plen) {  //�ж��µ�ƥ�����һ��ƥ���Ƿ��ֿܷ�
                cnt++;
                last=i;               //lastָ����һ��ƥ���ĩβλ��
            }
            //-------------------
        }
    }
}
int main(){
    while(~scanf("%s", str)){      //����
        if(str[0] == '#')  break;
        scanf("%s", pattern);      //��ģʽ��
        cnt = 0;
        kmp(str, pattern);
        printf("%d\n", cnt);
    }
    return 0;
}
