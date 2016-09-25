    #include <bits/stdc++.h>
    #define MAX 200010
     
    using namespace std;
     
    int arr[MAX];
     
    long long int findDist(int s, int d, int dir, int n){
       	long long int dist = 0;
        int cur = s, temp;
        while(cur != d){
        	if(dir == 1 && cur == n){
        		temp = 1;
        	}
         
        	else if(dir == -1 && cur == 1){
        		temp = n;
        	}
         
        	else {
        		temp = cur + dir;
        	}
         
        	if(dir == 1)
        		dist = dist + arr[cur];
         
        	else
        		dist = dist + arr[temp];
         
        	cur = temp;
        }
     
        return dist;
    }
     
    long long int findOneMore(int s, int d, int dir, long long int sDist, int n){
    	long long int dist = 0;
    	long long int tempDist, min = sDist;
        int cur = s, temp;
     
        while(cur != d){
        	if(dir == 1 && cur == n){
        		temp = 1;
        	}
         
        	else if(dir == -1 && cur == 1){
        		temp = n;
        	}
         
        	else {
        		temp = cur + dir;
        	}
     
        	if(dir == 1)
        		dist = dist + arr[cur];
         
        	else
        		dist = dist + arr[temp];
     
        	tempDist = 2*dist + sDist;
     
        	if(tempDist < min)
        		min = tempDist;
     
        	cur = temp;
        }
     
        return min;
    }
     
     
    long long int findMin(int s, int d, int dir, int n, long long int destDist){
     
    	long long int dist = 0, comp = 0;
    	long long int tempDist, min = destDist;
        int cur = s, temp;
     
        while(cur != d){
        	if(dir == 1 && cur == n){
        		temp = 1;
        	}
         
        	else if(dir == -1 && cur == 1){
        		temp = n;
        	}
         
        	else {
        		temp = cur + dir;
        	}
     
        	if(dir == 1)
        		dist = dist + arr[cur];
         
        	else
        		dist = dist + arr[temp];

        	if(temp == d){
        		tempDist = dist;
        		if(tempDist < min)
        			min = tempDist;
        	}

        	if(dist < comp){
        		tempDist = 2*dist + destDist;
     
	        	if(tempDist < min)
	        		min = tempDist;
	     
	        	if(temp != d){
	        		tempDist = findOneMore(d, temp, -dir, tempDist, n);
	        	}
	     
	        	if(tempDist < min)
	        		min = tempDist;

	        	comp = dist;
	     
        	}
        	cur = temp;
        }
     
        destDist = dist;
        dist = 0;
        while(cur != s){
        	if(dir == 1 && cur == n){
        		temp = 1;
        	}
         
        	else if(dir == -1 && cur == 1){
        		temp = n;
        	}
         
        	else {
        		temp = cur + dir;
        	}
         
        	if(dir == 1)
        		dist = dist + arr[cur];
         
        	else
        		dist = dist + arr[temp];
     
        	if(temp == s){
        		tempDist = 2*destDist + dist;
        		if(tempDist < min)
        			min = tempDist;
        	}
     
        	tempDist = 2*dist + destDist;
        	if(tempDist < min)
        		min = tempDist;
     
        	cur = temp;
        }
     
        return min;
    }
     
    int main(){
    	int t, p = 0, n, i, s, d;
    	long long int dist1, dist2, ans1, ans2;
    	scanf("%d", &t);
     
    	while(p < t){
    		scanf("%d", &n);
    		for(i = 1; i <= n; i++)
    			scanf("%d", &arr[i]);
    		scanf("%d %d", &s, &d);
     
    		if(n != 2){
    			dist1 = findDist(s, d, 1, n);
    			dist2 = findDist(s, d, -1, n);
     
    			ans1 = findMin(s, d, 1, n, dist2);
    			ans2 = findMin(s, d, -1, n, dist1);
     
    			if(ans2 < ans1)
    				ans1 = ans2;
    		}
     
    		else {
    			ans1 = arr[s];
    		}
     
    		printf("%lld\n", ans1);
    		++p;
    	}
     
    	return 0;
    } 