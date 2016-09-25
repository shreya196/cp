#include <bits/stdc++.h>
#define MAX 9999

using namespace std;

int main(){
	int t, i, j;
	int wmin, hmin, dmin;
	long long int total;

	while(1){
		scanf("%d", &t);

		if(t == 0)
			break;

		int w[t], h[t], d[t];
		wmin = MAX, hmin = MAX, dmin = MAX;
		total = 0;
		i = 0;

		while(i < t){
			scanf("%d %d %d", &w[i], &h[i], &d[i]);
			if(w[i] < wmin)
				wmin = w[i];
			if(h[i] < hmin)
				hmin = h[i];
			if(d[i] < dmin)
				dmin = d[i];
			total += (w[i] * h[i] * d[i]);
			i++;
		}

		if(wmin < hmin){
			if(wmin < dmin){
				hmin = wmin;
				dmin = wmin;
			}

			else {
				wmin = dmin;
				hmin = dmin;
			}
		}

		else {
			if(hmin < dmin){
				wmin = hmin;
				dmin = hmin;
			}

			else {
				wmin = dmin;
				hmin = dmin;
			}
		}

		for(i = 0; i < t; i++){
			if(wmin == 1)
				break;
			if((w[i] % wmin != 0) || (h[i] % hmin != 0) || (d[i] % dmin != 0)){
				i = -1;
				--wmin;
				--hmin;
				--dmin;
			}
		}

		printf("%lld\n", total/(wmin * hmin * dmin));
	}
}