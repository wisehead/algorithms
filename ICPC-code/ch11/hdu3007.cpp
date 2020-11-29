//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
const int maxn = 505;
int sgn(double x){
    if(fabs(x) < eps)  return 0;
    else return x<0?-1:1;
}
struct Point{
    double x, y;
};
double Distance(Point A, Point B){return hypot(A.x-B.x,A.y-B.y);}
//��������abc�����Բ��Բ�ģ�
Point circle_center(const Point a, const Point b, const Point c){
    Point center;
    double a1=b.x-a.x, b1=b.y-a.y, c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x, b2=c.y-a.y, c2=(a2*a2+b2*b2)/2;
    double d =a1*b2-a2*b1;
    center.x =a.x+(c1*b2-c2*b1)/d;
    center.y =a.y+(a1*c2-a2*c1)/d;
    return center;
}
//����С����Բ������Բ��c���뾶r��
void min_cover_circle(Point *p, int n, Point &c, double &r){
    random_shuffle(p, p + n);  //����������������е㡣��һ������Ҫ
    c=p[0]; r=0;                  //�ӵ�1����p0��ʼ��Բ��Ϊp0���뾶Ϊ0
    for(int i=1;i<n;i++)         //��չ���е�
        if(sgn(Distance(p[i],c)-r)>0){ //��pi��Բ�ⲿ
            c=p[i]; r=0;                   //��������Բ��Ϊpi���뾶Ϊ0
            for(int j=0;j<i;j++)         //���¼��ǰ�����еĵ㡣
                if(sgn(Distance(p[j],c)-r)>0){   //���㶨Բ
                    c.x=(p[i].x + p[j].x)/2;
                    c.y=(p[i].y + p[j].y)/2;
                    r=Distance(p[j],c);
                    for(int k=0;k<j;k++)
                        if (sgn(Distance(p[k],c)-r)>0){//���㲻�ܶ�Բ�������㶨Բ
                            c=circle_center(p[i],p[j],p[k]);
                            r=Distance(p[i], c);
                        }
                }
        }
}
int main(){
    int n;                //��ĸ���
    Point p[maxn];      //�����
    Point c; double r;  //��С����Բ��Բ�ĺͰ뾶
    while(~scanf("%d",&n) && n){
        for(int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        min_cover_circle(p,n,c,r);
        printf("%.2f %.2f %.2f\n",c.x,c.y,r);
    }
    return 0;
}
