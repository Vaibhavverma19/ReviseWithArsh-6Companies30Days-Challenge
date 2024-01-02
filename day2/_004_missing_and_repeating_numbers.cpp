#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int N)
{   long long n=N;
	long long sn=n*(n+1)/2;
	long long sn2=n*(n+1)*(2*n+1)/6;

	long long s1=0,s2=0;
	for(int i=0;i<n;++i)
	{
		s1+=arr[i];
		s2+=(long long)arr[i]*(long long)arr[i];
	}

	long long val1=s1-sn;
	long long val2=s2-sn2;
	val2=val2/val1;
	//val1 = x-y
	//val2=x+y

	long long x=(val1+val2)/2;
	long long y=val2-x;

	return {(int)y,(int)x};

	
}
