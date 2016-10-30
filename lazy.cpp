#include<bits/stdc++.h>

using namespace std;
int main()
{
	long long int n,t,b,m,res=0,q,s=5,x;
	cin>>t;
	while(t!=0)
	{
		cin>>n>>b>>m;
		//cout<<n<<endl;

		q=n;
           while(q!=0)
		{
			x=q;
			//cout<<q<<endl;
			if(q%2==0)
				q=q/2;
			else
				q=(q+1)/2;
			//cout<<q<<endl;
			res=res+q*m+b;
            q=x-q; 
            m=2*m;

		}
		cout<<res-b<<endl;
		t--;
		res=0;
	}
}
