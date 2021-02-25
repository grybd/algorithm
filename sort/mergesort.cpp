#include <iostream>
#include <string.h>
using namespace std;

void merge(int arr[],int left,int mid,int right,int temp[]);

void mergesort(int arr[], int left,int right,int temp[])
{
  if(left<right)
  {
    int mid=(left+right)/2;
    mergesort(arr,left,mid,temp);//左边归并排序，使得左子序列有序；
    mergesort(arr,mid+1,right,temp);//右边归并排序，使得右子序列有序；
    merge(arr,left,mid,right,temp);//将两个有序子数组合并操作；
  }
}
void merge(int arr[],int left,int mid,int right,int temp[])
{
  int i=left;//左序列指针
  int j=mid+1;//右序列指针；
  int t=0;//临时数组指针；
  while(i<=mid&&j<=right)
  {
    if(arr[i]<=arr[j])
    {
      temp[t++]=arr[i++];
    }
    else
    {
      temp[t++]=arr[j++];
    }
  }
  while(i<=mid)
  {
    //将左边剩余元素填充进temp中
    temp[t++]=arr[i++];
  }
  while(j<=right)
  {
    //将右序列剩余元素填充进temp中
    temp[t++]=arr[j++];
  }
  t=0;
  //将temp中的元素全部拷贝到原数组中
  while(left<=right)
  {
    arr[left++]=temp[t++];
  }
}

int  main()
{
  int arr[] = {1,4,3,2,6,7,5,9,8};
  int temp[9];
  memset(temp,0,sizeof(temp));
  for(int i=0;i<9;i++)
  {
    cout<<temp[i]<<'\n'<<endl;
  }
  mergesort(arr,0,8,temp);
  for(int i=0;i<9;i++)
  {
    cout<<arr[i]<<endl;
  }
}
/*
void merge_sort_recursive(int arr[],int reg[],int start,int end)
{
  if(start>=end)
  {
    return;
  }
  int len=end-start,mid=(len>>1)+start;
  int start1=start,end1=mid;
  int start2=mid+1,end2=end;
  merge_sort_recursive(arr,reg,start1,end1);
  merge_sort_recursive(arr,reg,start2,end2);
  int k=start;
  while(start1<=end1&&start2<=end2)
  {
    reg[k++]=arr[start1]<arr[start2]?arr[start1++]:arr[start2++];
  }
  while(start1<=end1)
  {
    reg[k++]=arr[start1++];
  }
  while(start2<=end2)
  {
    reg[k++]=arr[start2++];
  }
  for(k=start;k<=end;k++)
  {
    arr[k]=reg[k];
  }
}

void merge_sort(int arr[],const int len)
{
  int reg[len];
  merge_sort_recursive(arr,reg,0,len-1);
}

int main()
{
  int arr[]={1,3,5,4,2,6,8,7,9};
  merge_sort(arr,9);
  for(int i=0;i<9;i++)
  {
    cout<<arr[i];
  }
}
*/

