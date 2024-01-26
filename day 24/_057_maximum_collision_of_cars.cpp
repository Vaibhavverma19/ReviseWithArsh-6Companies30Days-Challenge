class Solution {
public:
    int countCollisions(string directions) {
        //jitni bhi left me gaadiya hai jo ki left ko hi jaa rhi hai vo left ko hi chlti jayengi or ni takrayngi
       
        int left=0;
        while(left < directions.length() && directions[left]=='L')
        {
            
            left++;
        }

        //similarly for right going cars at the right end;
       
        int right=directions.length()-1;
        while(right>=0 && directions[right]=='R')
        {
           
            right--;
        }

        // ab unke bipch jo bhi cars hai vo gadbad karengi and agr stationary hai top use ignore karenge kuki usse takrane pe 1 hi count badhega and range ke andr jitni bhi cars hai vo sure hai ki takrayngi hi except stationary kuki unhe count ni krna hai.
        int count=0;
        for(int i=left; i<=right;++i)
        {
            if(directions[i]!='S')
            {
                count++;
            }
        }

        return count;
    }
};