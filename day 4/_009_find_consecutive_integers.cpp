class DataStream {
public:
   int val,k;
   int false_cnt=0;
   queue<pair<int,bool>> q;
    DataStream(int value, int k) {
        this->val=value;
        this->k=k;
    }
    
    bool consec(int num) {
        bool match;
        (num==val)?match=true:match=false;
        
        if(q.size()<k)
        {
            q.push({num,match});
            if(!match) false_cnt++;
            if(q.size()<k)
            return false;
        }else{
            auto temp=q.front();
            q.pop();
            if(temp.second==false) false_cnt--;
            q.push({num,match});
            if(!match) false_cnt++;
        }
        bool ans=true;
       

        if(false_cnt) return false;
        else return true;
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */