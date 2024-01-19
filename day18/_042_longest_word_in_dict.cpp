class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        pair<string,int> ans;
        ans={"",0};
        // sort(dictionary.begin(),dictionary.end());
        for(auto& word:dictionary)
        {
            int i=0,j=0;
            while(j<word.length())
            {
                if( i >= s.length())
                {
                    break;
                }

                if(word[j] == s[i])
                {
                  i++;
                  j++;

                }else{
                    i++;
                }
            }

            //checking ki word mila ki ni 
            if(j==word.length())
            {  //agar mil gaya to vo kya answer ki length se bada hai ki ni?
                if(ans.second < word.length() || (ans.second == word.length() && ans.first > word))
                {
                    ans={word,word.length()};
                }
            }
        }

        return ans.first;
    }
};