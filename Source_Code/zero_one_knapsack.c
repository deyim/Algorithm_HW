#include <stdio.h>
#include <stdlib.h>

int main(){
	;
}

int zero_one_knapsack(int *p, int*w, int n, int W)
{
	int i, ww, tmp;

	for (ww = 0; ww <= W ; ww++) P[0][ww] = 0;
	for(i = 0 ; i <= n; i++){
		p[i][0] = 0;
		for(ww = 1 ; ww <= W; ww++){
			if(w[i] <= ww){
				if((tmp = P[i]+P[i-1][ww-w[i]]) > P[i-1][ww])
					P[i][ww] = tmp;
				else
					P[i][ww] = P[i-1][ww];
			}
			else P[i][ww] = P[i-1][ww];
		}
	}
	return P[n][W];
}
