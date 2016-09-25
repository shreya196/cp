#include <stdio.h>

int main(){
  int n, countNeg = 0, noOfOp = 0, no = 0;
  long long int sum = 0;
  scanf("%d", &no);
  int k = 1;
  while(k <= no){
    scanf("%d %d", &n, &noOfOp);
    int arr[n];
    for(int i = 0; i<n; i++){
      scanf("%d", &arr[i]);
      if(arr[i] < 0)
        countNeg++;
      sum += arr[i];
    }

    for(int  i = 0; i<noOfOp; i++){
      if(i < countNeg){
        sum -= arr[i];
        arr[i] = -1 * arr[i];
        sum += arr[i];
      }

      else {
        if(countNeg == n){
          sum -= arr[countNeg - 1];
          arr[countNeg - 1] = -1 * arr[countNeg - 1];
          sum += arr[countNeg - 1];
        }
        else if(countNeg == 0){
          sum -= arr[countNeg];
          arr[countNeg] = -1 * arr[countNeg];
          sum += arr[countNeg];
        }
        else if(arr[countNeg - 1] < arr[countNeg]){
          sum -= arr[countNeg - 1];
          arr[countNeg - 1] = -1 * arr[countNeg - 1];
          sum += arr[countNeg - 1];
        }
        else {
          sum -= arr[countNeg];
          arr[countNeg] = -1 * arr[countNeg];
          sum += arr[countNeg];
        }
      }
    }
    printf("%lld\n", sum);
    k++;
    sum = 0;
    countNeg = 0;
  }
  return 0;
}
