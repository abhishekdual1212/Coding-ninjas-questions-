class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxi = nums[0];  // assume the first element is the largest

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxi) {   // compare each element
                maxi = nums[i];     // update if current element is bigger
            }
        }

        return maxi;  // final largest element
    }
};
