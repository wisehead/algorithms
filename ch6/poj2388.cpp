//ECUST luoyongjun
#include"stdio.h"
const int N = 10010;
int data[N];
#define swap(a, b) {int temp = a; a = b; b = temp;} //����
int partition(int left, int right){    //���ֳ����������֣���iָ�����Ϊ��
    int i = left;
	int temp = data[right];             //��β���������ɻ�׼��
    for(int j = left; j < right; j++)
        if(data[j] < temp){
            swap(data[j], data[i]);
            i++;
        }
    swap(data[i], data[right]);
	return i;                             //���ػ�׼����λ��
}
void quicksort(int left, int right){
	if(left < right){
        int i = partition(left, right);    //����
		quicksort(left, i-1);              //���Σ�i��ߵļ����ݹ黮��
		quicksort(i+1, right);    	     //���Σ�i�ұߵļ����ݹ黮��
	}
}
int main(){
    int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)  scanf("%d", &data[i]);
	quicksort(1, n);
	printf("%d\n", data[(n+1)/2]);
	return 0;
}
