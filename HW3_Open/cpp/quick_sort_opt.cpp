#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_types.h"
#define substitute(A,B) memcpy(A, B, sizeof(ELEMENT));
#define swap(A,B,tmp) { memcpy(&tmp, A, sizeof(ELEMENT)); memcpy(A, B, sizeof(ELEMENT)); memcpy(B, &tmp, sizeof(ELEMENT));}

void swap_quick_opt(ELEMENT *A, ELEMENT *B);
void substitute_quick_opt(ELEMENT *A, ELEMENT *B);
int partition_opt(ELEMENT data[], int left, int right);
void quick_sort_opt_recur(ELEMENT data[], int left, int right, int elemCnt);


int QUICK_SORT_OPT(ELEMENT data[], int left, int right) {

	int elemCnt = (right - left + 1)*0.1;
	quick_sort_opt_recur(data, left, right, elemCnt);
	INSERTION_SORT(data, left, right);
	return 1;
}

void quick_sort_opt_recur(ELEMENT data[], int left, int right, int elemCnt)
{
	ELEMENT pivotElem;
	int pivot, pivotKey;
	int left1, right1, left2, right2, splitPoint;

	if (right - left <= 50) return;

	left2 = left; right2 = right;
	if (left < right) {
		while (right2 - left2 >= 1) {

			splitPoint = partition_opt(data, left2, right2);

			if (splitPoint < (left2 + right2) / 2)
			{
				left1 = left2; right1 = splitPoint - 1;
				left2 = splitPoint + 1;
			}
			else
			{
				left1 = splitPoint + 1; right1 = right2;
				right2 = splitPoint - 1;
			}

			quick_sort_opt_recur(data, left1, right1,elemCnt);
		}
	}

	return;
}

int partition_opt(ELEMENT data[], int left, int right)
{
	int a, b, c, pivot, rightKey;
	int akey, bkey, ckey;
	ELEMENT tmp;

	a = left; b = (left + right) / 2; c = right;
	akey = ELEMENT_KEY(&data[a]); bkey = ELEMENT_KEY(&data[b]); ckey = ELEMENT_KEY(&data[c]);
	if ((akey >= bkey && bkey >= ckey) || (ckey >= bkey && bkey >= akey)) pivot = b;
	else if ((bkey >= akey && akey >= ckey) || (ckey >= akey && akey >= bkey)) pivot = a;
	else pivot = c;

	//swap_quick_opt(&data[right], &data[pivot]);
	memcpy(&tmp, &data[right], sizeof(ELEMENT));
	memcpy(&data[right], &data[pivot], sizeof(ELEMENT));
	memcpy(&data[pivot], &tmp, sizeof(ELEMENT));

	pivot = left;
	rightKey = ELEMENT_KEY(&data[right]);
	for (int i = left; i < right; i++) {
		if (ELEMENT_KEY(&data[i]) < rightKey) {
			//swap_quick_opt(&data[i], &data[pivot]);
			memcpy(&tmp, &data[i], sizeof(ELEMENT));
			memcpy(&data[i], &data[pivot], sizeof(ELEMENT));
			memcpy(&data[pivot], &tmp, sizeof(ELEMENT));
			pivot++;
		}
	}
	memcpy(&tmp, &data[right], sizeof(ELEMENT));
	memcpy(&data[right], &data[pivot], sizeof(ELEMENT));
	memcpy(&data[pivot], &tmp, sizeof(ELEMENT));
	//swap_quick_opt(&data[right], &data[pivot]);

	return pivot;
}


void swap_quick_opt(ELEMENT *A, ELEMENT *B)
{
	ELEMENT tmp;
	//return;
	memcpy(&tmp, A, sizeof(ELEMENT));
	memcpy(A, B, sizeof(ELEMENT));
	memcpy(B, &tmp, sizeof(ELEMENT));
}

void substitute_quick_opt(ELEMENT *A, ELEMENT *B) {
	memcpy(A, B, sizeof(ELEMENT));
}




/*
void swap_quick_opt(ELEMENT *A, ELEMENT *B);
void substitute_quick_opt(ELEMENT *A, ELEMENT *B);
int partition_opt(ELEMENT data[], int left, int right, int medIdx);


use selection sort and insertion sort to optimize quick sort


int QUICK_SORT_OPT(ELEMENT data[], int left, int right) {

	 int elemCnt, pivot, selOk, medIdx1, medIdx2, medIdx;
	 int left1, right1, left2, right2, splitPoint;
	ELEMENT pivotElem;
	elemCnt = right - left + 1;
	left2 = left; right2 = right;

	// insertion sort for base case
	if (elemCnt <= 20) { 
		INSERTION_SORT(data, left, right);
	}
	// selection recursion to find median
//	else if (right - left>0) {
	//while (right2 - left2 > 20) {
	if (right - left>0) {
		while (right2 - left2 > 1) {
			printf("left2: %d, right2: %d\n", left2, right2);
			pivotElem = data[left];
			pivot = pivotElem.key;
			//selOk = SELECTION_REC(data, left, right, elemCnt / 2, &medIdx);
			// divide using the found median
			elemCnt = right2 - left2 + 1;
			

			//do {
				medIdx1 = (unsigned int)((((float)rand()) / RAND_MAX) * (float)(elemCnt));
				medIdx1 += left;
				medIdx2 = (unsigned int)((((float)rand()) / RAND_MAX)  * (float)(elemCnt));
				medIdx2 += left;
				if (data[medIdx1].key > data[medIdx2].key) medIdx = medIdx1;
				else medIdx = medIdx2;
				printf("medIdx: %d\n", medIdx);
				splitPoint = partition_opt(data, left, right, medIdx);
		//	}
			//while (splitPoint == 0);
			printf("splitPoint: %d\n", splitPoint);



			substitute_quick_opt(&data[splitPoint],& pivotElem);

			if (splitPoint < (left2 + right2) / 2)
			{
				left1 = left2; right1 = splitPoint - 1;
				left2 = splitPoint + 1;
				printf("left1 %d right1 %d left2 %d right2 %d\n", left1, right1, left2, right2);
			}
			else 
			{
				left1 = splitPoint + 1; right1 = right2;
				right2 = splitPoint - 1;
				printf("left1 %d right1 %d left2 %d right2 %d\n", left1, right1, left2, right2);
			}

			
			if (right1-left1 <= 10) {
				printf("insertion sort\n\n");
				INSERTION_SORT(data, left1, right1);
			}
			else {
				printf("quick sort\n\n");
				QUICK_SORT_OPT(data, left1, right1);
			}
			// recursion
			//QUICK_SORT_OPT(data, left, pivot - 1);
			//QUICK_SORT_OPT(data, pivot + 1, right);
		}
	}
	return 1;
}

int partition_opt(ELEMENT data[], int left, int right, int medIdx)
{
	int pivot;

	swap_quick_opt(&data[right], &data[medIdx]);
	pivot = left;
	for (int i = left; i < right; i++) {
		if (ELEMENT_KEY(&data[i]) < ELEMENT_KEY(&data[right])) {
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
	memcpy(&tmp, A, sizeof(ELEMENT));
	memcpy(A, B, sizeof(ELEMENT));
	memcpy(B, &tmp, sizeof(ELEMENT));
}
void substitute_quick_opt(ELEMENT *A, ELEMENT *B) {
	memcpy(A, B, sizeof(ELEMENT));
}

*/