class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {

    auto cmp=[](const pair<string,int>& a,const pair<string,int>& b)     {  if(a.second==b.second)
          {
              return a.first > b.first;
          }
          return a.second < b.second;
       };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> maxheap;
        
        unordered_map<string,int> freq;
        for(int i=0;i<words.size();++i)
        {
             string word=words[i];
             freq[word]++;
        }

        for(auto it:freq)
        {
            maxheap.push({it.first,it.second});
        }

        vector<string> ans;
        while(k--)
        {
            auto top=maxheap.top();
            maxheap.pop();
            cout<<top.first<<","<<top.second<<endl;
            ans.push_back(top.first);
        }

        

        // sort(ans.begin(),ans.end());
        return ans;

    }
};