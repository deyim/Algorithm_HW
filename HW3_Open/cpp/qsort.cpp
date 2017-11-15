#include "my_types.h"
#include <stdlib.h>

///QSORT COMPLETED///


int keys_compare(const void *a, const void *b) {
	ELEMENT *rec_a, *rec_b;
	rec_a = (ELEMENT*)a;
	rec_b = (ELEMENT*)b;
	// do it yourself
	if(rec_a->key > rec_b->key) return -1;
	else if(rec_a->key == rec_b->key) return 0;
	else return 1;	
}

/*

QSORT uses the library function given by stdlib.h
no need to make code about it 

*/

int QSORT(ELEMENT data[], int left, int right) {
	// must return 1 if the function finishes normally or return 0 otherwise

	qsort(data + left, right-left+1, sizeof(ELEMENT), keys_compare);
	return 1;
}