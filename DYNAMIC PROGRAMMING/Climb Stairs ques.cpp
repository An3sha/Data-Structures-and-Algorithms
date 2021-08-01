/* Climb Stairs

 You are given a number n, representing the number of stairs in a staircase.
 You are on the 0th step and are required to climb to the top.
 In one move, you are allowed to climb 1, 2 or 3 stairs.
 You are required to print the number of different paths via which you can climb to the top.
input = 4
output = 7 */

#include <iostream>
using namespace std;

int cs(int n){
    // write your code here
    int dp[100];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    for(int i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}



/* Climb Stairs With Variable Jumps

You are given a number n, representing the number of stairs in a staircase.
You are on the 0th step and are required to climb to the top.
You are given n numbers, where ith element's value represents - till how far from the step you could jump to in a single move.  
You can of course jump fewer number of steps in the move.
You are required to print the number of different paths via which you can climb to the top.
*/

#include <iostream>
using namespace std;

int cs(int arr[], int n){
    // write your code here
    int dp[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i] = 0;
    }
    dp[n]=1;
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=arr[i]; j++)
        {
            if(i+j <= n)
            {
                dp[i] += dp[i+j];
            }
            
        }
    }

    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}

/* Climb Stairs With Minimum Moves */

import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int[] arr = new int[n];
      for (int i = 0; i < arr.length; i++) {
         arr[i] = Integer.parseInt(br.readLine());
      }

      Integer[] dp = new Integer[n + 1];
      dp[n] = 0;

      for (int i = n - 1; i >= 0; i--) {
         if (arr[i] > 0) {
            int min = Integer.MAX_VALUE;

            for (int j = 1; j <= arr[i] && i + j < dp.length; j++) {
               if(dp[i + j] != null){
                  min = Math.min(min, dp[i + j]);
               }
            }

            if(min != Integer.MAX_VALUE){
               dp[i] = min + 1;
            }
         }
      }

      System.out.println(dp[0]);
   }

}
