#include<iostream>
using namespace std;

#define max 1000000
int visited[max];
int ch=0,ck=1,f;
int count=0;

int check(){
//	cout<<"k\n";
	for(int i=1;i<=f;i++){
		if(visited[i]==1)
			ch=1;	
		else
			ck=0;	
	}

	if(ck==0)
		return 0;
	return 1;
}

int main(){
	int s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	int z=1;
	while(z<=f){
		visited[z]=0;
		z++;
	}
	visited[s]=1;

	if(d==0 && s>g){
		cout<<"use the stairs\n";
		return 0;
	}
	
	

	while(!check()){
//		cout<<"hello\n";
		while(s<g){
//			cout<<"hi\n";
			s+=u;
			if(visited[s]==1){
				cout<<"use the stairs\n";
				return 0;			
			}
			visited[s]=1;
			count++;
		}
		if(s==g){
//			cout<<"final";
			cout<<count<<"\n";
			return 0;		
		}

		while(s>g){
//			cout<<"here\n";
			s-=d;
			count++;
			visited[s]=1;
		}


		
	}
	
}
