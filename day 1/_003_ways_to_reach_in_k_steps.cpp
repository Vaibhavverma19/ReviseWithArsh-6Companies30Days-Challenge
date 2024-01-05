class Solution {
public:
    int solve(int s,int e,int k,int& ans,vector<vector<int>>& dp,int& n)
    {
        if(k==0 && s==e)
        {
          
            
            return 1;
        }
        if(k<0) return 0;

        if(dp[s+n][k]!=-1) 
        {
        
          return dp[s+n][k];
        }

        //left
        long long a=solve(s-1,e,k-1,ans,dp,n);

        //right
        a+=solve(s+1,e,k-1,ans,dp,n);

        return dp[s+n][k]=a%1000000007;

    }
    int numberOfWays(int startPos, int endPos, int k) {
        int ans=0;
         vector<vector<int>> dp(4001,vector<int>(1001,-1));
        return solve(startPos,endPos,k,ans,dp,k);
        
    }
};