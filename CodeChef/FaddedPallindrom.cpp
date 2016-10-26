#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s;
		int check = 0;
		cin>>s;
		int l = s.size();
		for(int j=0;j<l;j++){
			if(s[j]=='.'){
				if(s[l-j-1]!='.'){
					s[j] = s[l-j-1];
				}
				else
					s[j] = 'a';
			}
			else if(s[j]==s[l-j-1] || s[l-j-1]=='.')
				continue;

			else{
				check = 1;
				break;
			}
//			cout<<s[j]<<"\n";
			
		}

		if(check == 1)
			cout<<"-1\n";
		else
			cout<<s<<"\n";

	}
}