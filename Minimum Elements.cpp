// solve minimum coin is required to make given amount using recursion and memoixation method and tabulation method 

#include <bits/stdc++.h> 

// its is giving time limit exceeded 
int solveRec(vector<int> &num, int x){
    //base case
    if(x==0)
    return 0;
    if(x<0)
    return INT_MAX;

    int mini = INT_MAX;

for(int i=0; i<num.size();i++){
    int ans =solveRec(num, x-num[i]);
    if(ans!= INT_MAX)
    mini = min(mini,1+ans);
}
return mini;
}
// this code is using memoization and recursion no error
int solveRecmem(vector<int> &num, int x,vector<int> &dp){
    //base case
    if(x==0)
    return 0;
    if(x<0)
    return INT_MAX;
 if (dp[x] != -1)
 return dp[x];
    int mini = INT_MAX;

for(int i=0; i<num.size();i++){
    int ans =solveRecmem(num, x-num[i],dp);
    if(ans!= INT_MAX)
    mini = min(mini,1+ans);
}
dp[x] = mini;
return mini;
}
//solve using tabulation 
int solvetab(vector<int> &num, int x){
   vector<int> dp(x+1,INT_MAX);
 dp[0] =0;
 for(int i =1; i<=x;i++){
    //  we are trying to solve for every amount of figure 1 to x
for(int j=0;j<num.size();j++){
    if(i-num[j]>=0 && dp[i-num[j]] != INT_MAX){
    dp[i] =min(dp[i],1+dp[i-num[j]]);
    }
}

 }
 if(dp[x]==INT_MAX)
 return -1;
 return dp[x];

}


// int solveRecmem(vector<int> &num, int x,vector<int> &dp){
//     //base case
//     if(x==0)
//     return 0;
//     if(x<0)
//     return INT_MAX;
//  if (dp[x] != -1)
//  return dp[x];
//     int mini = INT_MAX;

// for(int i=0; i<num.size();i++){
//     int ans =solveRecmem(num, x-num[i],dp);
//     if(ans!= INT_MAX)
//     mini = min(mini,1+ans);
// }
// dp[x] = mini;
// return mini;
// }




int minimumElements(vector<int> &num, int x)
{
//     // int ans =solveRec(num,x);
//     // if(ans==INT_MAX)
//     // return -1;

  //function call 
// vector<int> dp(x+1,-1);
// int ans =solveRecmem(num,x,dp);
// if(ans==INT_MAX)
// return -1;
// else
// return ans;

return solvetab(num,x);

}
