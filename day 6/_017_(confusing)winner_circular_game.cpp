class Solution {
public:
    //this function will return position.
    int solve(int n,int k)
    {
        if(n==1) return 0;

        //now lets solve for n-1 numbers and we get winner's position as x.
        int x=solve(n-1,k);

        //for eg arr is 3,4,0,1 so the second position is winner i.e in pos 0,1,2,3 winner is 1st position.

        //now we have to extract the number of the winner w.r.t position.
        int y=(x+k)%n;

        return y;

    }
    int findTheWinner(int n, int k) {
       return solve(n,k) + 1;
    }
};