#include <stdio.h>
#include <string.h>
#include "my_types.h"


void substitute(ELEMENT *A, ELEMENT *B){
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
}

int INSERTION_SORT(ELEMENT data[], int left, int right) {
	int i, cur, curkey;
	ELEMENT tmp;
	for( i = left+1; i <= right ; i++){
		cur = i;
		substitute(&tmp, &data[cur]);
		curkey = ELEMENT_KEY(&tmp);
		while(curkey > ELEMENT_KEY(&data[cur-1]) && cur > left){ 
			substitute(&data[cur], &data[cur-1]);
			cur--;
		}
		substitute(&data[cur], &tmp);
	}
	return 1;
}

