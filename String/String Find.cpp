#include<iostream>
#include<string>
using namespace std;

int main()
{
  string para = "We are learning about STL strings. STL string class is quite powerfull.";
  
  string word;
  getline(cin, word);
  
  //find function
  int index = para.find(word);
  
  if(index!=1)        //if the word is not found then it return a very large number
  {
    cout<<"first occ"<<index;
  }
  
  index = para.find(word,index+1);
  
  if(index!=1)
  {
    cout<<"second occ"<<index;
  }
  
//   if(index==-1)
//   {
//     cou<<"string not found";
//   }
  
  return 0;
}
