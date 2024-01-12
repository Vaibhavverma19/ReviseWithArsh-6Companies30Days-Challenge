class Solution {
public:
    int solve(vector<int>& nums,vector<int>& previdx)
    {   int maxi=0;
        int largestindex=0;
        vector<int> dp(nums.size(),0);
        for(int i=0;i<nums.size();++i)
        {  previdx[i]=i;
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(1+dp[j] > dp[i])
                    {
                        previdx[i]=j;
                    }
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }

            if(dp[i] > maxi)
            {
                maxi=dp[i];
                largestindex=i;
            }
        }
       return largestindex;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> previdx(nums.size());
        int index=solve(nums,previdx);
        vector<int> ans;
        
        ans.push_back(nums[index]);
        while(previdx[index]!=index)
        {
            index=previdx[index];
           
            ans.push_back(nums[index]);
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};