class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0] == b[0] )
        {
            return a[1] > b[1];
        }

        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        int ans=0;
        vector<int> dp;
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        //ek final vector lenge or usme elements dalte rhneg lis ki trah.
        //sirf height pe focus krenge hme max length of increasing height chahiye kuki width ke acc already hi sort hai.
        
        for(int i=0;i<n;++i)
        {
         

           int newheight=envelopes[i][1];
           //iski sahi position in ans vector
           int index=lower_bound(dp.begin(),dp.end(),newheight) - dp.begin();

           if(index >= dp.size() )  dp.push_back(newheight);
           else{
               dp[index]=newheight;
           }

        }

        return dp.size();
    }
};