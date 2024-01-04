class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> ans(isWater.size(),vector<int>(isWater[0].size(),-1));
        queue<pair<int,int>> q;
        vector<vector<int>> vis(isWater.size(),vector<int>(isWater[0].size(),0));
        for(int i=0;i<isWater.size();i++)
        {
            for(int j=0;j<isWater[0].size();++j)
            {
                if(isWater[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=1;
                }
                
            }
        }

        //now exctract front element till q is not empty.
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;
            int val=ans[i][j];
            

            //up
            if(i-1>=0 && vis[i-1][j]!=1 && ans[i-1][j]!=0)
            {   vis[i-1][j]=1;
                ans[i-1][j]=val+1;
                q.push({i-1,j});

            }
            //down
            if(i+1<isWater.size() && vis[i+1][j]!=1 && ans[i+1][j]!=0)
            {   vis[i+1][j]=1;
                ans[i+1][j]=val+1;
                 q.push({i+1,j});
            }
            //left
            if(j-1>=0 && vis[i][j-1]!=1 && ans[i][j-1]!=0)
            {   vis[i][j-1]=1;
                ans[i][j-1]=val+1;
                q.push({i,j-1});    
            }

            //right
            if(j+1<isWater[0].size() && vis[i][j+1]!=1 && ans[i][j+1]!=0)
            {   vis[i][j+1]=1;
                ans[i][j+1]=val+1;
                q.push({i,j+1});

            }         
        }

        return ans;
    }
};