#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	
	char name[20], space[1]=" ", filename[30] = "./Data_A/", *tmp;
	int cnt, binaryNum, *numbers;
	FILE *fp;
	srand(time(NULL));
	
	while(1){
		strcpy(filename, "./Data_A/");
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
