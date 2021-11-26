/* Given a string, write a function to replace all spaces in a string with %20. It is given that the string has sufficient space at the end to hold the additional characters.


Sample Input : hello world,  how are you?
Sample output : hello%20world,%20%20how%20are%20you?


count the spaces first

*/



#include <iostream>
#include <cstring>
using namespace std;

void replace_space(char *str)
{
  // 1. Calc spaces
  int spaces = 0;
  for(int i=0; str[i]!='\0'; i++)
  {
    if(str[i]==' ')
    {
      spaces += 1;
    }
  }
  int index = strlen(str) + 2*spaces;
  str[index] = '\0';            //string is null terminated
  
  for(int i=strlen(str)-1; i>=0; i--)
  {
    if(str[i]==' ')
    {
      str[index-1] = '0';
      str[index-2] = '2';
      str[index-3] = '%';
      index = index-3;
    }
    else
    {
      str[index-1] = str[i];
      index--;
    }
  }
}


int main()
{
  char input[10000];
  cin.getline(input,10000);   //we use cin because it also includes spaces
  replace_space(input);
  cout<<input<<endl;
  
  return 0;
}
