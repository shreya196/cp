#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int c[n];
		int point[n];
		int done[7];
		int diff[7];	
		for(int j=0;j<n;j++){
			for(int g=0;g<8;g++){
				done[g]=0;
				diff[g]=0;
			}

			cin>>c[j];
			point[j]=c[j];
			int size[n][c[j]];
			for(int k=0;k<c[j];k++){
				cin>>size[j][k];

				if(size[j][k]==1){
					diff[1]++;
					done[1]=1;
				}
				else if(size[j][k]==2){
					diff[2]++;
					done[2]=1;
				}
				else if(size[j][k]==3){
					diff[3]++;
					done[3]=1;
				}
				else if(size[j][k]==4){
					diff[4]++;
					done[4]=1;
				}
				else if(size[j][k]==5){
					diff[5]++;
					done[5]=1;
				}
				else if(size[j][k]==6){
					diff[6]++;
					done[6]=1;
				}
			}
			int count=0;

			for(int k=1;k<7;k++){
				if(diff[k]>0)
					count++;
			}
//			cout<<count<<"\n";
			while(count>=4){
				if(count==6){
					int min=1000000000;
					for(int k=1;k<7;k++){
						if(min>diff[k])
							min=diff[k];
					}
					point[j]+=4*min;
					for(int k=1;k<7;k++){
						diff[k]--;
					}
				}

				else if(count==5){
					int min=1000000000;
					for(int k=1;k<7;k++){
						if(min>diff[k] && diff[k]!=0)
							min=diff[k];
					}
					point[j]+=3*min;
					for(int k=1;k<7;k++){
						if(diff[k]!=0)
							diff[k]--;
					}
				}

				else if(count==4){
					int min=1000000000;
					for(int k=1;k<7;k++){
						if(min>diff[k] && diff[k]!=0)
							min=diff[k];
					}
					point[j]+=2*min;
					for(int k=1;k<7;k++){
						if(diff[k]!=0)
							diff[k]--;
					}
				}
				count=0;
				for(int k=1;k<7;k++){
					if(diff[k]>0)
						count++;
				}
			}
		}


		
		int cc=-50;
//		for(int o=0;o<n;o++)
//			cout<<point[o]<<" ";
//
//		cout<<"\n";
		for(int z=1;z<n;z++){
			if(point[0]>point[z])
				cc=0;
			else{
				cc=-50;
				break;
			}
		}
		if(cc!=0){
//			cout<<"hi\n";
			for(int x=0;x<n;x++){
				for(int y=x+1;y<n;y++){
					if(point[y]>point[x]){
						cc=y;
					}
					else if(point[y]==point[x]){
						cc=-1;
						break;
					}
				}
				if(cc==-1)
					break;
			}
		}

		if(cc==0)
			cout<<"chef\n";
		else if(cc==-1)
			cout<<"tie\n";
		else
			cout<<cc+1<<"\n";
	}
}