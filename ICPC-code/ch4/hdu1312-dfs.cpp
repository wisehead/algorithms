//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
char room[23][23];
int dir[4][2] = {
    {-1,0},  //�������Ͻ�������(0, 0)
    {0,-1},  //����
    {1,0},   //����
    {0,1}    //����
};
int Wx, Hy, num;                 //Wx�У�Hy�С���numͳ�ƿ��ߵ�λ���ж���
#define CHECK(x, y) (x<Wx && x>=0 && y >=0 && y<Hy) //�Ƿ���room��
struct node {int x,y;};
void DFS(int dx, int dy){
    room[dx][dy] = '#';                 //������λ�ã���ʾ�Ѿ��߹�
      // cout<<"walk:"<<dx<<dy<<endl; //�ڴ˴���ӡ�߹���λ�ã���֤�Ƿ����
    num++;
    for(int i = 0; i < 4; i++) {      //���ϡ��ҡ��£�4������˳ʱ������
        int newx = dx + dir[i][0];
        int newy = dy + dir[i][1];
        if(CHECK(newx, newy) && room[newx][newy] == '.'){
             DFS(newx, newy);
             // cout<<"    back:"<<dx<<dy<<endl;
 //�ڴ˴���ӡ���˵ĵ�����꣬�۲����ѵ��׺󣬻��˵����
//���絽������15���λ�ú󣬻�һֱ�˵����
//����ӡ��14-11-10-9-8-7-6-5-4-3-2-1����Ҳ�ǵݹ���򷵻صĹ���
        }
    }
}

int main(){
    int x, y, dx, dy;
    while (cin >> Wx >> Hy) {   	          //Wx�У�Hy��
        if (Wx==0 && Hy==0)   			 //����
            break;
        for (y = 0; y < Hy; y++) {         //��Hy��
            for (x = 0; x < Wx; x++) { 	 //һ�ζ���һ��
                cin >> room[x][y];
                if(room[x][y] == '@') {     //�������
                    dx = x;
                    dy = y;
                }
            }
        }
        num = 0;
        DFS(dx, dy);
        cout << num << endl;
    }
    return 0;
}
