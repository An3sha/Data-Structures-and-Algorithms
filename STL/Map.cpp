/*.  map <T1, T2> obj;        where T1 is key and T2 is value */

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
  map<string, int> mpp;
  
  //insert
  mpp["Mango"] = 100;

  mpp.insert(make_pair("Apple", 120));
 
  pair<string, int> p("Orange", 50);
  mpp.insert(p);
  
  //loop through map
  for(auto &el1: mpp)
  {
    cout<<el1.first<<" "<<el1.second<<endl;
  }
  
  //access
  cout<<mpp["Apple"]<<endl;           //120
  
  cout<<mpp.at("Apple")<<endl;        //120
  
  //search
  if(mpp.count("Mango")==1)
  {
    cout<<"Apple is present"<<endl;
    cout<<"Price of Apple is"<<mpp["Apple"]<<endl;
  }
  if(mpp.count("Guava")==0)
  {
    cout<<"Guava is not present"<<endl;
  }
  
  //iterators to search
  auto f = mpp.find("Mango");
  if(f!=mpp.end())
  {
    cout<<"Price of Mango is"<<(f -> second)<<endl;       //can't write (*f) because f is in pair
  }
  else
  {
    cout<<"Doesn't exist<<endl;
  }
  
  //deletion
  mpp.erase("Mango");
  
}
  
  
  




















