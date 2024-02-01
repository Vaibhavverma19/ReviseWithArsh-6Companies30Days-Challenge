class Solution {
public:
int solve(string& s,int index,unordered_map<string,int>& freq)
{
    if(index == s.length()) return 0;

    string left="";
    int ans=INT_MAX;
    for(int curr=index;curr<s.length();++curr)
    {
        left.push_back(s[curr]);
         int leftextra=0;
        if(freq[left]==0)
        {
            leftextra+=left.length();
        }

        int remainingExtra=solve(s,curr+1,freq);

        ans=min(ans,leftextra + remainingExtra);
    }

    return ans;
}
int solvememo(string& s,int index,unordered_map<string,int>& freq,vector<int>& dp)
{
    if(index == s.length()) return 0;
    if(dp[index]!=-1) return dp[index];
    string left="";
    int ans=INT_MAX;
    for(int curr=index;curr<s.length();++curr)
    {
        left.push_back(s[curr]);
         int leftextra=0;
        if(freq[left]==0)
        {
            leftextra+=left.length();
        }

        int remainingExtra=solvememo(s,curr+1,freq,dp);

        ans=min(ans,leftextra + remainingExtra);
    }

    return dp[index]=ans;
}

int solvetab(string& s,unordered_map<string,int>& freq)
{
    vector<int> dp(s.length()+1,0); //dp[i] represents the ans of string starting from index and ends at s.length()

    for(int index=s.length()-1;index>=0;--index)
    {
        string left="";
        int ans=s.length();
        for(int curr=index;curr<s.length();++curr)
        {
            left.push_back(s[curr]);
            int leftextra=0;
            if(freq[left]==0)
            {
                leftextra+=left.length();
            }

            

            ans=min(ans,leftextra + dp[curr+1]);
        }

       dp[index]=ans;
    }

    return dp[0];
}
    int minExtraChar(string s, vector<string>& dictionary) {
       //for checking that whether word lie in the dict or not
       unordered_map<string,int> freq;
       for(auto word:dictionary)
       {
           freq[word]++;
       }
        // vector<int> dp(s.length(),-1);
        // return solvememo(s,0,freq,dp);
        return solvetab(s,freq);
    }
};