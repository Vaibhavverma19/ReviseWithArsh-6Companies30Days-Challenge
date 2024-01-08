class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //sum(k)= sum(n) - sum(n-k)...... here sum(n) is sum equal to n
        unordered_map<int,int> freq_of_sum;
        freq_of_sum[0]=1;
        int sum=0;
        int answer=0;
        for(auto& num:nums)
        {
            if(num &1)
            {
                sum+=1;
            }else{
                sum+=0;
            }
           //jitni bar piche n-k sum mil chuka hoga utni subarrays ban jayengi is point pr.
            answer += freq_of_sum[sum - k];
            freq_of_sum[sum]++;
        }

        return answer;
    }
};