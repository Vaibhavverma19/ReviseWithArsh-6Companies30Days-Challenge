class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=arr1.size();
        for(auto& i:arr1)
        {
           auto it=lower_bound(arr2.begin(),arr2.end(),i+d);
           auto it2=lower_bound(arr2.begin(),arr2.end(),i-d);
           if(it!=it2 || *it==i+d || *it==i-d) ans--;
        //    if(it==arr2.end()){
        //        it=arr2.end()-1;
        //    }
        //    while(it >= arr2.begin())
        //    {
        //        if(abs(*it - i)<=d)
        //        {
        //            ans--;
        //            break;
        //        }
        //        it--;
        //    }
           
        }
        return ans;
    }
};