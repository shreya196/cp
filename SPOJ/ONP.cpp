#include <bits/stdc++.h>

using namespace std;

void convert(char str[]){
	stack <char> q;
	int i = 0, len = strlen(str);

	while(i < len){
		if(str[i] >= 'a' && str[i] <= 'z')
			printf("%c", str[i]);

		else if(str[i] == '(')
			q.push('(');

		else if(str[i] == '^'){
			while(q.top() != '('){
				printf("%c", q.top());
				q.pop();
			}

			if(str[i] == '(')
				q.pop();

			q.push('^');
		}

		else if(str[i] == '/' || str[i] == '*'){
			while(1){
				if(q.top() == '(' || q.top() == '^')
					break;
				printf("%c", q.top());
				q.pop();
			}

			if(str[i] == '(')
				q.pop();
			
			q.push(str[i]);
		}

		else if(str[i] == '+' || str[i] == '-'){
			while(1){
				if(q.top() == '+' || q.top() == '-')
					printf("%c", q.top());
				else
					break;
			}

			if(str[i] == '(')
				q.pop();

			q.push(str[i]);
		}

		else if(str[i] == ')'){
			while(q.top() != '('){
				printf("%c", q.top());
				q.pop();
			}
			q.pop();
		}

		++i;
	}
	printf("\n");
}

int main(){
	int t, p = 0;
	scanf("%d", &t);

	while(p < t){
		char str[401];
		scanf("%s", str);
		convert(str);
		++p;
	}
}