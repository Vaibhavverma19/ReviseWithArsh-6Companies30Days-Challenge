class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());

        int ans=0;
        for(int i=0;i<ages.size();++i)
        {
            auto start=upper_bound(ages.begin(),ages.end(),0.5*ages[i] + 7);
            auto end=upper_bound(ages.begin(),ages.end(),ages[i]);
            int total=distance(start,end) - 1;  //-1 because khudke sath vala bhi hatana hai.
             ans+=max(total,0); //in case start > end
        }

        return ans;
    }

};