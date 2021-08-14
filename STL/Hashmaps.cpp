#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main()
{
  unordered_map<string, int> m;                 // we can also write as map<string, int> m and use headerfile <map> above
  
  //INSERT
  m["Mango"] = 100;
  
  //Second Insert
  m.insert(make_pair("Apple", 120));
  
  //SEARCH
  if(m.count("Apple")==1)
  {
    cout<<"Price of Apple is "<<m["Apple"]<<endl;
  }
  if(m.count("Guava")==0)
  {
    cout<<"Guava does not exist"<<endl;
  }
  
  //We can also use Iterators for Searching
  auto f = m.find("Mango");
  if(f!=m.end())
  {
    cout<<"Price of mango is "<<(f->second)<<endl;       // cannot use *f because it contains pairs
  }
  else
  {
    cout<<"Mango does not exist"<<endl;
  }
  
  //DELETION
  m.erase("Mango");
}



//insert, count, erase, []










