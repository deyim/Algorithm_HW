#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_types.h"
void swap_sel(ELEMENT *A, ELEMENT *B);
void substitute_sel(ELEMENT *A, ELEMENT *B);
int SELECT(ELEMENT data[], int k, int elemCnt);



//k = kth index!!
int SELECTION_REC(ELEMENT data[], int left, int right, int k, int *index) {
	
	//ELEMENT checking[right-left+1];
	// ELEMENT *checking;
	ELEMENT *data_copy;
	int target;

	data_copy = (ELEMENT*)malloc(sizeof(ELEMENT)*(right-left+1));
	//checking = (ELEMENT*)malloc(sizeof(ELEMENT)*(right-left+1));

	//int findingIDX = k-1;
	memcpy(data_copy, data+left, sizeof(ELEMENT)*(right-left+1));
	/*********************************data+left index!!!!!!**********************************************************/

	//memcpy(checking, data, sizeof(ELEMENT)*(right-left+1));
	
	//selection recursion
	target = SELECT(data_copy, k-1, right-left+1);
	// printf("1111target: %d index: %d\n", target, *index);



	//finding target index
	for(int i = left; i <= right ; i++){
		if(ELEMENT_KEY(&data[i]) == target){
			*index = i;
		}
	}

	free(data_copy);

	return 0;
}

int SELECT(ELEMENT data[], int k, int elemCnt)
{
	ELEMENT *data_copy, *data_copy2, *medians;
	data_copy = (ELEMENT*)malloc(sizeof(ELEMENT)*(elemCnt));
	data_copy2 = (ELEMENT*)malloc(sizeof(ELEMENT)*(elemCnt));
	medians = (ELEMENT*)malloc(sizeof(ELEMENT)*(elemCnt/5));

	ELEMENT *S1, *S3;
	
	int median;
	memcpy(data_copy, data, sizeof(ELEMENT)*(elemCnt));
	memcpy(data_copy2, data, sizeof(ELEMENT)*(elemCnt));

	//element number less than 50
	if(elemCnt<=7){
		if(elemCnt==1) return ELEMENT_KEY(&data[0]);
		 INSERTION_SORT(data, 0, elemCnt-1);
		 free(data_copy); 
		 free(data_copy2); 
		 free(medians);
		return ELEMENT_KEY(&data[k]);	
	}
	else{
		//printf("dubefsdf\n");
		int median_idx=0;
		for(int i = 0; i<elemCnt; i+=5){
			if(i+4 >= elemCnt) break;			
			INSERTION_SORT(data_copy, i, i+4);
			substitute_sel(&medians[median_idx++], &data_copy[i+2]);
		}
		int m;
		
		median = SELECT(medians, (median_idx-1)/2, median_idx);
		for(int i = 0 ; i< elemCnt ; i++){
			if(ELEMENT_KEY(&data[i]) == median){
				m = i;
			}
		}

		int s1=0, s2=0, s3=0;
		int leftidx=0, rightidx=elemCnt-1;
		for(int i = 0 ; i<=elemCnt-1 ; i++){
			if(ELEMENT_KEY(&data_copy2[i]) < median ){
				substitute_sel(&data[leftidx++], &data_copy2[i]);				
				s1++;
			}
			else if(ELEMENT_KEY(&data_copy2[i]) > median ){ 
				substitute_sel(&data[rightidx--], &data_copy2[i]);				
				s3++;
			}
			else{
				s2++;				
			}

		}
		// substitute_sel(&data[leftidx], &data_copy2[m]);
		for(int i = leftidx ; i <= rightidx ; i++)
			substitute_sel(&data[i], &data_copy2[m]);

		if(s1-1>=k){
			S1 = (ELEMENT*)malloc(sizeof(ELEMENT)*(s1));
			memcpy(S1, data, sizeof(ELEMENT)*(s1));

			return SELECT(S1, k, elemCnt-s2-s3);
		}
		else{
			if(s1+s2>=k){
				free(data_copy); 
				free(data_copy2); 
				free(medians);
				return median;
			}
			else{
				S3 = (ELEMENT*)malloc(sizeof(ELEMENT)*(elemCnt-s1-s2));
				memcpy(S3, data+s1+s2, sizeof(ELEMENT)*(elemCnt - s1-s2));
				return SELECT(S3, k-s1-s2, elemCnt-s1-s2);
			}
		}
	}
	
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