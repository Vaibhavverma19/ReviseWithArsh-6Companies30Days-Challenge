class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n=nums.size();
        for(auto& q:queries)
        {
            vector<pair<string,int>> temp;
            for(int i=0;i<n;++i)
            {
                string name=nums[i].substr(nums[i].size()-q[1],nums[i].size());
              temp.push_back({name,i});
            }

            sort(temp.begin(),temp.end());
            ans.push_back(temp[q[0]-1].second);
        }

        return ans;
    }
};