//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 100010;
const double INF = 1e20;
int sgn(double x){
    if(fabs(x) < eps)  return 0;
    else return x<0?-1:1;
}
struct Point{
    double x,y;
 };
double Distance(Point A, Point B){return hypot(A.x-B.x,A.y-B.y);}
bool cmpxy(Point A,Point B){     //�����ȶԺ�����x�����ٶ�y����
	return sgn(A.x-B.x)<0 || (sgn(A.x-B.x)==0 && sgn(A.y-B.y)<0);
}
bool cmpy (Point A,Point B){return sgn(A.y-B.y)<0;}//ֻ��y��������
Point p[MAXN],tmp_p[MAXN];
double Closest_Pair(int left,int right){
    double dis = INF;
    if(left == right) return dis;      //ֻʣ1����
    if(left + 1 == right)                //ֻʣ2����
        return Distance(p[left], p[right]);
    int mid = (left+right)/2;           //����
    double d1 = Closest_Pair(left,mid);      //��s1�ڵ�������
    double d2 = Closest_Pair(mid+1,right);  //��s2�ڵ�������
    dis = min(d1,d2);
    int k = 0;
    for(int i=left;i<=right;i++)       //��s1��s2�м丽���ҿ��ܵ���С���
        if(fabs(p[mid].x - p[i].x) <= dis)  //��x��������
            tmp_p[k++] = p[i];
	sort(tmp_p,tmp_p+k,cmpy);//��y�����������ڼ�֦�����ﲻ�ܰ�x��������
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++){
            if(tmp_p[j].y - tmp_p[i].y >= dis)  break;    //��֦
            dis = min(dis,Distance(tmp_p[i],tmp_p[j]));
        }
	return dis;  //������С����
}
int main(){
    int n;
    while(~scanf("%d",&n) && n){
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmpxy);                          //������
        printf("%.2f\n",Closest_Pair(0,n-1)/2); //�����̾����һ��
    }
    return 0;
}
