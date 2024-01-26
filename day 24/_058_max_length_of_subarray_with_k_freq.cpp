class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i=0,j=0;
        int ans=0,length=0;
        while(j<nums.size())
        {
            freq[nums[j]]++;
            if(freq[nums[j]] > k)
            {
                while(i<j && nums[i]!=nums[j])
                {
                    freq[nums[i]]--;
                    i++;
                }
                i++;
                freq[nums[j]]--;
            }

            length=j-i+1;
            ans=max(ans,length);
            j++;
        }
       return ans;
    }
};