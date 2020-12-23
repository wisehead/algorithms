//ECUST luoyongjun
#include <bits/stdc++.h>
using namespace std;
const double INF = 1e12;
const double pi = acos(-1.0);
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x) < eps)  return 0;
    else return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
};
typedef Point Vector;
double Cross(Vector A,Vector B){return A.x*B.y - A.y*B.x;} //���
struct Line{
	Point p;
	Vector v;
	double ang;
	Line(){};
	Line(Point p,Vector v):p(p),v(v){ang=atan2(v.y,v.x);}
	bool operator < (Line &L){return ang<L.ang;}     //���ڼ�������
};
//��p����L��ߣ�����p����L�����棺
bool OnLeft(Line L,Point p){return sgn(Cross(L.v,p-L.p))>0;}
Point Cross_point(Line a,Line b){    //��ֱ�߽���
    	Vector u=a.p-b.p;
		double t=Cross(b.v,u)/Cross(a.v,b.v);
		return a.p+a.v*t;
}
vector<Point> HPI(vector<Line> L){     //���ƽ�潻������ͼ�����
	int n=L.size();
	sort(L.begin(),L.end());//�����а�ƽ�水�ռ�������
	int first,last;       //ָ��˫�˶��еĵ�һ�������һ��Ԫ��
	vector<Point> p(n);  //�������ڰ�ƽ��Ľ���
	vector<Line> q(n);   //˫�˶���
	vector<Point> ans;   //��ƽ�潻�γɵ�͹��
	q[first=last=0]=L[0];
	for(int i=1;i<n;i++){
		//���1��ɾ��β���İ�ƽ��
		while(first<last && !OnLeft(L[i], p[last-1])) last--;
		//���2��ɾ���ײ��İ�ƽ�棺
		while(first<last && !OnLeft(L[i], p[first]))  first++;
		q[++last]=L[i];     //����ǰ�İ�ƽ�����˫�˶���β��
		//������ͬ��������ƽ�棬������ߣ�
		if(fabs(Cross(q[last].v,q[last-1].v)) < eps){
			last--;
			if(OnLeft(q[last],L[i].p)) q[last]=L[i];
		}
		//�������β����ƽ�潻�㣺
		if(first<last) p[last-1]=Cross_point(q[last-1],q[last]);
	}
	//���3��ɾ������β�������ð�ƽ��
	while(first<last && !OnLeft(q[first],p[last-1])) last--;
	if(last-first<=1) return ans;   //�ռ�
	p[last]=Cross_point(q[last],q[first]);  //���������β���Ľ��㡣
	for(int i=first;i<=last;i++)  ans.push_back(p[i]);   //���ơ�
	return ans;               //����͹�����
}
int main(){
     int T,n;
		cin>>T;
		while(T--){
			cin>>n;
		    vector<Line> L;
		   //��һ����ƽ��F:����y��
         L.push_back(Line(Point(0,0),Vector(0,-1)));
			//��һ����ƽ��E:y����������ֱ��
		    L.push_back(Line(Point(0,INF),Vector(-1,0)));
  	    while(n--){
				double a,b;
				scanf("%lf%lf",&a,&b);
			 	L.push_back(Line(Point(0,a),Vector(1,b)));
		 }
		 vector<Point> ans=HPI(L);        //�õ�͹�����
		 printf("%d\n",ans.size()-2);    //ȥ����Ϊ�ӵ�������
	 }
     return 0;
}
