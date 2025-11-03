//using tabulation method in dynamic programming 


class Solution {
public:
int solve3(vector<int>&cost, int n){
    //step1 creation of dp array
    vector<int> dp(n+1);
    //step2 base case analysis
    dp[0] =cost[0];
    dp[1] =cost[1];
    // step 3 
    for(int i=2; i<n;i++){
        dp[i] =cost[i] + min(dp[i-1],dp[i-2]);
    } 
    return min(dp[n-1],dp[n-2]);
}

    int minCostClimbingStairs(vector<int>& cost) {
        // // int n = cost.size();
        // // //it can be simplified
        // // int ans = min(solve(cost,n-1),solve(cost,n-2));
        // // return ans;
        // int n =cost.size();

        // vector<int> dp(n+1,-1);
        // int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        // return ans;

 int n =cost.size();
 return solve3(cost,n);
    }
    
};
