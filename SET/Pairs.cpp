/* Input = 10, 5, 2, 3, -6, 9, 11
   sum = 4
   output = 10, -6 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int sum)
{
  unordered_set<int> s;
  vector<int> result;
  for(int i=0; i<arr.size(); i++)
  {
    int x = sum - arr[i];
    if(s.find(x)!=s.end())        // if (stringSet.find(key) == stringSet.end()) means the number is not present
    {
      result.push_back(x);
      result.push_back(arr[i]);
      return result;
    }
    s.insert(arr[i]);
 }
  return {};
}


int main()
{
  vector<int> arr{10, 5, 2, 3, -6, 9, 11};
  int S = 4;
  
  auto p = pairSum(arr,S);
  if(p.size()==0)
  {
    cout<<"No such pair";
  }
  else
  {
    cout<<p[0]<<","<<p[1]<<endl;
  }
  return 0;
}
