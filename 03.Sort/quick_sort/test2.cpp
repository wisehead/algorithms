/*******************************************************************************
 *      file name: quit_sort.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/12-07:55:33                              
 *  modified time: 2020/09/12-07:55:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void qsort(vector<int> &vec, int start, int end) {
	if (start >= end) return;
	cout<<"===begin=="<<endl;
    for (int i = start; i <= end; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
	int pivot = start;
	int l = start;
	int r = end;
	while (l < r ) {
		while (vec[l] <= vec[pivot]) l++;
		while (vec[r] > vec[pivot]) r--;
		if (l<r) {
			swap(vec[l], vec[r]);
		}
		cout<<"===xxx process=="<<endl;
		cout<<"start:"<<start<<",end:"<<end<<",l:"<<l<<",r:"<<r<<endl;
		for (int i = start; i <= end; i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	//if (start != r)
	swap(vec[start], vec[r]);
	pivot = r;
	cout<<"===process=="<<endl;
	cout<<"start:"<<start<<",end:"<<end<<",l:"<<l<<",r:"<<r<<endl;
    for (int i = start; i <= end; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
	qsort(vec, start, pivot-1);
	qsort(vec, pivot+1, end);
	cout<<"===end=="<<endl;
    for (int i = start; i <= end; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main()
{
	int arr[] = {5,9,2,8,1,3,4,7,6};
	vector<int> vec(arr, arr+9);
	qsort(vec, 0, 8);
}
