#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <string.h>
using namespace std;
using namespace chrono;


void MSS(char *, char *, char*);
int* A1(int *, int );
int* A2(int *, int );
int* A3(int *, int );
void MSS(char input[], char output[], char funcArr[]);
int* DNCMSS(int *numbers, int, int);
int maxof3(int a, int b, int c){
	if(a>=b && b>=c)  return a;
	else if(b>=a && b>=c) return b;
	else return c;
}

int main(){

	char *onetmp, oneLine[50], input[15], output[25], func[5];
	FILE *fp;
	//fp = fopen("Data_A/HW1_MSS_config.txt", "r");
	fp = fopen("Data_A/HW1_MSS_config_2.txt", "r");
	
	while((onetmp = fgets(oneLine, sizeof(oneLine), fp)) != NULL){
		sscanf(oneLine, "%s %s %s", input, output, func);
		char inputFile[20] = "./Data_A/"; strcat(inputFile, input);
		char outputFile[30] = "./Data_A/"; strcat(outputFile, output);
		MSS(inputFile, outputFile, func);
	}
	
	fclose(fp);
	return 0;
}


void MSS(char input[], char output[], char funcArr[]){
	FILE *fp_in, *fp_out;
	int cnt, *numbers, func, *infos, tmp; //infos has MSS, head and tail
	double timer, timer2;
	
	//get numbers from input file
	if((fp_in = fopen(input, "rb")) != NULL){
		fread(&cnt, sizeof(int), 1, fp_in);
		printf("filename: %s", input);
		printf("\tcnt: %d", cnt);
		numbers = (int*)malloc(sizeof(int)*cnt);
		tmp = fread(numbers, sizeof(int), cnt, fp_in);
		fclose(fp_in);
	}
	else fprintf(stderr, "file open error");

	//run algorithm
	
	
	system_clock::time_point start = std::chrono::system_clock::now();
	if(strcmp(funcArr, "A1")==0){
		func = 1;
		infos = A1(numbers, cnt);
	}
	else if(strcmp(funcArr, "A2")==0){
		func = 2;
   	infos = A2(numbers, cnt);
	}
	else if(strcmp(funcArr, "A3")==0){
		func = 3;
		infos = A3(numbers, cnt);
	}
	system_clock::time_point end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> sec = end-start;
	timer = sec.count()*1000;
	printf("\tused function: %d", func);
	printf("\ttime: %.3lf \n", timer);
	
	//write file
	fp_out = fopen(output, "w");
	fprintf(fp_out, "%d\n%d\n%d\n%d %d\n%.3lf", cnt, func, infos[0], infos[1], infos[2], timer);
	fclose(fp_out);
	
	return;
}


/************function A1****************
			 time complexity: O(n^2)
			 description: Improved brute force
 *****************************************/

int* A1(int *numbers, int cnt){
	int MSS=0, head=0, tail, sum, headTmp;
	int *infos = (int*)malloc(sizeof(int)*3);

	//find MSS
	for(int i = 0 ; i < cnt ; i++){
		sum = 0; headTmp=i;
		for(int j = i ; j < cnt; j++){
			sum += numbers[j];
			if(MSS < sum){
				MSS = sum; tail = j; head=headTmp;
			}
		}
	}
		
	infos[0] = MSS;
	infos[1] = head;
	infos[2] = tail;
	
	return infos;
	
}

/************function A2****************
			 time complexity: O(nlogn)
			 description: Divide and Conquer
 *****************************************/
int *A2(int *numbers, int cnt){
	int *infos;
	infos = DNCMSS(numbers, 0, cnt);
	
	return infos;
}

int* DNCMSS(int *numbers, int left, int right){
	int MSS;
	int *infoRight, *infoLeft, *infoCenter, *infoCur;
	int center;
	
	center = (left+right)/2;
	infoCur = (int*)malloc(sizeof(int) * 4);
	
	if(center - left == 0){
		if(numbers[left] > 0){
			for(int i = 0 ; i < 3 ; i++) infoCur[i] = numbers[center];
			return infoCur;
		}
		else{
			for(int i = 0 ; i < 3 ; i++) infoCur[i] = 0;
			return infoCur;
		}
	}
	
	infoRight = DNCMSS(numbers, left, center);
	infoLeft = DNCMSS(numbers, center+1, right);
	
	//Center sum
	infoCenter = (int*)malloc(sizeof(int) * 3);
	int leftMax=0, rightMax=0, sum=0;
	for(int i = center; i>=left ; i--){
		sum += numbers[i];
		if(leftMax < sum){
			leftMax = sum;
			infoCenter[1] = i;
		}
	}
	sum = 0;
	for(int i = center+1; i<=right; i++){
		sum += numbers[i];
		if(rightMax < sum){
			rightMax = sum;
			infoCenter[2] = i;
		}
	}
	infoCenter[0] = leftMax+ rightMax;
	
	
	if(infoRight[0] > infoLeft[0] && infoRight[0] > infoCenter[0]){
		infoCur = infoRight;
	}
	else if(infoLeft[0] > infoRight[0] && infoLeft[0] > infoCenter[0]){
		infoCur = infoLeft;
	}
	else{
		infoCur = infoCenter;
	}
	
	return infoCur;
}

/************function A3****************
		 time complexity: O(n)
		 description: Dynamic Programming
 *****************************************/
int *A3(int *numbers, int cnt){
	int *infos = (int*)malloc(sizeof(int)*3);
	int maxThis=0, maxSum=0;
	int head=0, tail, thisHead=0;
	
	
	for(int i = 0 ; i < cnt; i++){
		maxThis += numbers[i];
		if(maxThis > maxSum){
			maxSum = maxThis;
			tail = i;
			head = thisHead;
		}
		if(maxThis < 0){
			maxThis = 0;
			thisHead = i+1;
		}
	}
	
	infos[0] = maxSum;
	infos[1] = head;
	infos[2] = tail;
	
	return infos;
}








