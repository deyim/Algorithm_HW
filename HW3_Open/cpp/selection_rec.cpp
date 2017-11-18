#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_types.h"
void swap_sel(ELEMENT *A, ELEMENT *B);
void substitute_sel(ELEMENT *A, ELEMENT *B);
int SELECT(ELEMENT data[], int k, int elemCnt);

int recursing = 0;

//k = kth index!!
int SELECTION_REC(ELEMENT data[], int left, int right, int k, int *index) {
	
	ELEMENT checking[right-left+1];
	ELEMENT data_copy[right-left+1];
	int target;

	//int findingIDX = k-1;

	memcpy(data_copy, data, sizeof(ELEMENT)*(right-left+1));
	memcpy(checking, data, sizeof(ELEMENT)*(right-left+1));


	//for check
	INSERTION_SORT(checking, left, right);
	printf("REAL finding %d idx Element: %d\n", k, ELEMENT_KEY(&checking[k]));
	

	//selection recursion
	target = SELECT(data_copy, k-1, right-left+1);
	printf("AFTER SELECT function target: %d\n", target);


	//finding target index
	for(int i = left; i <= right ; i++)
		if(ELEMENT_KEY(&data[i]) == target){
				*index = i;
				printf("index: %d\n",i);
			}


    //print result
	printf("kth element: %d in index %d\n\n", target, *index);

	return 1;
}

int SELECT(ELEMENT data[], int k, int elemCnt)
{
	ELEMENT data_copy[elemCnt];
	ELEMENT data_copy2[elemCnt];
	ELEMENT medians[elemCnt/5];

	ELEMENT *S1, *S3;
	
	int median;
	recursing++;
	printf("\n\nIN %dth RECURSION\n", recursing);
	printf("finding %d\n", k);
	memcpy(data_copy, data, sizeof(ELEMENT)*(elemCnt));
	memcpy(data_copy2, data, sizeof(ELEMENT)*(elemCnt));

	ELEMENT *ptr = data;
	for (int i = 0; i < elemCnt; i++, ptr++)
		fprintf(stdout, "  i = %6d: (%11u)\n", i, ELEMENT_KEY(ptr));
	fprintf(stdout, "\n");

	//element number less than 50
	if(elemCnt<7){
		if(elemCnt==1) return ELEMENT_KEY(&data[0]);
		 INSERTION_SORT(data, 0, elemCnt-1);
		 printf("AFTER INSERTION\n");
		 ptr = data;
		 printf("returning k = %dth %d\n", k, ELEMENT_KEY(&data[k]));
		return ELEMENT_KEY(&data[k]);	
	}
	else{
		printf("bigger than 7 \n");

		int median_idx=0;
		for(int i = 0; i<elemCnt; i+=5){
			if(i+4 >= elemCnt) break;			
			INSERTION_SORT(data_copy, i, i+4);
			substitute_sel(&medians[median_idx++], &data_copy[i+2]);
		}
		int m;
		
		printf("MEDIAN SEARCHING\n");
		median = SELECT(medians, (median_idx-1)/2, median_idx);
		printf("MEDIAN SEARCHING OVER\n");
		recursing--;
		printf("\n\nIN %dth RECURSION\n", recursing);
		for(int i = 0 ; i< elemCnt ; i++){
			if(ELEMENT_KEY(&data[i]) == median){
				m = i;
			}
		}
		printf("median: %d in index %d\n", median, m);

		int s1=0, s2=0, s3=0;
		int leftidx=0, rightidx=elemCnt-1;
		printf("\npartitioning...\n");
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

		ptr = data;
		for (int i = 0; i < elemCnt; i++, ptr++)
			fprintf(stdout, "  i = %6d: (%11u)\n", i, ELEMENT_KEY(ptr));
		fprintf(stdout, "\n");

		printf("s1: %d, s2: %d, s3: %d\n", s1, s2, s3);
		printf("k: %d\n",k);
		if(s1>k){
			S1 = (ELEMENT*)malloc(sizeof(ELEMENT)*(s1));
			memcpy(S1, data, sizeof(ELEMENT)*(s1));
			ptr = data;
			for (int i = 0; i < s1; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u)\n", i, ELEMENT_KEY(ptr));
			fprintf(stdout, "\n");

			return SELECT(S1, k, elemCnt-s2-s3);
		}
		else{
			if(s1+s2>=k) return median;
			else{
				ptr = data+(s1+s2);
				S3 = (ELEMENT*)malloc(sizeof(ELEMENT)*(elemCnt-s1-s2));
				memcpy(S3, ptr, sizeof(ELEMENT)*(elemCnt - s1-s2));
				printf("should return %d th element\n", k-s1-s2-1);
				for (int i = 0; i < elemCnt-s1-s2; i++, ptr++)
					fprintf(stdout, "  i = %6d: (%11u)\n", i, ELEMENT_KEY(ptr));
				fprintf(stdout, "\n");
				return SELECT(data+(s1+s2), k-s1-s2+1, elemCnt-s1-s2);
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