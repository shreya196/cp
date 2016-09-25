#include <stdio.h>
#include <string.h>

int main(){
  int n, i = 0;
  scanf("%d", &n);

  long long int a, b, temp, res;
  char x[999999], y[999999];
  while(i < n){
    scanf("%s %s", x, y);
    int p;
    a = 0, b = 0, temp = 0, res = 0;
    for(p = strlen(x) - 1; p >= 0; p--){
      temp = x[p] - '0';
      a = a*10 + temp;
    }

    for( p = strlen(y) - 1; p>=0; p--){
      temp = y[p] - '0';
      b = b*10 + temp;
    }

    temp = a + b;
    p = 0;

    while(temp>0){
      p = temp%10;
      temp = temp/10;
      res = res*10 + p;
    }

    printf("%lld\n", res);
    i++;
  }
  return 0;
}
