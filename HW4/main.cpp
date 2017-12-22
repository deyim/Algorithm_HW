#include <cstdio>
#include <stdlib.h>

void longestPalindrome();
void partitionPalindrome();
void intervalPartition();

int main(){

	longestPalindrome();
    partitionPalindrome();
	intervalPartition();
	return 0;
}

void longestPalindrome()
{
	int tc, length;
	bool *check;
	char *origin, *palin;
	int i,j;
	FILE *fp = fopen("input-3-1.txt", "r");
	FILE *out = fopen("output-3-1.txt", "w");
	fscanf(fp,"%d\n", &tc);
	fprintf(out, "%d\n", tc);

	while(tc--)
	{
		fscanf(fp, "%d\n", length);
		fprintf(out, "%d\n", length);
		origin = new char[length];
		palin = new char[length];
		check = new bool[length];
		fscnaf(fp, "%s\n", origin);
		
		//subproblems
		for(i = 0 ; i < length; i++)
		{
			for( j = 0 ; j < length; j++)
			{
				if(origin[i] != origin[j]){
					//max i+1 j / i j-1
					check[i] = true;
				}
				else{
					if(j == i+1){
						//

					}
					else{
						//

					}
				}

			}
		}

		fprintf(out, "%s\n", palin);
		free(origin);
		free(palin);
	}
	return;
}

void partitionPalindrome()
{

}

void intervalPartition();
{

}