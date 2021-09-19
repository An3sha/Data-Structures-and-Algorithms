#include<iostream>
#include<vector>
using namespace std;

int main()
{
  //Demo vector
  vector<int> arr = {1, 2, 10, 12, 15};
  
  //Fill Constructor
  vector<int> arr(10, 7);     // push 10 time 7
  
  //Pop_back O(1)
  arr.pop_back();
  
  //Push_back O(1)
  arr.push_back(16);
  
  //print all the elements
  for(int i=0; i<arr.size(); i++)
  {
    cout << arr[i] << endl;
  }
  
  
  //Size of vector
  cout << arr.size() << endl;
  
  //Capacity of vactor
  cout << arr.capacity() << endl;
  
  return 0;
}
