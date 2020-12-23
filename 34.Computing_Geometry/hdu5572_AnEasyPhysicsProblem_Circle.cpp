//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;  //��������趨eps=1e-10����Wrong Answer
int sgn(double x){         //�ж�x�Ƿ����0
    if(fabs(x) < eps)  return 0;
    else return x<0?-1:1;
}
struct Point{               //�����ͻ�������
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
};
typedef Point Vector;                          //��������
double Dot(Vector A,Vector B){return A.x*B.x + A.y*B.y;} //���
double Len(Vector A){return sqrt(Dot(A,A));}   //�����ĳ���
double Len2(Vector A){return Dot(A,A);}         //�������ȵ�ƽ��
double Cross(Vector A,Vector B){return A.x*B.y - A.y*B.x;} //���
double Distance(Point A, Point B){return hypot(A.x-B.x,A.y-B.y);}
struct Line{
    Point p1,p2;
    Line(){}
    Line(Point p1,Point p2):p1(p1),p2(p2){}
};
typedef Line Segment;             //�����߶Σ����˵���p1,p2
int Point_line_relation(Point p,Line v){
    int c = sgn(Cross(p-v.p1,v.p2-v.p1));
    if(c < 0)return 1;       //1��p��v�����
    if(c > 0)return 2;       //2��p��v���ұ�
    return 0;                 //0��p��v��
}
double Dis_point_line(Point p, Line v){ //�㵽ֱ�ߵľ���
    return fabs(Cross(p-v.p1,v.p2-v.p1))/Distance(v.p1,v.p2);
}
//�㵽�߶εľ���
double Dis_point_seg(Point p, Segment v){
    if(sgn(Dot(p- v.p1,v.p2-v.p1))<0 || sgn(Dot(p- v.p2,v.p1-v.p2))<0)
        return min(Distance(p,v.p1),Distance(p,v.p2));
    return Dis_point_line(p,v);
}
//����ֱ���ϵ�ͶӰ
Point Point_line_proj(Point p, Line v){
    double k=Dot(v.p2-v.p1,p-v.p1)/Len2(v.p2-v.p1);
    return v.p1+(v.p2-v.p1)*k;
}
//��p��ֱ��v�ĶԳƵ�
Point Point_line_symmetry(Point p, Line v){
    Point q = Point_line_proj(p,v);
    return Point(2*q.x-p.x,2*q.y-p.y);
}
struct Circle{
    Point c;       //Բ��
    double r;      //�뾶
    Circle(){}
    Circle(Point c,double r):c(c),r(r){}
    Circle(double x,double y,double _r){c=Point(x,y);r = _r;}
};
//�߶κ�Բ�Ĺ�ϵ��0 �߶���Բ��, 1 �߶κ�Բ����, 2 �߶���Բ��
int Seg_circle_relation(Segment v,Circle C){
    double dst = Dis_point_seg(C.c,v);
    if(sgn(dst-C.r) < 0) return 0;
    if(sgn(dst-C.r) ==0) return 1;
    return 2;
}
//ֱ�ߺ�Բ�Ĺ�ϵ��0 ֱ����Բ��, 1 ֱ�ߺ�Բ����, 2 ֱ����Բ��
int Line_circle_relation(Line v,Circle C){
    double dst = Dis_point_line(C.c,v);
    if(sgn(dst-C.r) < 0) return 0;
    if(sgn(dst-C.r) ==0) return 1;
    return 2;
}
//ֱ�ߺ�Բ�Ľ��㣬pa, pb�ǽ��㡣����ֵ�ǽ������
int Line_cross_circle(Line v,Circle C,Point &pa,Point &pb){
    if(Line_circle_relation(v, C)==2) return 0;    //�޽���
    Point q = Point_line_proj(C.c,v);        //Բ����ֱ���ϵ�ͶӰ��
    double d = Dis_point_line(C.c,v);        //Բ�ĵ�ֱ�ߵľ���
    double k = sqrt(C.r*C.r-d*d);
    if(sgn(k) == 0){                             //1�����㣬ֱ�ߺ�Բ����
        pa = q;   pb = q;  return 1;
    }
    Point n=(v.p2-v.p1)/ Len(v.p2-v.p1);  //��λ����
    pa = q + n*k;
    pb = q - n*k;
    return 2;                                   //2������
}
int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        Circle O; Point A,B,V;
        scanf("%lf%lf%lf", &O.c.x, &O.c.y, &O.r);
        scanf("%lf%lf%lf%lf", &A.x, &A.y, &V.x, &V.y);
        scanf("%lf%lf", &B.x, &B.y);
        Line l(A, A+V);      //����
        Line t(A, B);
            //�����1��ֱ�ߺ�Բ���ཻ������ֱ�߾�����
        if(Point_line_relation(B,l)==0
            && Seg_circle_relation(t,O)>=1 && sgn(Cross(B-A,V))==0)
            printf("Case #%d: Yes\n", cas);
        else{
            Point pa, pb;         //ֱ�ߺ�Բ�Ľ���
           //�����2��ֱ�ߺ�Բ���У���������
           if(Line_cross_circle(l,O,pa,pb) != 2)
				printf("Case #%d: No\n",cas);
           //�����3��ֱ�ߺ�Բ�ཻ
           else{
                Point cut; //ֱ�ߺ�Բ����ײ��
                if(Distance(pa,A) > Distance(pb,A)) cut = pb;
                else cut = pa;
                Line mid(cut, O.c); //Բ�ĵ���ײ��ĵ�ֱ��;
                Point en = Point_line_symmetry(A,mid);  //�����
                Line light(cut, en);                       //������
                if(Distance(light.p2,B) > Distance(light.p1,B))
				  swap(light.p1, light.p2);                							 	  if(sgn(Cross(light.p2-light.p1,
							    Point(B.x-cut.x,B.y-cut.y)))== 0)
                printf("Case #%d: Yes\n", cas);
                else
				   printf("Case #%d: No\n", cas);
            }
        }
    }
    return 0;
}
