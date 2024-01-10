class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int prev = -1;
                bool incr = true;
                // check whether the remaining array is strictly increasing or
                // not.
                for (int k = 0; k < nums.size(); ++k) {
                    // check for every element except elements of irremovable
                    // subarray.
                    if (k >= i && k <= j)
                        continue;

                    // is the curr ele is not greater than prev
                    if (nums[k] <= prev) {
                        incr = false;
                        break;
                    } else {
                        prev = nums[k];
                    }
                }
                if (incr == true)
                    ans++;
            }
        }

        return ans;
    }
};