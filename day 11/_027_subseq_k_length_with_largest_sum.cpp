class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxheap;

        for(int i=0;i<nums.size();++i)
        {
            maxheap.push({nums[i],i});
        }

        vector<int> indexes;
        while(k--)
        {
            auto temp=maxheap.top();
            maxheap.pop();
            indexes.push_back(temp.second);
        }

        sort(indexes.begin(),indexes.end());
         vector<int> ans;
        for(int i=0;i<indexes.size();++i)
        {
            ans.push_back(nums[indexes[i]]);
        }

        return ans;
    }
};