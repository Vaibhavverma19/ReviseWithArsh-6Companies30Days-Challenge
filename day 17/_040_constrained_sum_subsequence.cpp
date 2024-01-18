class Solution {
public:
    int solve(vector<int>& nums,int k,int prev,int index)
    {   
        if(index >= nums.size() )
        {
            return 0;
        }
        
       
        int inc=0;
        if(prev == -1 || index - prev <=k)
        {
            inc= nums[index] + solve(nums,k,index,index+1);
        }
            int excl=solve(nums,k,prev,index+1);

            

        return max(inc,excl);
        

        
    }
    int solvememo(vector<int>& nums,int k,int prev,int index,unordered_map<string,int>& map)
    {   
        if(index >= nums.size() )
        {
            return 0;
        }

        string key=to_string(index) + "-" + to_string(prev);
        if(map.count(key)){
            return map[key];
        }

        int inc=0;
        if(prev == -1 || index - prev <=k)
        {
            inc= nums[index] + solvememo(nums,k,index,index+1,map);
        }
            int excl=solvememo(nums,k,prev,index+1,map);

            

            return map[key]=max(inc,excl);
        

        
    }

    //************tabulation**************

    int solvetab(vector<int>& nums,int k)
    {
        vector<int> dp(nums.size(),0); //dp[i] represents max sum of subseq ends at i.
        for(int i=0;i<nums.size();++i)
        {
            dp[i]=nums[i];
        }
        int res=INT_MIN;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i-1;j>=0 && i-j<=k;--j)
            {
                dp[i]=max(dp[i],nums[i]+dp[j]);
            }
             res=max(res,dp[i]);
        }

        return res;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // int result= solve(nums,k,-1,0);
        // unordered_map<string,int> map;
        // int result=solvememo(nums,k,-1,0,map);
        int result=solvetab(nums,k);
        if(result == 0) //means empty sub seq.
        {
            return *max_element(nums.begin(),nums.end());
        }

        return result;
    }
};