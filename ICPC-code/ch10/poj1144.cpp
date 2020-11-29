#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=109;
int low[N],num[N],dfn;
bool iscut[N];
vector <int> G[N];
void dfs(int u, int fa){       //u�ĸ������fa
	low[u] = num[u] = ++ dfn;     //��ʼֵ
	int child = 0;                  //������Ŀ
	for (int i = 0;i < G[u].size(); i++)	{   //����u�������ӽ��
		int v = G[u][i];
		if (!num[v]) {              //vû���ʹ�
		    child++;
			dfs(v, u);
			low[u] = min(low[v], low[u]);    //�ú���ķ���ֵ����lowֵ
			if (low[v] >= num[u] && u !=1)
                iscut[u] = true;              //��Ǹ��
		}
		else if(num[v] < num[u] && v != fa)
 		       //������˱ߣ�ע������v != fa��fa��u�ĸ���㣬
       //faҲ��u���ھӣ�����ǰ���Ѿ����ʹ�������Ҫ������
            low[u] = min(low[u], num[v]);
	}
	if (u == 1 && child >= 2)     //����㣬���������ϲ�����������
        iscut[1] = true;
}
int main(){
    int ans,n;
	while (scanf("%d",&n)!=-1){
		if (n==0)break;
		memset(low,0,sizeof(low));
		memset(num,0,sizeof(num));
		dfn=0;
		for (int i=0;i<=n;i++) G[i].clear();
		int a,b;
		while (scanf("%d",&a)&&a)
			while (getchar()!='\n'){
				scanf("%d",&b);
				G[a].push_back(b);
				G[b].push_back(a);
			}
		memset(iscut,false,sizeof(iscut));
		ans = 0;
		dfs(1,1);
		for (int i=1;i<=n;i++) ans+=iscut[i];
		printf("%d\n",ans);
	}
}
