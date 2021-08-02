/* return true if it's a valid parenthesis */

#include <iostream>
#include <stack>

using namespace std;

bool check_parenthesis(string str) 			 //Boolean Function to check the given expression 
{
	stack <int> s;

	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{' )
		{
			s.push(str[i]);    					//Push the element into stack
		}

		else
		{
			switch(str[i])
			{
				case ')':
				 if(s.empty() || s.top()!='(')
				 {
				 	return false;
				 }
				 s.pop();
				 break;

				case ']':
				  if(s.empty() || s.top()!='[')
				  {
				  	return false;
				  }
				  s.pop();
				  break;

				case '}':
				 if(s.empty() || s.top()!='}')
				 {
				 	return false;
				 }
				 s.pop();
				 break;
			}
		}
	}

	return s.empty();

}

int main()
{

	string exp;
	cin>>exp;

	if (check_parenthesis(exp))   			 //Calling the function
      cout << "true";
   else
      cout << "false";
}


   // Input : [(a+b)]
   // Output:  True

   // Input : [)]
   // Output:  False
 
 	// Time Complexity : O(n)
 	// Space Complexity : O(n)
	
/* Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "". */

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> asterisk;
        stack<int> validPar;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') validPar.push(i);
            if(s[i] == '*') asterisk.push(i);
            if(s[i] == ')'){
                if(!validPar.empty()) 
                    validPar.pop();
                else if(!asterisk.empty()) 
                    asterisk.pop();
                else 
                    return false;
            }
        }
        
        while(!validPar.empty() && !asterisk.empty()){
            if(validPar.top() > asterisk.top()) return false;
            
            validPar.pop(); asterisk.pop();
        }
        
        return validPar.empty();
    }
};
