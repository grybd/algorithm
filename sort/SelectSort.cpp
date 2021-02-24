#include <iostream>
#include <vector>
using namespace std;
template<typename T>

void selection_sort(vector<T>&arr)
{
  for(int i=0;i<arr.size()-1;i++)
  {
    int min=i;
    for(int j=i+1;j<arr.size();j++)
    {
      if(arr[j]<arr[min])
      {
        min=j;
      }
    }
    swap(arr[i],arr[min]);
  }
}

