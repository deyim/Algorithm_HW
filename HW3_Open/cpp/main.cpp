#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_types.h"
#include <Windows.h>

__int64 start, freq, end;
#define CHECK_TIME_START QueryPerformanceFrequency((LARGE_INTEGER*)&freq); QueryPerformanceCounter((LARGE_INTEGER*)&start)
#define CHECK_TIME_END(a) QueryPerformanceCounter((LARGE_INTEGER*)&end); a = (float)((float)(end - start) / (freq / 1000.0f))
float compute_time;

#define STUDENT_ID	20140938

#include "test_data_config.h"  // the content of this file will be modified for evaluation.

//#define DUMP_DATA

//#define TEST_SELECTION_REC
//#define TEST_INSERTION_SORT
#define TEST_HEAP_SORT
#define TEST_QSORT
#define TEST_QUICK_SORT
#define TEST_QUICK_SORT_OPT
//#define TEST_QUICK_SORT_OPT_TIME_CHECK


int read_input_data(const char *file_name, int *n, ELEMENT **data) {
	FILE *fp;

	fprintf(stdout, "^^^ Reading the input data file %s...\n", file_name);
	if ((fp = fopen(file_name, "rb")) == NULL) {
		fprintf(stderr, "Error: cannot open the binary file %s for reading...\n", file_name);
		return 0;
	}

	fread(n, sizeof(int), 1, fp);
	fprintf(stdout, "*** Number of elements = %d\n", *n);

	if ((*data = (ELEMENT *)malloc(sizeof(ELEMENT)*(*n))) == NULL) {
		fprintf(stderr, "Error: cannot allocate memory for %d ELEMENTs...\n", n);
		return 0;
	}
	fread(*data, sizeof(ELEMENT), *n, fp);	// assume there is no problem in the input data file
	fclose(fp);
	fprintf(stdout, "^^^ Done...\n\n");
	return 1;
}

int check_selection_result(int index_correct, int index_computed, int n, ELEMENT *data) {
	// return 1 if the selection has been carried out correctly or 0 otherwise

	if ((index_computed < 0) || (index_computed >= n))
		return 0;
	if (ELEMENT_KEY(data + index_correct) == ELEMENT_KEY(data + index_computed))
		return 1;
	else
		return 0;
}

int check_sorting_result(const char *file_name, int n, ELEMENT *data) {
	// return 1 if the input data has been sorted correctly
	// or 0 otherwise

	int prev, next;
	prev = ELEMENT_KEY(&data[0]);
	for (int i = 1; i < n; i++) {
		next = ELEMENT_KEY(&data[i]);
		if (prev > next) return 0;
		prev = next;
	}
	/*
	FILE *fp;
	ELEMENT prev, next;
	int prevKey, nextKey, tmp;

	fprintf(stdout, "^^^ Checking the sorted data file %s...\n", file_name);
	if ((fp = fopen(file_name, "rb")) == NULL) {
		fprintf(stderr, "Error: cannot open the binary file %s for reading...\n", file_name);
		return 0;
	}

	fread(&tmp, sizeof(int), 1, fp);
	fread(&next, sizeof(ELEMENT), 1, fp);
	nextKey = ELEMENT_KEY(&next);
	for (int i = 1; i < n; i++) {
		prevKey = nextKey;
		fread(&next, sizeof(ELEMENT), 1, fp);
		nextKey = ELEMENT_KEY(&next);
		printf("nextKey %d prevKey %d\n", nextKey, prevKey);
		if (prevKey > nextKey) return 0;
	}
	fclose(fp);
	fprintf(stdout, "^^^ SUCCESS return 1...\n\n");
	*/
	return 1;
}

void main(void) {
	ELEMENT *data;
	int n;
	FILE *fp, *time;

	char test_result_file[32];
	char test_method[32];

	int test_result;

	sprintf(test_result_file, "TEST_RESULT_%d.txt", STUDENT_ID);

	if ((fp = fopen(test_result_file, "w")) == NULL) {
		fprintf(stderr, "Error: cannot open the file %s for reading...\n", test_result_file);
		exit(-1);
	}

	time = fopen("Sorting_Time_Experiment.txt", "w");

#ifdef TEST_SELECTION_REC
	sprintf(test_method, "SELECTION_REC");
	printf("SELECTION_REC\n");

	test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
		{
			int index_computed;

			test_result = SELECTION_REC(data, 0, n - 1, test_data_k_selection[i], &index_computed);
			if (test_result == 1) {
				// the function has finished successfully
				fprintf(fp, "^^^ Selection method = %s, Test file = %s, Result =  %d\n",
					test_method, test_data_file_sorting[i], check_selection_result(test_data_indices_selected[i], index_computed, n, data));
			}
			else
				fprintf(fp, "^^^ Selection method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);

#ifdef DUMP_DATA
			{
				fprintf(stdout, "*** %s: Output data\n", test_method);
				fprintf(stdout, "  index = %6d\n", index_computed);
				fprintf(stdout, "\n");
			}
#endif
		}
	}
#endif // end of TEST_INSERTION_SORT

#ifdef TEST_INSERTION_SORT
	sprintf(test_method, "INSERTION_SORT");
	printf("INSERTION SORT\n");

	//test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
		CHECK_TIME_START;
		test_result = INSERTION_SORT(data, 0, n - 1);
		CHECK_TIME_END(compute_time);
		if (test_result == 1) {
			// the function has finished successfully
			/********SORTED FILE******/
			ELEMENT *dataPtr = data;
			FILE *sorted = fopen(test_data_file_sorted[i], "w");
			fwrite(&n, sizeof(int), 1, sorted);
			fwrite(data, sizeof(ELEMENT), n, sorted);
			fclose(sorted);

			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n",
				test_method, test_data_file_sorting[i], check_sorting_result(test_data_file_sorted[i], n, data));
			fprintf(time, "%s\t%s\t%.3f\n", test_method, test_data_file_sorted[i], compute_time);
		}
		else
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);
		

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Output data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
	}
#endif // end of TEST_INSERTION_SORT

	fprintf(time, "\n");

#ifdef TEST_HEAP_SORT
	sprintf(test_method, "HEAP_SORT");
	printf("HEAP SORT\n");
	//test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
		CHECK_TIME_START;
		test_result = HEAP_SORT(data, 0, n - 1);
		CHECK_TIME_END(compute_time);

		if (test_result == 1) {
			// the function has finished successfully
			/********SORTED FILE******/
			ELEMENT *dataPtr = data;
			FILE *sorted = fopen(test_data_file_sorted[i], "w");
			fwrite(&n, sizeof(int), 1, sorted);
			fwrite(data, sizeof(ELEMENT), n, sorted);
			fclose(sorted);

			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n",
				test_method, test_data_file_sorting[i], check_sorting_result(test_data_file_sorted[i], n, data));
			fprintf(time, "%s\t%s\t%.3f\n", test_method, test_data_file_sorted[i], compute_time);
		}
		else
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Output data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
	}
#endif // end of TEST_HEAP_SORT

	fprintf(time, "\n");

#ifdef TEST_QSORT
	sprintf(test_method, "QSORT");
	printf("QSORT SORT\n");
	//test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif

		CHECK_TIME_START;
		test_result = QSORT(data, 0, n - 1);
		CHECK_TIME_END(compute_time);
		printf("*** Time taken by %s to sort the array of size %d = %.3fms\n\n", test_method, n, compute_time);

		if (test_result == 1) {
			/********SORTED FILE******/
			ELEMENT *dataPtr = data;
			FILE *sorted = fopen(test_data_file_sorted[i], "w");
			fwrite(&n, sizeof(int), 1, sorted);
			fwrite(data, sizeof(ELEMENT), n, sorted);
			fclose(sorted);

			// the function has finished successfully
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n",
				test_method, test_data_file_sorting[i], check_sorting_result(test_data_file_sorted[i], n, data));
			fprintf(time, "%s\t%s\t%.3f\n", test_method, test_data_file_sorted[i], compute_time);
		}
		else
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);

		

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Output data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
	}
#endif // end of TEST_QSORT

	fprintf(time, "\n");

#ifdef TEST_QUICK_SORT
	sprintf(test_method, "QUICK_SORT");
	printf("QUICK SORT\n");
	//test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
		CHECK_TIME_START;
		test_result = QUICK_SORT(data, 0, n - 1);
		CHECK_TIME_END(compute_time);

		if (test_result == 1) {
			// the function has finished successfully

			/********SORTED FILE******/
			ELEMENT *dataPtr = data;
			FILE *sorted = fopen(test_data_file_sorted[i], "w");
			fwrite(&n, sizeof(int), 1, sorted);
			fwrite(data, sizeof(ELEMENT), n, sorted);
			fclose(sorted);

			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n",
				test_method, test_data_file_sorting[i], check_sorting_result(test_data_file_sorted[i], n, data));
			fprintf(time, "%s\t%s\t%.3f\n", test_method, test_data_file_sorted[i], compute_time);
		}
		else
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Output data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
	}
#endif // end of TEST_QUICK_SORT

	fprintf(time, "\n");

#ifdef TEST_QUICK_SORT_OPT
	sprintf(test_method, "QUICK_SORT_OPT");
	printf("QUICK SORT OPT\n");
	//test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);

#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif

		CHECK_TIME_START;
		test_result = QUICK_SORT_OPT(data, 0, n - 1);
		CHECK_TIME_END(compute_time);


		if (test_result == 1) {
			// the function has finished successfully
			/********SORTED FILE******/
			ELEMENT *dataPtr = data;
			FILE *sorted = fopen(test_data_file_sorted[i], "w");
			fwrite(&n, sizeof(int), 1, sorted);
			fwrite(data, sizeof(ELEMENT), n, sorted);
			fclose(sorted);

			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n",
				test_method, test_data_file_sorting[i], check_sorting_result(test_data_file_sorted[i], n, data));
			fprintf(time, "%s\t%s\t%.3f\n", test_method, test_data_file_sorted[i], compute_time);
		}
		else
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);



#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Output data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
	}
#endif // end of TEST_QUICK_SORT_OPT


	fprintf(time, "\n");

#ifdef TEST_QUICK_SORT_OPT_TIME_CHECK
	// time measuring code must be inserted
	sprintf(test_method, "QUICK_SORT_OPT_TIME_CHECK");
	printf("QUICK SORT OPT TIME CHECK\n");
	test_cases_sorting = 3; // for a simple test
	for (int i = 0; i < test_cases_sorting; i++) {
		read_input_data(test_data_file_sorting[i], &n, &data);


#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Input data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
		CHECK_TIME_START;
		test_result = QUICK_SORT_OPT(data, 0, n - 1);
		CHECK_TIME_END(compute_time);

		if (test_result == 1) {
			// the function has finished successfully
			/********SORTED FILE******/
			ELEMENT *dataPtr = data;
			FILE *sorted = fopen(test_data_file_sorted[i], "w");
			fwrite(&n, sizeof(int), 1, sorted);
			fwrite(data, sizeof(ELEMENT), n, sorted);
			fclose(sorted);

			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n",
				test_method, test_data_file_sorting[i], check_sorting_result(test_data_file_sorted[i], n, data));
			fprintf(time, "%s\t%s\t%.3f\n", test_method, test_data_file_sorted[i], compute_time);
		}
		else
			fprintf(fp, "^^^ Sorting method = %s, Test file = %s, Result =  %d\n", test_method, test_data_file_sorting[i], 0);



#ifdef DUMP_DATA
		{
			ELEMENT *ptr = data;
			fprintf(stdout, "*** %s: Output data\n", test_method);
			for (int i = 0; i < n; i++, ptr++)
				fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
			fprintf(stdout, "\n");
		}
#endif
	}
#endif // end of TEST_QUICK_SORT_OPT

	fclose(fp);
	fclose(time);
	int a;
	a = 0;
}