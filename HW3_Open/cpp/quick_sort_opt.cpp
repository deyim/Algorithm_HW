#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_types.h"
void swap_quick_opt(ELEMENT *A, ELEMENT *B);
int partition_opt(ELEMENT data[], int left, int right, int medIdx);

/*

use selection sort and insertion sort to optimize quick sort

*/

int QUICK_SORT_OPT(ELEMENT data[], int left, int right) {


   
	int elemCnt, pivot, selOk, medIdx;
	elemCnt = right - left + 1;
	// insertion sort for base case
	if(elemCnt <= 10){
		INSERTION_SORT(data, left, right);	
	} 

	// selection recursion to find median
   else if(right-left>0){
        selOk = SELECTION_REC(data, left, right, elemCnt/2, &medIdx);
	   // divide using the found median
	   pivot = partition_opt(data, left, right, medIdx);

	   // recursion
	   QUICK_SORT_OPT(data, left, pivot-1);
	  // if(pivot+1 < right)
		QUICK_SORT_OPT(data, pivot+1, right);
   }
	return 0;
}

int partition_opt(ELEMENT data[], int left, int right, int medIdx)
{
	int pivot;

	swap_quick_opt(&data[right], &data[medIdx]);


	pivot = left;

	for(int i = left ; i < right ; i++){
		if(ELEMENT_KEY(&data[i]) < ELEMENT_KEY(&data[right])){
			swap_quick_opt(&data[i], &data[pivot]);
			pivot++;
		}
	}

	swap_quick_opt(&data[right], &data[pivot]);

	return pivot;
}

void swap_quick_opt(ELEMENT *A, ELEMENT *B)
{
	ELEMENT tmp;
	tmp.key = A-> key; tmp.score = A->score; tmp.other = A->other; strcpy(tmp.name, A->name);
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
	B->key = tmp.key; B->score = tmp.score; B->other = tmp.other; strcpy(B->name, tmp.name);
}
