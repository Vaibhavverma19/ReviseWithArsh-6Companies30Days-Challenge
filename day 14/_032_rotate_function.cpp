class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       long long sum=0,fn=0;
       for(int i=0;i<nums.size();++i)
       {
           sum+=nums[i];
           fn+=i*nums[i];

       } 

       long long ans=fn;
       for(int i=1;i<nums.size();++i)
       {
           fn = fn + sum - nums.size()*nums[nums.size()-i];
           ans=max(ans,fn);
       }

       return (int)ans;
    }
};