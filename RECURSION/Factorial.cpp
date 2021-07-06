#include<iostream>
using namesoace std;

int fact(int n)
{
  if(n==0)
  {
    return 1;
  }
  int ans = n * fact(n-1);
  return ans;
}

int main()
{
  int n;
  cin>>n;
  
  cout<<fact(n)<<endl;
  
  return 0;
}
