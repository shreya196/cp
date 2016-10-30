    #include<iostream>
    #include<algorithm>
    #include<stdio.h>
    using namespace std;
    struct cow
    {
    	int id;
    	int dead;
    	int profit;
    };
    bool comparision(cow a,cow b)
    {
    	return (a.profit>b.profit);
    }
    void calc(cow arr[],int n)
    {
    	sort(arr,arr+n,comparision);	
    	int result[n],tot=0;
    	bool slot[n];
    	for(int i=0;i<n;i++)
    	slot[i]=false;
    	for(int i=0;i<n;i++)
    	{
    	
    	  for(int j=min(n,arr[i].dead)-1;j>=0;j--)
    	  {
    	  
    	  if(slot[j]==false)
    	  {
    	  	result[j]=i;
    	  	slot[j]=true;
    	  	break;
    	  }
    	}
    	}
    	for(int i=0;i<n;i++)
    	{
    		if(slot[i])
    		{
    		
    	//cout<<arr[result[i]].profit;
    	tot=tot+arr[result[i]].profit;
    }
    }
    	cout<<tot<<endl;
    }
    int main()
    {
    	int n,a,b;
    	cin>>n;
    	cow arr[n+9];
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&arr[i].profit);
    		scanf("%d",&arr[i].dead);
    	}
    	calc(arr,n);
    }
     
     
