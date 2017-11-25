#pragma once

//#define INPUT_FILE_NAME_1	"../Data/ENTIRELY_RANDOM_8.binary"
#define INPUT_FILE_NAME_0	"../Data/ENTIRELY_RANDOM_32.binary"
#define INPUT_FILE_NAME_3	"../Data/ENTIRELY_RANDOM_8.binary"
#define INPUT_FILE_NAME_1	"../Data/ENTIRELY_RANDOM_128.binary"
//#define INPUT_FILE_NAME_0	"../Data/ENTIRELY_RANDOM_64.binary"
#define INPUT_FILE_NAME_2 "../Data/ENTIRELY_RANDOM_1024.binary"
#define INPUT_FILE_NAME_4	"../Data/ENTIRELY_RANDOM_1048576.binary"

//#define SORTED_INPUT_FILE_NAME_1	"../Data/ENTIRELY_RANDOM_8_sorted.binary"
#define SORTED_INPUT_FILE_NAME_0	"../Data/ENTIRELY_RANDOM_32_sorted.binary"
#define SORTED_INPUT_FILE_NAME_3	"../Data/ENTIRELY_RANDOM_8_sorted.binary"
#define SORTED_INPUT_FILE_NAME_1	"../Data/ENTIRELY_RANDOM_128_sorted.binary"
//#define SORTED_INPUT_FILE_NAME_0	"../Data/ENTIRELY_RANDOM_64_sorted.binary"
#define SORTED_INPUT_FILE_NAME_2	"../Data/ENTIRELY_RANDOM_1024_sorted.binary"
#define SORTED_INPUT_FILE_NAME_4	"../Data/ENTIRELY_RANDOM_1048576_sorted.binary"

int test_cases_sorting = 3;
char test_data_file_sorting[3][128] = { INPUT_FILE_NAME_0, INPUT_FILE_NAME_1, INPUT_FILE_NAME_2 };
char test_data_file_sorted[3][128] = { SORTED_INPUT_FILE_NAME_0, SORTED_INPUT_FILE_NAME_1, SORTED_INPUT_FILE_NAME_2 };

int test_cases_selection = 3;
char test_data_file_selection[3][128] = { INPUT_FILE_NAME_0, INPUT_FILE_NAME_1, INPUT_FILE_NAME_2 };
//int test_data_k_selection[3] = { 13, 483, 44493 };			// k's for selection
// int test_data_k_selection[3] = { 13, 483, 44493 };			// k's for selection
// int test_data_indices_selected[3] = { 15, 132, 575038};	// indices of selected elements
int test_data_k_selection[3] = { 13, 29, 1023 };
int test_data_indices_selected[3] = { 15, 2, 12};