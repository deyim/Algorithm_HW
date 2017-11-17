#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_types.h"
void swap_sel(ELEMENT *A, ELEMENT *B);
void substitute_sel(ELEMENT *A, ELEMENT *B);

int SELECTION_REC(ELEMENT data[], int left, int right, int k, int *index) {
	
	ELEMENT data_copy[right-left+1];
	ELEMENT medians[(right-left+1)/5+1];
	
	int target;

	memcpy(data_copy, data, sizeof(ELEMENT)*(right-left+1));
	printf("\nselection rec start right %d left %d\n", right, left);
	//element number less than 50
	if(right-left<7){
		//QUICK_SORT(data_copy, left, right);
		INSERTION_SORT(data_copy, left, right);
		//QSORT(data, left, right);
		target = ELEMENT_KEY(&data_copy[k]);
		printf("right - left less than 7 \n");
		printf("%dth element %d\n", k, target);
		for(int i = left ; i<=right ; i++)
			if(ELEMENT_KEY(&data[i]) == target){
				*index = i;
				printf("index: %d\n",i);
			}
				
			
	}
	else{
		printf("right - left bigger than 7 \n");
		int median_idx=0;
		for(int i = 0; i<right; i+=5){
			if(i+4 > right) break;
			
			INSERTION_SORT(data_copy, i, i+4);
			printf("sorting..... %dth %d ?\n", i, ELEMENT_KEY(&data_copy[i+2]));
			substitute_sel(&medians[median_idx++], &data_copy[i+2]);
		}
		ELEMENT *ptr = medians;
		for (int i = 0; i < right/5; i++, ptr++)
			fprintf(stdout, "  i = %6d: (%11u)\n", i, ELEMENT_KEY(ptr));
		fprintf(stdout, "\n");

		int m;

		SELECTION_REC(medians, 0, median_idx-1, (median_idx-1)/2, &m);
		target = ELEMENT_KEY(&medians[m]);
		for(int i = left ; i<=right ; i++)
			if(ELEMENT_KEY(&data[i]) == target){
				*index = i;
				printf("index: %d\n",i);
			}
		printf("median: %d\n", *index);

		int s1=0, s2=0, s3=0;
		int leftidx=left, rightidx=right;
		int median = ELEMENT_KEY(&data[m]);
		printf("partitioning...\n");
		for(int i = left ; i<=right ; i++){
			if(ELEMENT_KEY(&data_copy[i]) < median){
				swap_sel(&data_copy[leftidx++], &data_copy[i]);
				s1++;
			}
			else if(ELEMENT_KEY(&data_copy[i]) > median){ 
				swap_sel(&data_copy[rightidx--], &data_copy[i]);
				s3++;
			}
			else{
				s2++;				
			}

		}

		// ptr = data;
		// for (int i = 0; i < 32; i++, ptr++)
		// 	fprintf(stdout, "  i = %6d: (%11u)\n", i, ELEMENT_KEY(ptr));
		// fprintf(stdout, "\n");

		printf("s1: %d, s2: %d, s3: %d\n", s1, s2, s3);

		if(s1>=k){
			printf("s1!!\n");
			SELECTION_REC(data, 0, s1, k, index);
		}
		else{
			if(s1+s2>=k) *index = m;
			else{
				printf("s3!!!\n");
				SELECTION_REC(data, 0, s3, k-s1-s2, index);
			}
		}
	}



	return 1;
}

void substitute_sel(ELEMENT *A, ELEMENT *B){
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
}

void swap_sel(ELEMENT *A, ELEMENT *B)
{
	ELEMENT tmp;
	//return;
	tmp.key = A-> key; tmp.score = A->score; tmp.other = A->other; strcpy(tmp.name, A->name);
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
	B->key = tmp.key; B->score = tmp.score; B->other = tmp.other; strcpy(B->name, tmp.name);
}