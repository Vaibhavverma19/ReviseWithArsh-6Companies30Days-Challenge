class Solution {
public:
    // void solve(vector<int>& nums,unordered_map<int,bool>& vis,int& ans,int prev,int& size)
    // {   if(size == nums.size()) 
    //     {
    //       ans++ ;
    //        return;
    //     }
    //     for(int i=0;i<nums.size();++i)
    //     {
    //         if(vis[nums[i]]!=true)
    //         {
    //            if(prev == -1 || (nums[i] % prev==0 || prev % nums[i]==0))
    //            {
    //                vis[nums[i]]=true;
    //                size++;
    //                solve(nums,vis,ans,nums[i],size);
    //                vis[nums[i]]=false;
    //                size--;
    //            }
    //         }
    //     }
    // }
//******************** dp + bitmask solution********************
   int solve(vector<int>& nums,int previndex,int currindex,int mask,vector<vector<int>>& dp)
   {
       if(currindex == nums.size())
       {   
           return 1;
       }
       if(dp[previndex+1][mask]!=-1) return dp[previndex + 1][mask]; //prev index isiliye kuki operations usi ke hisab se ho rhe hai na currindex to bas konsa idex fill krna hai uske liye hai
       int total=0;
       for(int i=0;i<nums.size();++i)
       {
          if(mask & (1<<i))
          {
              continue;
          }

          if(previndex == -1 || (nums[i] % nums[previndex]==0 || nums[previndex] % nums[i]==0) )
          {  
              total += solve(nums,i,currindex+1, mask | (1<<i), dp);
              total=total%1000000007;
          }
       }

       return dp[previndex+1][mask]=total%1000000007;
   }

    int specialPerm(vector<int>& nums) {
    //    unordered_map<int,bool> vis;
    //    int ans=0;
    //    int size=0;                 // d- use krni pdegi kuki tle aa gya hai..  and vsi vale me dp lagane ke liye hm logo ko masking use krni pdti hai so lets go to that.
    //    solve(nums,vis,ans,-1,size);
    //    return ans; 

    vector<vector<int>> dp(16,vector<int>( 1<<14 , -1));
    return solve(nums,-1,0,0,dp);  //nums, prev , currindex(kis index ke liye value fill kr rhe ho), mask(jaha jaha setbit 1 hogi vo no. already choose kr liye hai)
    }
};