#include <iostream>
#include <bits/stdc.h++>
using namespace std;

int searchkey(int arr[], int n, int key)    //searching Time:O(n); Space:0(1)
{
  for(int i=0; i<10; i++)
  {
    if(arr[i]==key)
      return i;
    else
      return -1;
}

int main()
{
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  int pos = searchkey(arr, n, key);
  
  int key = 5;
  
  if(pos==-1)
  {
    cout<"element not found";
  }
  else
  {
    cout<<"element found at position:"<<pos+1;
  }
  
  return 0;
  
}
  
