class Solution {
public:
   int ans=0;
    int solve(vector<int>& n,vector<int>& m,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=n.size() || j>=m.size())
        return 0;
         if(dp[i][j]!=-1) return dp[i][j];
        //two cases.
        int temp_ans=0;
        //1 both the elements are same
        if(n[i]==m[j])
        {
            temp_ans= 1 + solve(n,m,i+1,j+1,dp);
        }else{
           temp_ans=0;
         
        }
        
        solve(n,m,i+1,j,dp); 
        solve(n,m,i,j+1,dp);

        ans=max(ans,temp_ans);

        return dp[i][j]=temp_ans;
    }
   
    int findLength(vector<int>& nums1, vector<int>& nums2) {
         vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
         solve(nums1,nums2,0,0,dp);
         return ans;
    }
};