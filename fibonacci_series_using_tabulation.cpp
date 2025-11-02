// fibonacci series solving using tabulation method 
//without memoization
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin>> n;
     //step 1
     vector<int> dp[n+1];
     //step2
     dp[0] = 0;
     dp[1] = 1;

     //step3
     for(int i =2; i<=n;i++)
           dp[i] =dp[i-1]+ dp[i-2];
     cout<< dp[n] << endl;

      return 0;
}
