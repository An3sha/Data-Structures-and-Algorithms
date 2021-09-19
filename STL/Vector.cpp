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
  for(int i : arr)
  {
    cout << i <<",";
  }
  
//   for(int i=0; i<arr.size(); i++)
//   {
//     cout << arr[i] << endl;
//   }
  
  //Size of vector
  cout << arr.size() << endl;
  
  //Capacity of vactor
  cout << arr.capacity() << endl;
  
  
  
  // 2D Vector
  vector<vector<int>> arr = { {1,2,3},
                              {4,5,6},
                              {7,8,9,10},
                              {11,12}};
  arr[0][0] += 10;    //update
  
  for(int i=0; i<arr.size(); i++)
  {
    for(int number : arr[i])
    {
      cout << number << ",";
    }
    cout << endl;
  }
  
  return 0;
}
