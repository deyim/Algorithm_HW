#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>

//#define CHECK_GENERATED_DATA

//#define N_ELEMENTS 1048576	// 2^20
//#define N_ELEMENTS 1024		// 2^10
#define N_ELEMENTS 4194304		// 2^5

#define FILE_NAME_PREFIX  "SWAP"
//1024, 4096, 16384, 65536, 262144, 1048576, 2097152, 4194304

typedef struct {
	unsigned int key; float score; double other; char name[16];
} ELEMENT;
#define ELEMENT_KEY(x) ((x)->key)
void swap_data(ELEMENT *A, ELEMENT *B);

int main() {
	unsigned scale_factor_uint = UINT_MAX >> 2;
	float scale_factor_flt = 90.0f, sqrtn;

	int n, randI, randJ;
	char file_name[32];
	FILE *fp;

	ELEMENT *data, element;

	n = N_ELEMENTS; // n is the number of data elements to be written
	sqrtn = sqrt(n);
	data = (ELEMENT*)malloc(sizeof(ELEMENT)*n);
	sprintf(file_name, "%s_%d.binary", FILE_NAME_PREFIX, n);

	fprintf(stdout, "^^^ UNIT_MAX = %u\n", UINT_MAX);
	fprintf(stdout, "^^^ RAND_MAX = %u\n\n", RAND_MAX);

	if ((fp = fopen(file_name, "wb")) == NULL) {
		fprintf(stderr, "Error: cannot open the binary file %s for writing...\n", file_name);
		exit(-1);
	}

	fwrite(&n, sizeof(int), 1, fp);
	srand((int)time(NULL));

	for (int i = 0; i < n; i++) {
		//
		// For more efficient read/write operations, use a buffer of proper size!!!
		//
		data[i].key = i;
		data[i].score = ((float)rand()) / RAND_MAX * scale_factor_flt + 10.0f;
		data[i].other = 3.141592653589793; // dummy value
		strcpy(data[i].name, "abcdefghijklmno");  // dummy value


	}

	for(int i = 0 ; i < sqrtn ; i++){
		randI = (unsigned int)((((float)rand()) / RAND_MAX) * (float)n);
		//randI has to be between i-4 and i+4 == i-3 ~ i+3
		//has to be bigger than 0
		if(randI >= sqrtn){
			do 
				randJ = (unsigned int)((((float)rand()) / RAND_MAX) * sqrtn + ((float)(randI)-sqrtn));
			while(randI == randJ);
		}
		else{
			do
				randJ = (unsigned int)((((float)rand()) / RAND_MAX) * ((float)(randI)+sqrtn));
			while(randI == randJ);
		}
		
		printf("change randI %d and randJ %d \n", randI, randJ);
		swap_data(&data[randI], &data[randJ]);
	}

	for(int i = 0 ; i < n ; i++) 		
		fwrite(&data[i], sizeof(ELEMENT), 1, fp);


	fclose(fp);

#ifdef CHECK_GENERATED_DATA
	if ((fp = fopen(file_name, "rb")) == NULL) {
		fprintf(stderr, "Error: can not open the binary file %s for reading...\n", file_name);
		exit(-1);
	}
	fread(&n, sizeof(int), 1, fp);
	fprintf(stdout, "*** Number of elements = %d\n", n);

	for (int i = 0; i < n; i++) {
		fread(&element, sizeof(ELEMENT), 1, fp);
		fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(&element), element.score, element.other, element.name);
	}
	fclose(fp);
	return 0;
#endif
}

void swap_data(ELEMENT *A, ELEMENT *B)
{
	ELEMENT tmp;
	//return;
	tmp.key = A-> key; tmp.score = A->score; tmp.other = A->other; strcpy(tmp.name, A->name);
	A->key = B-> key; A->score = B->score; A->other = B->other; strcpy(A->name, B->name);
	B->key = tmp.key; B->score = tmp.score; B->other = tmp.other; strcpy(B->name, tmp.name);
}
