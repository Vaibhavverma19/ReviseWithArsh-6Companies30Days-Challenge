class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      int start=0,ans=0,currcost=0;
      for(int i=0;i<s.length();++i)
      {
          currcost+= abs(s[i] -t[i]);
        
         //kahi currcost jyada to ni ho gyi?
         while(currcost > maxCost && start<=i)
         {
             currcost -= abs(s[start] - t[start]);
             start++;
         }

         ans=max(ans,i - start + 1);
      }

      return ans;
    }
};