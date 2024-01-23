class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int length=1;
        int temp=1;
        for(int i=0;i<hBars.size();++i)
        {
            if(i!=0 && hBars[i]> hBars[i-1] + 1)
            {
                temp=1;
                // continue;
            }

            temp++;
            length=max(length,temp);
        }   
        int breadth=1;
        int temp2=1;
        for(int i=0;i<vBars.size();++i)
        {
            if(i!=0 && vBars[i]> vBars[i-1] + 1)
            {
                temp2=1;
                // continue;
            }

            temp2++;
            breadth=max(breadth,temp2);
        }   

        int side=min(length,breadth);

        return side*side;
    }
};