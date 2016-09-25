#include <stdio.h>
#include <string.h>

long long int gcd(long long int num, long long int den){
  if(num == den)
    return num;

  if(num == 0)
    return den;

  if(den == 0)
    return num;

  if(num%2 == 0){
    if(den%2 == 0)
      return 2*gcd(num/2, den/2);
    else
      return gcd(num/2, den);
  }

  if(num%2 != 0){
    if(den%2 != 0){
      if(num >= den)
        return gcd((num-den)/2, den);
      else
        return gcd((den-num)/2, num);
    }

    if(den%2 == 0)
      return gcd(num, den/2);
  }
}

int main(){
  int i;
  long long int decimalPart, y, z, temp1, temp2, num, den, ansNum, ansDen, gcdVal, count = 0;
  while(1){
    char number[30];
    scanf("%s", number);

    if(strlen(number) == 1)
      break;

    decimalPart = 0, y = 1, count = 0;

    for(i = 2;;i++){
      if(number[i] == '.')
        break;
        count++;
        decimalPart = decimalPart*10 + (number[i] - '0');
        y = y*10;
    }

    temp1 = decimalPart, temp2 = y;
    ansDen = decimalPart, ansNum = y;

    for(i = 1; i <= count; i++){
      temp1 = temp1/10;
      temp2 = temp2/10;
      num = decimalPart - temp1;
      den = y - temp2;

      gcdVal = gcd(num, den);
      num = num/gcdVal;
      den = den/gcdVal;

      if(den < ansDen || i == 1){
          ansNum = num;
          ansDen = den;
      }
    }
    printf("%lld/%lld\n", ansNum, ansDen);
  }
  return 0;
}
