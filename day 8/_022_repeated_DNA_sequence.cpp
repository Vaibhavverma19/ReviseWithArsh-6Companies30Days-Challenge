class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       if(s.length()<11) return {};
       unordered_map<string,int> frq;
       vector<string> ans;
       for(int i=0;i<=s.length()-10;++i)
       {
           string str=s.substr(i,10);
           
           frq[str]++;
       } 

       for(auto& f: frq)
       {
           if(f.second>1)
           {   
               ans.push_back(f.first);
           }
       }

       return ans;
    }
};