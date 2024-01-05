//*******************************************
//********************************************************
//*****************************************
//**********not the optimal soln so learn concepts of bs and trie and again try it.
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        vector<int> arr(nums.size());
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]%p==0)
            arr[i]=1;
            else{
                arr[i]=0;
            }
        }

        set<vector<int>> diff_subarrays;
        for(int i=0;i<nums.size();++i)
        {
            vector<int> subArr;
            int cnt=k;
            for(int j=i;j>=0;--j)
            {  if(arr[j]==1) cnt--;
               if(cnt>=0)
               {
                   subArr.push_back(nums[j]);
               }
              

               diff_subarrays.insert(subArr);
            }
        }

        return diff_subarrays.size();
    }
};