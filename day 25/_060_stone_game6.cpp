class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int> >  pq;
        for(int i=0;i<aliceValues.size();++i)
        {
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int alice=0;
        int bob=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int index=it.second;
            
            alice+=aliceValues[index];
            if(!pq.empty())
            {
                auto it2=pq.top();
                pq.pop();
              
                bob+=bobValues[it2.second];
            }

        }

        if(alice>=bob){
           if(alice==bob) return 0;
           return 1;
        } 

        return -1;
    }
};