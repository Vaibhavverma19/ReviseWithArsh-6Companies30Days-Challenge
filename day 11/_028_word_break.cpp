class Solution {
public:
    int solve(string& s,unordered_set<string>& dict,int index,vector<int>& dp)
    {
         if(index>=s.length()) return 1;
         if(dp[index]!=-1) return dp[index];
         for(int i=1;i<=s.length();++i)
         {
             string str=s.substr(index,i);
            //  cout<<str<<endl;
             if(dict.find(str)!=dict.end())
             {
                 int ans=solve(s,dict,index+i,dp);
                 if(ans==1) return dp[index]= 1;
             }
         }

         return dp[index]=0;
    }

    int solvetab(string& s,unordered_set<string>& dict)
    {
        vector<int> dp(s.length()+1,0);
        dp[s.length()]=1;
        for(int index=s.length()-1;index>=0;--index)
        {
             for(int i=1;i<=s.length();++i)
            {
                string str=s.substr(index,i);
                //  cout<<str<<endl;
                if(dict.find(str)!=dict.end())
                {   if(index + i <= s.length())
                    {
                        dp[index]=dp[index+i];
                        if(dp[index]==1) {
                         
                         break;
                        }

                    }
                }
            }

             
        }

        return dp[0];

    }

    bool wordBreak(string s, vector<string>& wordDict) {      unordered_set<string> dict;
    vector<int> dp(s.length()+1,-1);
       for(auto& word:wordDict) dict.insert(word);
        // int ans=solve(s,dict,0,dp);
        int ans=solvetab(s,dict);

        if(ans==1) return true;
        else return false;
    }
};