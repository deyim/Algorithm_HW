#include <stdio.h>
#include <string.h>
#include "my_types.h"


void substitute(ELEMENT *A, ELEMENT *B) {
	memcpy(A, B, sizeof(ELEMENT));
	//	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
}

int INSERTION_SORT(ELEMENT data[], int left, int right) {
	unsigned int i, cur, curkey;
	ELEMENT tmp;
	for (i = left + 1; i <= right; i++) {
		cur = i;
		substitute(&tmp, &data[cur]);
		curkey = ELEMENT_KEY(&tmp);
		while (cur > left && curkey < ELEMENT_KEY(&data[cur - 1])) {
			/***************fatal ERROR!!!!**********************/
			// if cur becomes 0 because of c--; below, 
			// in the condition check sentence data[-1] is accessed!!!!
			// if cur > left should be checked first!!
			substitute(&data[cur], &data[cur - 1]);
			cur--;
		}
		substitute(&data[cur], &tmp);
	}
	return 1;
}

//1,048,576
