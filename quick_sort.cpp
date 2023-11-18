#include <iostream>
using namespace std;
//分治思想
//对整体部分进行分区
//双指针
void quick_sort(int arr[],int L,int R)
{
    if(L>=R) return;
    //随机取数，之后和arr[L]交换
    swap(arr[L],arr[L+rand()%(R-L+1)]);
    int x=arr[L];
    //设置指针
    int i=L,j=R;
    while(i<j)
    {
        while(i<j&&arr[j]>x)
        j--;
        if(i<j) arr[i++]=arr[j];
        while(i<j&&arr[i]<x)
        i++;
        if(i<j) arr[j--]=arr[i];
    }
    arr[i]=x;
    quick_sort(arr,L,i-1);
    quick_sort(arr,i+1,R);
}
 
int main()
{
    int arr[]={1,2,12,3,23,6,34,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
}

//c++有库函数
//  #include<algorithm>
//  对于数组arr[]:   sort(arr,arr+n);实现快速排序