void solve(int k,int target,vector<vector<int>>& ans,vector<int>& temp,int index)
{
    if(k==0 && target==0)
    {
        ans.push_back(temp);
        return;
    }
    if(target<=0)
    {
        return;
    }
    if(k<=0)
    {
        return;
    }

    //check every next integer after index
    for(int i=index;i<=9;++i)
    {
        
        temp.push_back(i);
        
        solve(k-1,target-i,ans,temp,i+1);
        
        temp.pop_back();
        
    }
}
vector<vector<int>> combinationSum(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    
    solve(k,n,ans,temp,1);
    return ans;
}