//Time Complexity: O(N) 
//Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

int findelement(int arr[], int n, int key)
{
  for(int i=0; i<n; i++)
  {
    if(arr[i]==key)
      return i;
    return -1;
  }
}
  
 int deletion(int arr[], int n, int key)
  {
    int pos = findelement(arr, n, key);
    
    if(pos==-1)
    {
      cout<<"element not found";
      return n;
    }
    //deleting element
    for(int i=pos; i<n-1; i++)
    {
      arr[i]=arr[i+1];
    }
    return n-1;
  }
      
  
  int main()
  {
    int arr[] = {10, 50, 30, 40, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 30;
    
    cout<<"Array before deletion";
    for(int i=0; i<n; i++)
    {
      cout<<arr[i]<<" ";
    }
    
    n = deletion(arr, n, key);
    
    cout<<"Array after deletion";
    for(int i=0; i<n; i++)
    {
      cout<<arr[i]<<" ";
    }
    
    return 0;
    
  }
    
    
