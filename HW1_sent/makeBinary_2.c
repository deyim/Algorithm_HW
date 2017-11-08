#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	
	char name[20], space[1]=" ", filename[30] = "./Data_B/", *tmp;
	int cnt=10, binaryNum, numbers[10] = {1,5,4,8,10,2,6,9,3,7};
	FILE *fp;

	fp = fopen("./Data_B/IC.input",  "wb");
	fwrite(&cnt, sizeof(int), 1, fp);
	fwrite(numbers,sizeof(int),cnt,fp);
	printf("%s file was made. \n", filename);
	fclose(fp);
	
	return 0;
}

/*
int main(){
	
	char name[20], space[1]=" ", filename[30] = "./Data_B/", *tmp;
	int cnt, binaryNum, *numbers;
	FILE *fp;
	srand(time(NULL));
	
	while(1){
		strcpy(filename, "./Data_B/");
		scanf("%s %d", name, &cnt);
		tmp = strcat(filename, name);
		fp = fopen(filename, "wb");
		fwrite(&cnt, sizeof(int), 1, fp);
		numbers = (int*)malloc(sizeof(int)*cnt);
		for(int i = 0 ; i < cnt ; i++){
			numbers[i] = rand()%2000-1000;
		}
		fwrite(numbers,sizeof(int),cnt,fp);
		printf("%s file was made. \n", filename);
		fclose(fp);
	}
	
	return 0;
}
*/

// IC.input 20
