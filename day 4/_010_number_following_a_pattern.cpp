//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
       string ans;
       stack<int> st;
       int num=1;
       for(int i=0;i<S.length();++i)
       {
           if(S[i]=='D')
           {
               st.push(num++);
           }else{
               st.push(num++);
               //breakpoint so khali krke print karao
               while(!st.empty())
               {
                   char c= st.top() + '0';
                   st.pop();
                  ans.push_back(c);
               }
           }
       }
       st.push(num);
       while(!st.empty())
       {   char c= st.top() + '0';
       st.pop();
           ans.push_back(c);
       }
       
       return ans;
       
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends