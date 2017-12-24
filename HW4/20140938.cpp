#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <direct.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int outputIdx = 0;
int **check;
char *input;

typedef struct room{
	int start;
	int finish;
};


void longestPalindrome();
void partitionPalindrome();
void intervalPartition();
void printpalins(char *palinstring[], int i, int j);

int main(){
	_mkdir("20140938_OUTPUT");
	longestPalindrome();
    partitionPalindrome();
	intervalPartition();
	return 0;
}

void longestPalindrome()
{

	int tc, length;
	int i,j, L, longest;
	char *origin=NULL;
	bool *mark=NULL;
	int **check=NULL, **palin=NULL;
	FILE *fp = fopen("INPUT/input-3-1.txt", "r");
	FILE *out = fopen("20140938_OUTPUT/output-3-1.txt", "w");
	fscanf(fp,"%d\n", &tc);
	fprintf(out, "%d\n", tc);

	while(tc--)
	{
		fscanf(fp, "%d\n", &length);
		origin = (char*)malloc(sizeof(char)*length);
		palin = (int**)malloc(sizeof(int*)*length);
		mark = (bool*)malloc(sizeof(bool)*length);
		check = (int**)malloc(sizeof(int*)*length);
		
		string toPrint;
		fscanf(fp, "%s\n", origin);
		string rever = string(origin);
		reverse(rever.begin(), rever.end());

		for(i = 0 ; i < length; i++){
			palin[i] = (int*)malloc(sizeof(int)*length);
			check[i] = (int*)malloc(sizeof(int)*length);
			memset(&palin[i][0], 0, sizeof(int)*length);
			memset(&check[i][0], 0, sizeof(int)*length);
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
					check[i][j] = 2;
					if(palin[i+1][j] > palin[i][j-1]) 
						check[i][j] = 1;//ㅜ
				//	else if(palin[i + 1][j] <= palin[i][j - 1])
					//	check[i][j] = 2; //<-
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
		fprintf(out, "%d\n", longest);


//*****************************print subsequence!!!

		i = 0; j = length-1;
		for (int i = 0; i < length; i++) {
			mark[i] = false;
		}
		
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
		fprintf(out, "%s\n", toPrint.c_str());

		
		for (int i = 0; i < length; i++) {
			free(palin[i]);
			free(check[i]);
		}
		free(palin); free(check); 
		free(mark);
		
		
	}

	fclose(fp);
	fclose(out);
	return;
}

void partitionPalindrome()
{
	int tc, length, idx=0, minidx, palins;
	int i, j, k, L, longest;

	int **C = NULL;
	char *output = NULL;
	char **palinstring = NULL;
	bool **P = NULL;

	FILE *fp = fopen("INPUT/input-3-2.txt", "r");
	FILE *out = fopen("20140938_OUTPUT/output-3-2.txt", "w");
	fscanf(fp,"%d\n", &tc);
	fprintf(out, "%d\n", tc);

	while(tc--){
		fscanf(fp, "%d\n", &length);
		
		//allocation
		idx = 0;
		outputIdx = 0;

		input = (char*)malloc(sizeof(char)*length);
		P = (bool**)malloc(sizeof(bool*)*length);
		C = (int**)malloc(sizeof(int*)*length);
		check = (int**)malloc(sizeof(int*)*length);
		palinstring = (char**)malloc(sizeof(char*)*length);
		for (i = 0; i < length; i++) {
			P[i] = (bool*)malloc(sizeof(bool)*length);
			C[i] = (int*)malloc(sizeof(int)*length);
			check[i] = (int*)malloc(sizeof(int)*length);
			palinstring[i] = (char*)malloc(sizeof(char)*length);
		}
		

		fscanf(fp, "%s\n", input);

		//initialization
		for( i = 0 ; i < length ; i++){
			P[i][i] = 1; C[i][i] = 1;
			check[i][i] = -1;
		}

		//Dynamic Programming
		for(L = 2 ; L <= length ; L++){
			for(i = 0 ; i < length-L+1 ; i++){
				
				j = L+i-1;

				if(L == 2)
				{
					if (input[i] == input[j]) {
						P[i][j] = true;
						C[i][j] = 1;
						check[i][j] = -1;
					}
					else {
						P[i][j] = false;
						C[i][j] = 2;
						check[i][j] = i;
					}
				}
				else {
					P[i][j] = (input[i] == input[j]) && P[i + 1][j - 1];

					if (P[i][j]) {
						C[i][j] = 1;
						check[i][j] = -1;
					}
					else {
						C[i][j] = 10000;
						for (k = i; k < j; k++) {//0 1 2 4 / 0 2 2 4 / 0 3 3 4 /
							if (C[i][j] != min(C[i][j], C[i][k] + C[k + 1][j])) {
								C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j]);
								minidx = k;
							}
							check[i][j] = minidx;
						}
					}
				}
			}
		}

		i = 0; j = length - 1;
		palins = C[0][length - 1];
		fprintf(out, "%d\n", palins);
		printpalins(palinstring, 0, length-1);
		while (outputIdx--) {
			fprintf(out, "%s\n", palinstring[i++]);
		}

		//deallocation
		for(i = 0; i < length; i++) {
			free(P[i]);
			free(C[i]);
			free(check[i]);
			free(palinstring[i]);
		}
		free(P);
		free(C);
		free(check);
		free(palinstring);
			
	}


	fclose(fp);
	fclose(out);
	return;
}

void printpalins(char *palinstring[], int i, int j) {
	if (check[i][j] != -1) {
		int k = check[i][j];
		printpalins(palinstring, i, k);
		printpalins(palinstring, k + 1, j);
	}
	else {
		string toPrint;
		int index = 0;
		for (int p = i; p <= j; p++) {
			toPrint += input[p];
			palinstring[outputIdx][index++] = input[p];
		}
		palinstring[outputIdx][index] = '\0';
		outputIdx++;
		printf("%s\n", toPrint.c_str());
		
	}
}

void intervalPartition()
{
	int tc, lectures, roomnumber, curnumber, st, fin;
	struct room * rooms = NULL;
	vector<pair<int, int> > time;
	int i, j;
	FILE *fp = fopen("INPUT/input-3-3.txt", "r");
	FILE *out = fopen("20140938_OUTPUT/output-3-3.txt", "w");
	fscanf(fp, "%d\n", &tc);
	fprintf(out, "%d\n", tc);

	while (tc--) {
		roomnumber = 0; 
		fscanf(fp, "%d\n", &lectures);
		rooms = (struct room*)malloc(sizeof(struct room)*lectures);
		rooms[roomnumber].finish = 0; rooms[roomnumber].start = 0;
		for (i = 0; i < lectures; i++) {
			fscanf(fp, "%d %d\n", &st, &fin);
			time.push_back(pair<int, int>(st, fin));
		}

		sort(time.begin(), time.end());
		for (i = 0; i < lectures; i++) {
			curnumber = 0;
			for (j = 1; j < roomnumber; j++) {
				if (rooms[curnumber].finish > rooms[j].finish)
					curnumber = j;
			}
			if (time[i].first >= rooms[curnumber].finish)//compatible
			{
				rooms[curnumber].finish = time[i].second;
			}
			else {
				roomnumber++;
				rooms[roomnumber].start = time[i].first;
				rooms[roomnumber].finish = time[i].second;
			}

		}
		fprintf(out, "%d\n", roomnumber+1);
		printf("%d\n", roomnumber+1);
		time.clear();
	}
	free(rooms);
	fclose(fp);
	fclose(out);
}