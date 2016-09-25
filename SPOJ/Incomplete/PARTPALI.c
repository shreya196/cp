#include <stdio.h>

int main(){
  long long int n, i = 0, j = 0;
  scanf("%lld", &n);
  long long int x, y, num = 1, count = 0, pal, k = 0, div, div2;
  while(i < n){
    num = 1;
    count = 0;
    scanf("%lld %lld", &x, &y);

    if(x % 10 == 0){
      i++;
      continue;
    }

    for(j = 1; j<y; j++)
      num = num*10;

    div = num;
    div2 = num;

    num = num/x + 1;

    while(1){
      pal = x * num;
      printf("%lld\n", pal);
      if(pal/div2 >= 10)
        break;
      div = div2;
      for(k = 1; k<=(y/2); k++){
        if(pal%10 != pal/div)
          break;
        pal = pal/10;
        div = div/10;
        pal = pal - ((pal/div)*div);
        div = div/10;
      }

      if(k == (y/2) + 1)
        count++;
      num++;
    }
    printf("%lld\n", count);
    i++;
  }
  return 0;
}
