#include <iostream>
using namespace std;

void quicksort(int arr[],int left,int right){
  int i=left,j=right,temp=arr[right];
  if(left>=right) return;
  while(i!=j)
  {
    while(arr[i]<=temp&&i<j) i++;
    while(arr[j]>=temp&&i<j) j--;
    if(i<j)
    {
      int c = arr[i];
      arr[i] = arr[j];
      arr[j] = c;
    }
  }
  arr[right]=arr[i];
  arr[i]=temp;
  quicksort(arr,left,i-1);
  quicksort(arr,i+1,right);
}
int main(){
  int arr[]={9,0,2,3,4,1,8,7,1,2,3,4,10};
  quicksort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
  cout<<arr[i]<<" ";
  return 0;
}

