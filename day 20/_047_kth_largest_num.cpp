class KthLargest {
public:
   priority_queue<int,vector<int>,greater<int> > minheap;
   int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto& n:nums)
        {
            minheap.push(n);
            if(minheap.size()>k) minheap.pop();    //kuki hme kth largest batana hai.
            //to ham min heap me alrgest k sabse bade elem store karenge.

        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k) minheap.pop();

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */