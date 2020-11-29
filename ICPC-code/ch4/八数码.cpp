//ECUST   luoyongjun
#include<bits/stdc++.h>
const int LEN = 362888;       //״̬��9!=362880��
using namespace std;
struct node{
    int state[9];       //��¼һ������������У���һ��״̬
    int dis;             //��¼�����ľ���
};

int dir[4][2] = {{-1,0}, {0,-1},{1,0},{0,1}};
           //���ϡ��ҡ���˳ʱ�뷽�����Ͻ�������(0,0)
int visited[LEN]={0};  //��ÿ��״̬��Ӧ�ļ�¼��Cantor��������������������
int start[9];            //��ʼ״̬
int goal[9];             //Ŀ��״̬
long int factory[] = {1,1,2,6,24,120,720,5040,40320,362880};
                             //Cantor�õ��ĳ���
bool Cantor(int str[], int n) {     //�ÿ���չ������
    long result = 0;
    for(int i = 0; i < n; i++) {
        int counted = 0;
        for(int j = i+1; j < n; j++) {
            if(str[i] > str[j])       //��ǰδ���ֵ�Ԫ���������ڵڼ���
                ++counted;
        }
        result += counted*factory[n-i-1];
    }
    if(!visited[result]) {            //û�б����ʹ�
        visited[result] = 1;
        return 1;
    }
    else
        return 0;
}
int bfs() {
    node head;
    memcpy(head.state, start, sizeof(head.state));  //��������״̬
    head.dis = 0;
    queue <node> q;          //�����з�״̬
    Cantor(head.state, 9);  //�ÿ���չ�����أ�Ŀ���Ƕ�����visited[]����ֵ
    q.push(head);             //��һ�������е������״̬

    while(!q.empty()) {              //�������
        head = q.front();
        q.pop();                       //���ڴ˴���ӡhead.state�����������е����
        int z;
        for(z = 0; z < 9; z++)        //�����״̬��Ԫ��0��λ��
            if(head.state[z] == 0)    //�ҵ���
                break;
            //ת��Ϊ��ά�����Ͻ���ԭ��(0, 0)��
        int x = z%3;          //������
        int y = z/3;          //������
        for(int i = 0; i < 4; i++){   //�ϡ��¡�������������4����״̬
            int newx = x+dir[i][0];    //Ԫ��0ת�ƺ��������
            int newy = y+dir[i][1];
            int nz = newx + 3*newy;    //ת��Ϊһά
            if(newx>=0 && newx<3 && newy>=0 && newy<3) {//δԽ��
                node newnode;
                memcpy(&newnode,&head,sizeof(struct node));//�������µ�״̬
                swap(newnode.state[z], newnode.state[nz]);//��0�ƶ����µ�λ��
                newnode.dis ++;
                if(memcmp(newnode.state,goal,sizeof(goal)) == 0)
                                                           //��Ŀ��״̬�Ա�
                    return newnode.dis;             //����Ŀ��״̬�����ؾ��룬����
                if(Cantor(newnode.state, 9))         //�ÿ���չ������
                    q.push(newnode);                   //���µ�״̬�Ž�����
             }
        }
    }
    return -1;            //û�ҵ�
}
int main(){
    for(int i = 0; i < 9; i++)  cin >> start[i];       //��ʼ״̬
    for(int i = 0; i < 9; i++)  cin >> goal[i];        //Ŀ��״̬
    int num = bfs();
    if(num != -1)  cout << num << endl;
    else          cout << "Impossible" << endl;
    return 0;
}
