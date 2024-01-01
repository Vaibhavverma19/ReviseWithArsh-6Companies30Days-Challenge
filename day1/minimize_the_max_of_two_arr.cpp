#include<math.h>
#include<bits/stdc++.h>
class Solution {
public:
    int lc(long long  a, long long  b) {
        long long  temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
       

         long long int start=1;
         long long int end=1e15;

         long long int mid;
         long long int ans=end;
         long long int g=__gcd(divisor1,divisor2);
         long long lcm=lc(divisor1,divisor2);
        

         while(start<=end)
         {   long long int cnt1=uniqueCnt1;
             long long int cnt2=uniqueCnt2;
             mid=start+(end-start)/2;
            //   cout<<mid<<".....";
             if(divisor1==divisor2){
                 //no of integers not divisible by divisors  
                 long long int c=mid - mid/divisor1;
                 if(c >= uniqueCnt1+uniqueCnt2)
                 {   ans=mid;
                     end=mid-1;
                 }else{
                     start=mid+1;
                 }

             }else{
                 //c1 is the no. of integers divisible by d1 and not by d2.
                 //c2 in no. of integeres divisible by d2 and not d1.
                 //common no. of integers divi by both d1 and d2.
                 
                 
                 long long common = mid/lcm;
                 long long c1=mid/divisor1 - common;
                 long long c2=mid/divisor2 -common;

                 // put c1 integers in arr2 and c2 in arr1 because we cannot waste them
                cnt1 = cnt1 - min(cnt1,c2);
                cnt2 = cnt2 - min(cnt2,c1);

                long long rem= mid - (c1 + c2 + common);
                if(rem>=cnt1 + cnt2)
                {   
                    ans=mid;
                    end=mid-1;
                    
                }else{
                    start=mid+1;
                }
             }

             
         }


         return ans;
        
    }
};