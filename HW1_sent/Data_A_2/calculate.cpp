#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	FILE *fp, *result;
	string filename = "MSS_00_00.output.txt";
	string input = "MSS_00.input";
	char *ch1, *ch2;
	double avg, timeSum, runtime;
	int inputSize, algo, MSS, head, tail;
	double times[25][3];
	
	result = fopen("cal_result2.txt", "w");
	for(int i = 0 ; i < 5;i++){
		filename[4] = i+48; 	input[4] = i+48;
		for(int j = 0 ;  j < 5 ; j++ ){
			filename[5] = j+48; input[5] = j+48;
			for(int k = 1; k <= 3; k++){
				filename[7] = k+48;
				timeSum = 0; avg = 0;
				for(int l = 1; l <= 5; l++){
					filename[8] = l+48;
					fp = fopen(filename.c_str(), "r");
					fscanf(fp, "%d\n%d\n%d\n%d %d\n%lf", &inputSize, &algo, &MSS, &head, &tail, &runtime);
					fclose(fp);
					timeSum += runtime;
				}
				avg = timeSum/5;
				times[i*5+j][k-1] = avg;
			}
			fprintf(result, "%s  %d\t", input.c_str(), inputSize);
			printf("%s   %d\t", input.c_str(), inputSize);
			fprintf(result, "%10lf   %10lf   %10lf\n", times[i*5+j][0], times[i*5+j][1], times[i*5+j][2]);
			printf("%10lf   %10lf   %10lf\n", times[i*5+j][0], times[i*5+j][1], times[i*5+j][2]);
		}
	}
	fclose(result);
	
	return 0;
}
