class Solution {
public:
    //is question me hme hr br ek ij return krna hai flip call [e jo ki 0 tha lekin ab 1 bn gya hai. 
    // or reset krne pe firse sab 0 ho jaynge lekin hm 0,0 se strt kre or agr hr br reset kre to hr br 0,0 ans na mile kuki fir o equally likely soln ni rhega isiliye bs i j ke sath khelna hai ki jisse bs hr br unique value mile lekin repqting ni hoi chahiye. or agr ij range se bhr jaa rhe ho to use tackle kar ske.

    int col,row;
    int i=0,j=0;
    Solution(int m, int n) {
       col=n;
        row=m;
    }
    
    vector<int> flip() {
        int x=i,y=j;
        //now we iterate i,j but cautiously.

        if(j+1<col)
        {
            j++;
        }else if(i+1<row)
             {
                 i++;
                 j=0; //hr row ko phle col se strt krna hai
             }
             else{
                 i=0;
                 j=0;
             }
        
        return {x,y};
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */