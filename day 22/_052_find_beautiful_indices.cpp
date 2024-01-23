class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> matchA, matchB;
        for (int i = 0; (i + a.size()) <= s.size(); i++) {
            if (s.substr(i, a.size()) == a) matchA.push_back(i);
        }
        for (int i = 0; (i + b.size()) <= s.size(); i++) {
            if (s.substr(i, b.size()) == b) matchB.push_back(i);
        }

        vector<int> ans;
        for(auto i:matchA)
        {
           
            auto it=lower_bound(matchB.begin(),matchB.end(),i-k);
            if(it!=matchB.end())
            {
                if(abs(*it - i)<=k)
                {
                    ans.push_back(i);
                }
            }
            
        }

        return ans;
    }
};