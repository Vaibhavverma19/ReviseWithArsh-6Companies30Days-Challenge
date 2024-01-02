class Solution {
public:
    vector<string> solve(vector<string> prevans,string temp)
    {
        vector<string> finalans;

        if(prevans.size()==0)
        {   string str;
            for(int i=0;i<temp.size();++i)
            {
                str=temp[i];
                finalans.push_back(str);
            }

            
        }else{

            for(int i=0;i<prevans.size();++i)
            {
                for(int j=0;j<temp.size();++j)
                {
                    prevans[i].push_back(temp[j]);
                    finalans.push_back(prevans[i]);
                    prevans[i].pop_back();
                }
            }
        }

        return finalans;
    } 
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> str={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        for(int i=0;i<digits.size();++i)
        {
            int index=digits[i]-'0';
            string temp=str[index-2];
            ans=solve(ans,temp);
        }

        return ans;
    }
};