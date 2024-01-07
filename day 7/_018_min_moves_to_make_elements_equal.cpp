class Solution {
public:
    int minMoves2(vector<int>& arr) {
        // vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mid;
        
        mid=n/2;
        int ans=0;
        for(int i=0;i<n;++i)
        {
           ans+=abs(arr[i] - arr[mid]);
        }

        return ans;

        
    }
};