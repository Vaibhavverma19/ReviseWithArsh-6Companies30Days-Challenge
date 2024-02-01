class Solution {
public:
    string frequencySort(string s) {
       auto cmp=[](const pair<char,int>& a,const pair<char,int>& b)
       {
           return a.second < b.second;
       } ;

       priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq;

       unordered_map<char,int> f;
       for(int i=0;i<s.length();++i)
       {
           f[s[i]]++;
       }
       for(auto it:f)
       {
           pq.push({it.first,it.second});
       }

       string ans;
       while(!pq.empty())
       {
           auto top=pq.top();
           pq.pop();
           while(top.second--)
           {
               ans.push_back(top.first);
           }
       }

       return ans;
    }
};