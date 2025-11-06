// house robber question in coding ninjas

#include <bits/stdc++.h>
using namespace std;

long long solve(const vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) return 0;

    long long prev2 = 0;
    long long prev1 = nums[0];

    for (int i = 1; i < n; ++i) {
        long long incl = prev2 + nums[i]; // use long long
        long long excl = prev1;
        long long ans  = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long houseRobber(vector<int>& valueInHouse) {
    int n = (int)valueInHouse.size();
    if (n == 0) return 0;
    if (n == 1) return valueInHouse[0];

    // case 1: [0 .. n-2], case 2: [1 .. n-1]
    vector<int> first(valueInHouse.begin(),  valueInHouse.end() - 1);
    vector<int> second(valueInHouse.begin()+1, valueInHouse.end());

    return max(solve(first), solve(second));
}
