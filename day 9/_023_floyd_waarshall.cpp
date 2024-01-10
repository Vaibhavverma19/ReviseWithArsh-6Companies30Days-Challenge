#include<limits.h>
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n,vector<int>(n,10001));

        for(int i=0;i<edges.size();++i)
        {   
            int src=edges[i][0];
            int dest=edges[i][1];
            int cost=edges[i][2];
            adjMatrix[src][dest]=cost;
            adjMatrix[dest][src]=cost;
        }
          for(int s=0;s<n;++s)
        {
            adjMatrix[s][s]=0;
        }

        //adjmatrix created.
        //now move via everynode from every src to des
        unordered_map<int,int> freq;
        for(int via=0;via<n;++via)
        {
            for(int s=0;s<n;++s)
            {
                for(int d=0;d<n;++d)
                {  
                    adjMatrix[s][d]=min(adjMatrix[s][d],(adjMatrix[s][via] + adjMatrix[via][d]));
                }
            }
        }
        int mini=INT_MAX;
        int ans;
        for(int s=0;s<n;++s)
        {
            for(int d=0;d<n;++d)
            {  
                if(adjMatrix[s][d]<=distanceThreshold)
                {
                    freq[s]++;
                }
            }
  
                if(freq[s]<=mini){
                    mini=freq[s];
                    ans=s;
                }
        }

        return ans;


    }
};