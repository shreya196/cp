#include <stdio.h>
#include <string.h>

char stack[120000];
int top = -1;

char x[120000];

int is_empty(){
  if(top == -1)
    return 1;
  else
    return 0;
}

void push(char x){
  top++;
  stack[top] = x;
}

char pop(){
  int temp = stack[top];
  top--;
  return temp;
}

int peek(){
  return stack[top];
}

void empty(){
  while(top >= 0)
    pop();
}

int main(){
  int n, i = 0;
  long long int len, j;
  scanf("%d", &n);
  char temp;

  while(i<n){
    scanf("%s", x);
    len = strlen(x);
    for(j=0; j<len; j++){
      if(x[j] == '1'){
        push(x[j]);
      }

      else {
        temp = pop();
        if(temp == '0' && peek() == '1'){
          pop();
        }
        else {
          push(temp);
          push(x[j]);
        }
      }
    }

    if(is_empty()){
      printf("Case %d: yes\n", i+1);
    }
    else {
      printf("Case %d: no\n", i+1);
    }

    empty();
    i++;
  }
  return 0;
}
