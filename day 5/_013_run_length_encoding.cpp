//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string ans;
  ans+=src[0];
  int cnt=1;
  for(int i=1;i<src.length();++i)
  {
      if(src[i]==src[i-1])
      {
          cnt++;
      }else{
          char c=cnt + '0';
          ans+=c;
          cnt=1;
          ans+=src[i];
      }
  }
  char c=cnt + '0';
  ans+=c;
  return ans;
}     
 
