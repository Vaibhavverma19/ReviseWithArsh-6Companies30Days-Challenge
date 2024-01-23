class Solution {
public:
    int findmask(string word)
    {
        int number=0;
        for(auto& ch:word)
        {
            number |= 1<<(ch-'a');
        }

        return number;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        //use bitmask to store the masks of startwords and then on target word remove one char and check whether startword having same mask exist or not?
        // mask of startwords
        set<int> st;
        for(auto& word:startWords)
        {
            int mask=findmask(word);
            st.insert(mask); //why set? because baad me si mask ko search krna pdega to set me (logn) me search ho jayega na
        }

        //ab target word pe jao uska ek ek character ko remove krke mask check kro ki kya ban rha hai and then us mask ko find kro ki vo set me already hai ki ni. agr set me hai iska mtlb startword me hai.
        //but hmne ye normal string ke sath hi ku ni kia? seedha ek ek char hatadete fir check kr lete ki string match ho rhi h ki ni? kuki bitmask fast hota hai na.
        int ans=0;
        for(auto& target:targetWords)
        {
            int mask=findmask(target);
            //unset bit of ith char
            for(int i=0;i<target.length();++i)
            {
                int check=mask - (1<<(target[i]-'a'));
                if(st.find(check)!=st.end())
                {
                    ans++;
                    break;
                }

            }
        }

        return ans;
    }
};