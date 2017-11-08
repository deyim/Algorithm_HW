#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <string.h>
#include <cstring>
using namespace std;
//int buffer[1000000];

void IC(char [], char []);
long long merge_sort(int *buffer, int *numbers, long long left, long long right);
long long merge(int *buffer, int *numbers, long long left, long long middle, long long right);

int main(){
	char *onetmp, oneLine[40], input[25], output[35];
	FILE *fp;
	fp = fopen("Data_B/HW1_IC_config.txt", "r");
	
	while((onetmp = fgets(oneLine, sizeof(oneLine), fp)) != NULL){
		sscanf(oneLine, "%s %s", input, output);
		char inputFile[40] = "./Data_B/"; strcat(inputFile, input);
		char outputFile[40] = "./Data_B/"; strcat(outputFile, output);
		IC(inputFile, outputFile);
	}
	
	fclose(fp);
	return 0;
}

void IC(char input[], char output[]){
	FILE *fp_in, *fp_out;
	int *numbers, *buffer,  tmp;
	long long cnt, inver=0;
	double timer;
	
	printf("%s\n", input);
	if((fp_in = fopen(input, "rb")) != NULL){
		fread(&cnt, sizeof(int), 1, fp_in);
		printf("%lld\n", cnt);
		numbers = (int*)malloc(sizeof(int)*cnt);
		buffer = (int*)malloc(sizeof(int)*cnt);
		tmp = fread(numbers, 4, cnt, fp_in);
	}
	else fprintf(stderr, "file open error   ");
	fclose(fp_in);
	
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	inver = merge_sort(buffer, numbers, 0, cnt-1);
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
	timer = sec.count()*1000;
	printf("time: %.3lf\n", timer);
	
	fp_out = fopen(output, "w");
	fprintf(fp_out, "%lld\n%lld\n", cnt, inver);
	printf("%lld\n%lld\n", cnt, inver);
	fclose(fp_out);
}

long long merge_sort(int *buffer, int *numbers, long long left, long long right){
	long long middle, inverL=0, inverR=0, inverC=0;
	middle = (left+right)/2;
	
	if(left < right){
		inverL = merge_sort(buffer, numbers, left, middle);
		inverR = merge_sort(buffer, numbers, middle+1, right);
		inverC = merge(buffer, numbers, left, middle, right);
	}
	return  inverL + inverR + inverC;
}

long long merge(int *buffer, int *numbers, long long left, long long middle, long long right){
	long long i, i_left, i_right;
	long long inver=0;
	
	for(int j = left ; j <= right ; j++) buffer[j] = numbers[j];
	//memcpy(buffer + left, numbers + left, sizeof(long long)*(right - left + 1));
	i_left = left;
	i_right = middle + 1;
	i = left;

	while ((i_left <= middle) && (i_right <= right)) {
		if (buffer[i_left] < buffer[i_right]){
			numbers[i++] = buffer[i_left++];
		}
		else{
			inver += middle-i_left+1;
			numbers[i++] = buffer[i_right++];
		}
	}
	while (i_left <= middle) numbers[i++] = buffer[i_left++];
	while (i_right <= right) numbers[i++] = buffer[i_right++];
	
	return inver;
}















