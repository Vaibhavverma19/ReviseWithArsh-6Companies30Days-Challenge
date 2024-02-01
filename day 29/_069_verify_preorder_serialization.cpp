class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder+=",";
        int totalcapacity=1;
        for(int i=0;i<preorder.size();++i)
        {  char c=preorder[i];
            //if comma then only process
            if(c!=',') continue;

            totalcapacity--; //ek node process ho chuki

            if(totalcapacity < 0) return false; //agr null nodes jyada hui to capacity se jada nodes process ho jayengi tbhi.

        //agr comma se phle vli node koi number thi iska mtlb capacity 2 se badh jayegi.
        if(preorder[i-1]!='#')
        {
            totalcapacity+=2;
        }
        }

        //agar complete binary tree hai to totalcapacity jitni hai utni hi nodes process hui hongi.
        if(totalcapacity==0)
        return true;

        return false;
    }
};