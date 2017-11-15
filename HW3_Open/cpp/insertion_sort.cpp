#include <stdio.h>

#include "my_types.h"
#include <string.h>

/*
void swap(struct ELEMENT *A, struct ELEMENT *B){
	struct ELEMENT tmp;
	tmp->key = A-> key; tmp->score = A->score; tmp->other = A->other; strcpy(tmp->name, A->name);
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
	B->key = tmp-> key; B->score = tmp->score; B->other = tmp->other; strcpy(B->name, tmp->name);

}
*/

void substitute(ELEMENT *A, ELEMENT *B){
	//printf("substitute\nA.key: %d vs B.key: %d\n", A->key, B->key);
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
}

int INSERTION_SORT(ELEMENT data[], int left, int right) {
	// must return 1 if the function finishes normally or return 0 otherwise --> How check this?,,,,
	//	return 0;
	int i, cur, curkey;
	ELEMENT tmp;
	printf("left: %d, right: %d\n", left, right);
	for( i = left+1; i <= right ; i++){
		cur = i;
		//printf("\n\n");
		substitute(&tmp, &data[cur]);
		curkey = tmp.key;
		//printf("i: %d\n", i);
		while(curkey < data[cur-1].key && cur > left){  //////////////////RERERERERERERE
			//printf("data[%d].key: %d vs data[%d].key: %d\n", i, data[i].key, cur-1, data[cur-1].key);
			substitute(&data[cur], &data[cur-1]);
			
			
			// ELEMENT *ptr = data;
			// for (int j = left; j <= i; j++, ptr++)
			// 	fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", j, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			// fprintf(stdout, "\n");

			cur--;
			// printf("why while loop out???\n");
			// printf("data[i[.key %d ? data[cur-1].key %d\n", data[i].key, data[cur-1].key);
			// printf("cur %d ? left %d\n", cur, left);
		}
		substitute(&data[cur], &tmp);
		// ELEMENT *ptr = data;
		// for (int j = left; j <= i; j++, ptr++)
		// 		fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", j, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
		// 	fprintf(stdout, "\n");
	}
	return 1;
}