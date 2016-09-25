#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
	return(*(int*)a - *(int*)b);
}

int main(){
  int n, i = 1;
  long long int size, j = 0, k = 0, count, some;
  scanf("%d", &n);

  while(i <= n){
    count = 0;
    scanf("%lld", &size);
    long long int arr[size], arr2[size];

    for(j = 0; j<size; j++){
      scanf("%lld", &arr[j]);
      arr2[j] = 0;
    }

    qsort(arr,size,sizeof(long long int),cmp);

    some = size -1;

    for(j = size-1; j>=0; j--){
      k = some - 1;
      for(; k>=0; k--){
        if(arr[j] >= arr[k]*2){
          if(arr2[k] == 0){
            count++;
            arr2[k] = 1;
            some = k;
            break;
          }
        }
      }
    }

    printf("Case %d: %lld\n", i, size - count);
    i++;
  }
  return 0;
}
