class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int x[]={-1,-1,-1,0,1,1,1,0};
        int y[]={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                 ans[i][j]=img[i][j];
                 int cnt=1;
                for(int k=0;k<8;++k)
                {
                    if(i+x[k] >=0 && i+x[k]<n && j+y[k]>=0 && j+y[k] < m)
                    {  cnt++;
                        ans[i][j]+=img[i+x[k]][j+y[k]];
                    }
                }

                ans[i][j]/=cnt;
            }
        }

        return ans;
    }
};