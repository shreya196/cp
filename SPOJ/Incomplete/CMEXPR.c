#include <stdio.h>
#include <string.h>

int main(){
  char exp[250];
  int n, i = 1, len, j, countTemp = 0, k;
  int countParanStart;

  scanf("%d", &n);

  while(i<=n){
    countTemp = 0;
    char ans[250] = {};
    char ansTemp[250] = {};
    char temp[250] = {};
    countParanStart = -1;
    int paranStart[250] = {}, opPlus[250] = {}, opMinus[250] = {}, opMul[250] = {}, opDiv[250] = {};
    scanf("%s", exp);
    len = strlen(exp);

    for(j = 0; j<len; j++)
      ansTemp[j] = 0;

    for(j = 0; j<len; j++){
      ansTemp[j] = exp[j];
      if(exp[j] == '('){
        countParanStart++;
        paranStart[countParanStart] = j;
      }
      else if(exp[j] == '+'){
        opPlus[countParanStart] = 1;
      }
      else if(exp[j] == '-'){
        opMinus[countParanStart] = 1;
      }
      else if(exp[j] == '*'){
        opMul[countParanStart] = 1;
      }
      else if(exp[j] == '/'){
        opDiv[countParanStart] = 1;
      }
      else if(exp[j] == ')'){
        if((exp[paranStart[countParanStart] - 1] == '(' && exp[j+1] == ')') || (paranStart[countParanStart] == 0 && exp[j+1] == ')') || (paranStart[countParanStart] == 0 && j == len - 1)){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
        }

        else if((opPlus[countParanStart] == 1 || opMinus[countParanStart] == 1) && ((paranStart[countParanStart] == 0 || exp[paranStart[countParanStart] - 1] == '+' || exp[paranStart[countParanStart] - 1] == '(') && (exp[j+1] == '+' || exp[j+1] == '-'))){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
          if(opPlus[countParanStart] == 1){
            opPlus[countParanStart] = 0;
          }
          else
            opMinus[countParanStart] = 0;
        }

        else if(opMul[countParanStart] == 1 && opMinus[countParanStart] != 1 && opPlus[countParanStart] != 1 && opDiv[countParanStart] == 0 && ((paranStart[countParanStart] == 0) || (exp[paranStart[countParanStart] - 1] == '*' || exp[paranStart[countParanStart] - 1] == '+' || exp[paranStart[countParanStart] - 1] == '-'  || exp[paranStart[countParanStart] - 1] == '('))){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
          opMul[countParanStart] = 0;
        }

        else if(opMul[countParanStart] == 1 &&  opMinus[countParanStart] != 1 && opPlus[countParanStart] != 1 && (exp[j+1] == '/' || exp[j+1] == '*' || exp[j+1] == '+' || exp[j+1] == '-')){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
          opMul[countParanStart] = 0;
        }

        else if(opDiv[countParanStart] == 1 &&  opMinus[countParanStart] != 1 && opPlus[countParanStart] != 1 && ((paranStart[countParanStart] == 0) || (exp[paranStart[countParanStart] - 1] == '-' || exp[paranStart[countParanStart] - 1] == '+') || exp[paranStart[countParanStart] - 1] == '(')){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
          opDiv[countParanStart] = 0;
        }

        else if(opDiv[countParanStart] == 1 &&  opMinus[countParanStart] != 1 && opPlus[countParanStart] != 1 && (exp[j+1] == '/' || exp[j+1] == '*' || exp[j+1] == '+' || exp[j+1] == '-') && exp[paranStart[countParanStart] - 1] != '/'){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
          opDiv[countParanStart] = 0;
        }

        else if(j - paranStart[countParanStart] == 2){
          ansTemp[j] = 0;
          ansTemp[paranStart[countParanStart]] = 0;
        }
        opPlus[countParanStart] = 0;
        opMinus[countParanStart] = 0;
        opMul[countParanStart] = 0;
        opDiv[countParanStart] = 0;
        countParanStart--;
      }
    }

    for(j = 0, k = 0; j<len; j++){
      if(ansTemp[j] != 0){
        ans[k] = ansTemp[j];
        k++;
      }
    }
    printf("%s\n", ans);
    i++;
  }

  return 0;
}
