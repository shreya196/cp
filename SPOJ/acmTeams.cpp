#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int count=0;
		int e,n;
		cin>>e>>n;
		while(n+e>=3 && n>0 && e>0){
			if(e>=n && n+e>=3 && n>0 && e>0){
				count++;
				e-=2;
				n--;
			}
			if(e<n && n+e>=3 && n>0 && e>0){
				count++;
				e--;
				n-=2;
			}
		}

		cout<<count<<"\n";
	}
}