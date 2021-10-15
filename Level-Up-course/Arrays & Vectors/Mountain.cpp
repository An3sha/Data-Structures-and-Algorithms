/* Time Complexity : O(N) */

#include<iostream>
using namespace std;

int highest_mountain(vector<int> a)
{
  int n = a.size();
  
  int largest = 0;  
  
  for(int i=1; i<=n-2; )       //first and second element cannot be a peak
  
  {
    //check a[i] is peak or not
    if(a[i]>a[i-1] && a[i]>a[i+1])
    {
      int cnt = 1;
      int j = 1;
      //count backwards(left)
      while(j>=1 && a[j]>a[j-1])        
      {
        j--;
        cnt++;
      }
      //count forwards(right)
      while(i<=n-2 && a[i]>a[i+1])            //putting constraints j>=1 and i<=n-2 because we cannot access a value that is outside array
      {
        i++;
        cnt++;
      }
      largest = max(largest, cnt);
    }
    else
    {
     i++;
    }
  }
  return largest;
}

int main()
{
  vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
  
  cout << highest_mountain(arr);
  
  
  return 0;
}
