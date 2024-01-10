class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp(nums.size());
        int j=nums.size()-1;
        int i=1;
        while(i<nums.size())
        {
            temp[i]=nums[j];
            j--;
            i+=2;
        }
        i=0;
        while(i<nums.size())
        {
            temp[i]=nums[j];
            j--;
            i+=2;
        }

        nums=temp;
        
    }
};