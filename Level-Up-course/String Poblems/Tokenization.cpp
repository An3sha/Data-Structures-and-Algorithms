/* Tokenization denotes splitting a string with respect to some delimiter

input: "today is a sunny day"
output: "today", "is", "a", "sunny", "day"

String tokenization in C++ :
  1. using stringstream class
  2. using strtok function
  
  
              STRINGSTREAM
              ____________
*/


#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
  string input;
  getline(cin,input);     //when we have to take input inside a stringn we use getline function
  
  //create a string stream object
  stringstream ss(input);   //initializing ss object with same as input string
  
  // >> and << operators which helps us to read and write data
  string token;
  vector<string> tokens;
  while(getline(ss,token,' '))        //we are reading here and put inside tokens
  {
    tokens.push_back(token);
  }
  
  //print all tokens
  for(auto token:tokens)
  {
    cout<<token<<",";
  }
  
  return 0;
}

//                                  STRTOK                              it works on character arrays
                                    ______
             
                                      
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
  
  char input[10000];
  cin.getline(input,10000);
  
  //strtok()
  cout<<strtok(input," ");      //it gives one word only and if we cout the same thing again and again then it will only give the first word so we use null
  cout<<strtok(NULL," ")<<endl; //internally maintains the state of the string you passed in the last fn call, static variable
  cout<<strtok(NULL," ")<<endl;
  cout<<strtok(NULL," ")<<endl;
  cout<<strtok(NULL," ")<<endl;
  
  
  
  return 0;
}

                                     







