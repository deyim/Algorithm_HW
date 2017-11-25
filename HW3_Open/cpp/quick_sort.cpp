#include <stdio.h>
#include <string.h>
#include "my_types.h"

void swap_quick(ELEMENT *A, ELEMENT *B);
int partition(ELEMENT data[], int left, int right);
/*
Make own effective pivot strategy to select pivot element.
Recursive and typical quick sort
Pivot can be chosen among first, middle and last element
*/


int QUICK_SORT(ELEMENT data[], int left, int right) {

	int pivot;

	if(left < right){
		pivot = partition(data, left, right);
		QUICK_SORT(data, left, pivot-1);
		QUICK_SORT(data, pivot+1, right);
	}

	return 0;
}

int partition(ELEMENT data[], int left, int right)
{
	int a,b,c, pivot;
	
	a = left; b = (left+right)/2; c=right;
	if((ELEMENT_KEY(&data[a])>=ELEMENT_KEY(&data[b]) && ELEMENT_KEY(&data[b])>=ELEMENT_KEY(&data[c])) 
		|| (ELEMENT_KEY(&data[c])>=ELEMENT_KEY(&data[b]) && ELEMENT_KEY(&data[b])>=ELEMENT_KEY(&data[a]))) pivot = b;
	else if((ELEMENT_KEY(&data[b])>=ELEMENT_KEY(&data[a]) && ELEMENT_KEY(&data[a])>=ELEMENT_KEY(&data[c])) || (ELEMENT_KEY(&data[c])>=ELEMENT_KEY(&data[a]) && ELEMENT_KEY(&data[a])>=ELEMENT_KEY(&data[b]))) pivot = a;
	else pivot = c;

	swap_quick(&data[right], &data[pivot]);


	pivot = left;

	for(int i = left ; i < right ; i++){
		if(ELEMENT_KEY(&data[i]) < ELEMENT_KEY(&data[right])){
			swap_quick(&data[i], &data[pivot]);
			pivot++;
		}
	}

	swap_quick(&data[right], &data[pivot]);

	return pivot;
}


void swap_quick(ELEMENT *A, ELEMENT *B)
{
	ELEMENT tmp;
	//return;
	tmp.key = A-> key; tmp.score = A->score; tmp.other = A->other; strcpy(tmp.name, A->name);
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
	B->key = tmp.key; B->score = tmp.score; B->other = tmp.other; strcpy(B->name, tmp.name);
}
