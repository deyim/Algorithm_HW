#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



void longestPalindrome();
void partitionPalindrome();
void intervalPartition();

int main(){

	//longestPalindrome();
    partitionPalindrome();
	intervalPartition();
	return 0;
}

void longestPalindrome()
{

	int tc, length;
	int i,j, L, longest;
	char *origin, **palin, *output;
	bool *mark;
	int **check;
	FILE *fp = fopen("input-3-1.txt", "r");
	FILE *out = fopen("output-3-1.txt", "w");
	fscanf(fp,"%d\n", &tc);
	fprintf(out, "%d\n", tc);

	while(tc--)
	{
		fscanf(fp, "%d\n", &length);
		origin = new char[length];
		output = new char[length];
		palin = new char*[length];
		mark = new bool[length];
		check = new int*[length];
		string toPrint;
		fscanf(fp, "%s\n", origin);
		string rever = string(origin);
		reverse(rever.begin(), rever.end());

		for(i = 0 ; i < length; i++){
			palin[i] = new char[length];
			check[i] = new int[length];
			palin[i][i] = 1;
		}
		
		//subproblems
		for(L = 2 ; L <= length; L++){
			for(i = 0 ; i < length-L+1; i++)
			{
				j = L + i -1;
					//check these cases in order 1,2,3,4
				if(origin[i] != origin[j]){
					palin[i][j] = max(palin[i+1][j], palin[i][j-1]);
					if(palin[i+1][j] > palin[i][j-1]) check[i][j] = 1;//ㅜ
					else check[i][j] = 2; //<-
				}
				else{
					if(j == i+1){
						palin[i][j] = 2;
						check[i][j] = 3;
					}
					else{
						palin[i][j] = palin[i+1][j-1] + 2;
						check[i][j] = 4;//대각선
					}
				}
			//	}
			}
		}

		longest = palin[0][length-1];
		printf("longest subsequence : %d\n", longest);


//*****************************print subsequence!!!

		i = 0; j = length-1;
		
		while(longest){
			if(i==j){
				mark[i] = true;
				longest--;
			}
			else
			{
				int which = check[i][j];
				switch(which){
					case 1:
						i = i+1;
						break;
					case 2:
						j = j-1;
						break;
					case 3:
						mark[i] = true;
						mark[j] = true;
						longest -= 2;
					case 4:
						mark[i++] = true;
						mark[j--] = true;
						longest -= 2;
						break;
				}
			}
			if(longest<0) break;
		}
		for(int i = 0 ; i < length; i++){
			if(mark[i]) toPrint += origin[i];
		}
		printf("%s\n", toPrint.c_str());
		fprintf(out, "%s\n", output);
		free(output);
		free(mark);
		free(origin);

		for(int i = 0 ; i < length; i++){
			free(palin[i]);
			free(check[i]);
		}
		free(palin); free(check);
	}
	fclose(fp);
	fclose(out);
	return;
}

void partitionPalindrome()
{
	int tc, length, idx=0, minidx;
	int i, j, k, L, longest;

	int **C;
	char *input, *output;
	bool **P, *check;
	//bool **P, **check;

	FILE *fp = fopen("input-3-2.txt", "r");
	FILE *out = fopen("output-3-2.txt", "w");
	fscanf(fp,"%d\n", &tc);
	fprintf(out, "%d\n", tc);

	while(tc--){
		fscanf(fp, "%d\n", &length);
		
		//allocation
		idx = 0;
		input = new char[length];
		
		P = new bool*[length];
		C = new int*[length];
		check = new bool[length];
		for(i = 0 ; i < length; i++){
			P[i] = new bool[length];
			C[i] = new int[length];
			//check[i] = new int[length];
		}

		fscanf(fp, "%s\n", input);

		//initialization
		for( i = 0 ; i < length ; i++){
			P[i][i] = 1; C[i][i] = 1;
		}

		//Dynamic Programming
		for(L = 2 ; L <= length ; L++){
			for(i = 0 ; i < length-L+1 ; i++){
				
				j = L+i-1;

				if(L == 2)
				{
					if(input[i]==input[j])
						P[i][j] = true;
					else
						P[i][j] = false;
				}
				else
					P[i][j] = (input[i] == input[j]) && P[i+1][j-1];
				//1,2 -> 2,1 이되네... 2,1 -> 
				
				if(P[i][j])
					C[i][j] = 1;
				else{
					C[i][j] = 10000;
					for(k = i ; k < j ; k++){//0 1 2 4 / 0 2 2 4 / 0 3 3 4 /
						if(C[i][j] != min(C[i][j], C[i][k] + C[k+1][j])){
							C[i][j] = min(C[i][j], C[i][k] + C[k+1][j]);
							minidx = k;
						}
						printf("minidx: %d\n", minidx);
						//check[k] = true;
						//check[i][k] check[k+1][j]
					}
				}
			}
		}

		for(i = 0 ; i < length ; i++){
			if(output[i] == true)
				printf("i: %d\n", i);
		}

		for(i = 0 ; i < length ; i ++){
			if(check[i] == true){
				output = new char[length];
				strncpy(output, &input[minidx], i-idx+1);
				printf("%s\n", output);
				fprintf(out, "%s\n", output);
				free(output);
			}
			
		}

		printf("number of cuts: %d\n", C[0][length-1]);

		//deallocation
		free(input);
		for(i = 0 ; i < length ; i++){
			free(P[i]); free(C[i]);
		}
		free(P); free(C);

	}


	fclose(fp);
	fclose(out);
	return;
}

void intervalPartition()
{
	;
}