#include<iostream>
#include<algorithm>
#include<utility>
#include<stdlib.h>
#include<vector>
using namespace std;
int main()
{
	long long  int arr[100];
	int q,n,k,i,c=0,sum=0,s;
	cin>>q;
	while(q)
	{
		
	cin>>n;
	cin>>k;
	for(i=0;i<n;i++)
	{
	cin>>arr[i];
	if(arr[i]<0)
	c++;
}
	sort(arr,arr+n)	;
	if(c!=0)
	{
	
	 if(k<=c)
	 for(i=0;i<k;i++)
	 {
	 
	 arr[i]=-arr[i];
	 	sort(arr,arr+n)	;
      
}

else
{
s=k%c;
for(i=0;i<s;i++)
{

arr[i]=-arr[i];	
	sort(arr,arr+n)	;
}
}
}
else
{
 if(k<=n)
	 for(i=0;i<k;i++)
	 {
	 
	 arr[i]=-arr[i];
	 	sort(arr,arr+n)	;
}


else
{
s=k%n;
for(i=0;i<s;i++)
{

arr[i]=-arr[i];	
	sort(arr,arr+n)	;
}
}
}
for(i=0;i<n;i++)
	 sum=sum+arr[i];
	 cout<<sum<<endl;
	q--;
	sum=0;
	}
}
