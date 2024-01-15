class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans=0;
       for(int i=0;i<nums.size();++i)
       {   if(i!=0 && nums[i]==nums[i-1])continue;
           int start=i+1;
           int end=nums.size()-1;
           while(start<=end)
           {
               int mid=start + (end- start)/2;
               
               if(nums[mid]-nums[i]<k)
               {
                   start=mid+1;
               }else{
                   if(nums[mid] - nums[i]==k  )
                   {  cout<<"mid is "<<nums[mid]<<"i is "<<nums[i]<<endl;
                       ans++;
                       break;
                   }

                   end=mid-1;
               }
           }
       } 
       return ans;
    }
};