#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
	return(*(long long int*)a - *(long long int*)b);
}

int main(){
  int n;
  long long int i, j, k;
  scanf("%d", &n);
  long long int arrSize, count;
  long long int temp = 0, sumAns = 0;
  i = 0;

  printf("\n");
  while( i < n ){
    count = 0, temp = 0, sumAns = 0;
    scanf("%lld", &arrSize);
    int x;
    long long int sum[arrSize];

    for(j = 0; j < arrSize; j++){
      scanf("%d", &x);
      if(j == 0)
        sum[j] = x;
      else
        sum[j] = sum[j-1] + x;
    }

    qsort(sum,arrSize,sizeof(long long int),cmp);

    if(sum[0] == 0)
      sumAns++;

    for(j = 1; j < arrSize; j++){
      if(sum[j] == 0)
        sumAns++;

      if(sum[j] == sum[j-1])
        count++;

      else {
        sumAns += ((count)*(count+1)/2);
        count = 0;
      }
    }

    sumAns += ((count)*(count+1)/2);
    printf("%lld\n", sumAns);
    i++;
  }
  return 0;
}
