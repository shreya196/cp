#include <stdio.h>

int main(){
	int n, i, j, k, row, col;
	char mat;
	scanf("%d", &n);
	long long int arr1[n][n], arr2[n][n], sum = 0, con, data, prev;
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			scanf("%lld", &arr1[i][j]);
		}
	}

	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			scanf("%lld", &arr2[i][j]);
		}
	}

	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			for(k = 0; k<n; k++){
				sum = sum + arr1[i][k]*arr2[k][j];
			}
		}
	}

	scanf("%lld", &con);

	i = 1;
	while(i<=con){
		scanf(" %c %d %d %lld", &mat, &row, &col, &data);
		if(mat == 'A'){
			prev = arr1[row][col];
			arr1[row][col] = data;
			for(j = 0; j<n; j++){
				sum = sum - (prev * arr2[col][j]);
				sum += data*arr2[col][j];
			}
		}

		else {
			prev = arr2[row][col];
			arr2[row][col] = data;
			for(j = 0; j<n; j++){
				sum -= prev*arr1[j][row];
				sum += data*arr1[j][row];
			}
		}
		printf("%lld\n", sum);
		i++;
	}


	return 0;
}
