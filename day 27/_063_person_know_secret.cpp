class Solution {
public:
   
   int solve(int curr,int& n,int& d,int& f,vector<long>& dp)
   {
       if(curr > n)
       {
           return 0;
       }
      
        if(dp[curr]!=-1) return dp[curr];

       long ans=0;
       //is person ko to pata hai to ise final ans me include kare 
       ans++;

       //lekin ye bhul bhi to skta hai forget ki wajah se.
       //ye tab bhulega agr forget vala din total days se phle aa jaye
       if(curr + f <= n)
       {
           ans--;
       }

       //ab ise to pata hai to ye kise kise batayega
       for(int i= curr+d ; i<min((curr + f),n+1);++i)
       {
           //ab isne agle bande ko bata diya ab vo kise kise batayega?
           //to ye aisa hi ho gaya ab jaise ek insaan ko pata ho vo kise batayega
           ans+=solve(i,n,d,f,dp);
           ans%=1000000007;
       }

       return dp[curr]=ans;


   }

 
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1,-1);
        return solve(1,n,delay,forget,dp);
    
    }
};