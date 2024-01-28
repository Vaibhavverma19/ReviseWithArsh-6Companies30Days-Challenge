class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums)
        {
            pq.push(i);
        }

        while(k--)
        {
            int top=pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }

        long long ans=1;
        while(!pq.empty())
        {
            ans=ans*pq.top();
            ans%=1000000007;
            pq.pop();
        }

        return ans;
    }
};