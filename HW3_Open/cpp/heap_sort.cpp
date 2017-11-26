#include <stdio.h>
#include <string.h>
#include "my_types.h"
void substitute_heap(ELEMENT *A, ELEMENT *B);
void swap_heap(ELEMENT *A, ELEMENT *B);
void adjust(ELEMENT data[], int root, int n);
// void makeHeap(ELEMENT data[], int root, int n);
// void insertMaxHeap(ELEMENT data[], ELEMENT *elem, int *n);
// ELEMENT * deleteMaxHeap(ELEMENT data[], int *n);
int checkIfHeap(ELEMENT data[], int left, int right);


int HEAP_SORT(ELEMENT data[], int left, int right)
{
	int i, datanum = right - left + 1;
	int check;

	//make heap	
	for (i = datanum / 2 - 1; i >= 0; i--) //only for parents
		adjust(data, i, datanum);

	//extract item one by one
	for (i = right - 1; i >= 0; i--) {
		swap_heap(&data[0], &data[i + 1]); //move max to the end of array
		if (i == 0) break;
		adjust(data, 0, i + 1); //make new array for reduced array
	}
	/*********************************indexindexindex!!!!!*****************************************/
	return 1;
}


//no recursion since data will be too big!
int checkIfHeap(ELEMENT data[], int left, int right)
{
	int i, childStart, parent=0, bigChild;
	printf("CHECKING IF THIS IS HEAP\n");
	childStart = (right) / 2;
	for (i = childStart; i < right; i += 2) {
		if (ELEMENT_KEY(&data[i]) > ELEMENT_KEY(&data[i + 1]))	bigChild = i;
		else bigChild = i + 1;

		while (parent >= 1) {
			parent = (bigChild - 1) / 2;
			if (ELEMENT_KEY(&data[parent]) < ELEMENT_KEY(&data[bigChild])) {
				printf("parent in %d : %d vs child in %d: %d\n", parent, ELEMENT_KEY(&data[parent]), bigChild, ELEMENT_KEY(&data[bigChild]));
				return 0;
			}
			bigChild = parent;
		}

	}
	return 1;
}

void adjust(ELEMENT data[], int root, int n)
{
	int child, rootKey;
	rootKey = ELEMENT_KEY(&data[root]);
	ELEMENT temp;
	if (root == 0) child = 1;
	else child = 2 * root;
	substitute_heap(&temp, &data[root]);

	while (child < n) {
		if (child < n - 1 && ELEMENT_KEY(&data[child]) < ELEMENT_KEY(&data[child + 1])) child++;

		if (ELEMENT_KEY(&data[child]) < rootKey) break;
		else {
			substitute_heap(&data[child / 2], &data[child]);
			child *= 2;
		}
	}
	substitute_heap(&data[child / 2], &temp); //마지막 child *=2 해준것떄문에 해줘야.. 즉 *2 해주기전 child와 root바꾸는거 
											  //내린거 없으면 root에 그대로  temp 넣어주는 거고. 
}

void substitute_heap(ELEMENT *A, ELEMENT *B) {
	memcpy(A, B, sizeof(ELEMENT));
	// A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
}

void swap_heap(ELEMENT *A, ELEMENT *B)
{
	ELEMENT tmp;
	//return;
	memcpy(&tmp, A, sizeof(ELEMENT));
	memcpy(A, B, sizeof(ELEMENT));
	memcpy(B, &tmp, sizeof(ELEMENT));
	// tmp.key = A-> key; tmp.score = A->score; tmp.other = A->other; strcpy(tmp.name, A->name);
	// A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
	// B->key = tmp.key; B->score = tmp.score; B->other = tmp.other; strcpy(B->name, tmp.name);
}

/*
void makeHeap(ELEMENT data[], int root, int n)
{
int i;
for( i = root; i <= n ; i++){
insertMaxHeap(data, &data[i], &i);
}
return;
}

void insertMaxHeap(ELEMENT data[], ELEMENT *elem, int *n)
{
int i, cur, curkey;
ELEMENT tmp;
if(*n == 0) substitute_heap(&data[0], elem);
//for(i = 0 ; i < *n ; i++){
cur = *n;
substitute_heap(&tmp, &data[cur]);
curkey = ELEMENT_KEY(&tmp);
while(curkey > ELEMENT_KEY(&data[cur/2]) && cur != 0){
substitute_heap(&data[cur], &data[cur/2]);
cur = cur/2;
}
substitute_heap(&data[cur], &tmp);
//}

}

ELEMENT * deleteMaxHeap(ELEMENT data[], int *n)
{
ELEMENT maxElem = data[0];

}
*/

//makeheap debugging
// ELEMENT *ptr = data;
// int idx=0, quad=1;
// while(idx <= right){
// 	fprintf(stdout, "%d: %11u", idx, ELEMENT_KEY(ptr));
// 	idx++; ptr++;
// 	if(idx == quad){
// 		quad *= 2;
// 		printf("\n");
// 	}

// }
// fprintf(stdout, "\n");