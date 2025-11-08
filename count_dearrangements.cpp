// count dearrangements using recursion +memoization and tabulation and space optimization 

#include<bits/stdc++.h>
#define MOD 1000000007   // 1e9+7
long long int solveMem(int n,vector<long long int> &dp){
    //base case
    if(n==1)
    return 0;
    if(n==2)
    return 1;             // tc = O(n)

    if(dp[n]!=-1)         //sc =O(n)+O(n);
    return dp[n];
    dp[n] = (((n-1)%MOD) * (solveMem(n-1,dp)%MOD + (solveMem(n-2,dp))%MOD)) % MOD;

    return dp[n];
}
long long int solvetab(int n){
vector<long long int> dp(n+1,0);
dp[1]=0;
dp[2]=1;
for(int i=3;i<=n;i++){
    long long int first =dp[i-1]%MOD;
    long long int second =dp[i-2]%MOD;
    long long int sum = (first+second)%MOD;  //tc =  o(n)

    long long int ans =((i-1)*sum)%MOD;       //sc = O(n)
    dp[i] = ans;

}
return dp[n];
}
long long int solveso(int n){

long long int prev2=0;
long long int prev1=1;
for(int i=3;i<=n;i++){
    long long int first =prev1%MOD; //tc =O(n)
    long long int second =prev2%MOD; //sc =(1)
    long long int sum = (first+second)%MOD;
    long long int ans =((i-1)*sum)%MOD;
  prev2 =prev1;
  prev1 =ans;

}
return prev1;
}
long long int countDerangements(int n) {
// vector<long long int> dp(n+1,-1);
// return solveMem(n,dp);
// return solvetab(n);
return solveso(n);
}
