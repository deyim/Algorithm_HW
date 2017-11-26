#pragma once

/*
#define INPUT_FILE_NAME_0	"4096_random.binary"
#define INPUT_FILE_NAME_1	"16384_random.binary"
#define INPUT_FILE_NAME_2	"1048576_random.binary"

#define SORTED_INPUT_FILE_NAME_0	"4096_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_1	"16384_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_2	"1048576_random_sorted.binary"

int test_cases_sorting = 3;
char test_data_file_sorting[3][128] = { INPUT_FILE_NAME_0, INPUT_FILE_NAME_1, INPUT_FILE_NAME_2};
char test_data_file_sorted[3][128] = { SORTED_INPUT_FILE_NAME_0, SORTED_INPUT_FILE_NAME_1, SORTED_INPUT_FILE_NAME_2};
*/



#define INPUT_FILE_NAME_0	"1024_random.binary"
#define INPUT_FILE_NAME_1	"4096_random.binary"
#define INPUT_FILE_NAME_2	"16384_random.binary"
#define INPUT_FILE_NAME_3	"65536_random.binary"
#define INPUT_FILE_NAME_4	"262144_random.binary"
#define INPUT_FILE_NAME_5	"1048576_random.binary"
#define INPUT_FILE_NAME_6	"1024_descending.binary"
#define INPUT_FILE_NAME_7	"4096_descending.binary"
#define INPUT_FILE_NAME_8	"16384_descending.binary"
#define INPUT_FILE_NAME_9	"65536_descending.binary"
#define INPUT_FILE_NAME_10	"262144_descending.binary"
#define INPUT_FILE_NAME_11	"1048576_descending.binary"
#define INPUT_FILE_NAME_12	"1024_swaps.binary"
#define INPUT_FILE_NAME_13	"4096_swaps.binary"
#define INPUT_FILE_NAME_14	"16384_swaps.binary"
#define INPUT_FILE_NAME_15	"65536_swaps.binary"
#define INPUT_FILE_NAME_16	"262144_swaps.binary"
#define INPUT_FILE_NAME_17	"1048576_swaps.binary"


#define SORTED_INPUT_FILE_NAME_0	"1024_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_1	"4096_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_2	"16384_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_3	"65536_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_4	"262144_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_5	"1048576_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_6	"1024_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_7	"4096_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_8	"16384_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_9	"65536_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_10	"262144_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_11	"1048576_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_12	"1024_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_13	"4096_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_14	"16384_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_15	"65536_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_16	"262144_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_17	"1048576_swaps_sorted.binary"

int test_cases_sorting = 18;
char test_data_file_sorting[18][128] = { INPUT_FILE_NAME_0, INPUT_FILE_NAME_1, INPUT_FILE_NAME_2, INPUT_FILE_NAME_3, 
INPUT_FILE_NAME_4, INPUT_FILE_NAME_5, INPUT_FILE_NAME_6 , INPUT_FILE_NAME_7 , INPUT_FILE_NAME_8, INPUT_FILE_NAME_9, 
INPUT_FILE_NAME_10, INPUT_FILE_NAME_11, INPUT_FILE_NAME_12, INPUT_FILE_NAME_13, INPUT_FILE_NAME_14, INPUT_FILE_NAME_15,
INPUT_FILE_NAME_16, INPUT_FILE_NAME_17 };
char test_data_file_sorted[18][128] = { SORTED_INPUT_FILE_NAME_0, SORTED_INPUT_FILE_NAME_1, SORTED_INPUT_FILE_NAME_2, 
SORTED_INPUT_FILE_NAME_3, SORTED_INPUT_FILE_NAME_4, SORTED_INPUT_FILE_NAME_5, SORTED_INPUT_FILE_NAME_6 , 
SORTED_INPUT_FILE_NAME_7 , SORTED_INPUT_FILE_NAME_8, SORTED_INPUT_FILE_NAME_9, SORTED_INPUT_FILE_NAME_10, 
SORTED_INPUT_FILE_NAME_11, SORTED_INPUT_FILE_NAME_12, SORTED_INPUT_FILE_NAME_13, SORTED_INPUT_FILE_NAME_14, SORTED_INPUT_FILE_NAME_15,
SORTED_INPUT_FILE_NAME_16, SORTED_INPUT_FILE_NAME_17 };


/*
#define INPUT_FILE_NAME_0	"1024_random.binary"
#define INPUT_FILE_NAME_1	"4096_random.binary"
#define INPUT_FILE_NAME_2	"16384_random.binary"
#define INPUT_FILE_NAME_3	"65536_random.binary"
#define INPUT_FILE_NAME_4	"1024_descending.binary"
#define INPUT_FILE_NAME_5	"4096_descending.binary"
#define INPUT_FILE_NAME_6	"16384_descending.binary"
#define INPUT_FILE_NAME_7	"65536_descending.binary"
#define INPUT_FILE_NAME_8	"1024_swaps.binary"
#define INPUT_FILE_NAME_9	"4096_swaps.binary"
#define INPUT_FILE_NAME_10	"16384_swaps.binary"
#define INPUT_FILE_NAME_11	"65536_swaps.binary"
#define INPUT_FILE_NAME_12	"262144_swaps.binary"
#define INPUT_FILE_NAME_13	"1048576_swaps.binary"


#define SORTED_INPUT_FILE_NAME_0	"1024_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_1	"4096_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_2	"16384_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_3	"65536_random_sorted.binary"
#define SORTED_INPUT_FILE_NAME_4	"1024_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_5	"4096_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_6	"16384_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_7	"65536_descending_sorted.binary"
#define SORTED_INPUT_FILE_NAME_8	"1024_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_9	"4096_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_10	"16384_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_11	"65536_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_12	"262144_swaps_sorted.binary"
#define SORTED_INPUT_FILE_NAME_13	"1048576_swaps_sorted.binary"

int test_cases_sorting = 14;

char test_data_file_sorting[14][128] = { INPUT_FILE_NAME_0, INPUT_FILE_NAME_1, INPUT_FILE_NAME_2, INPUT_FILE_NAME_3,
INPUT_FILE_NAME_4, INPUT_FILE_NAME_5, INPUT_FILE_NAME_6 , INPUT_FILE_NAME_7 , INPUT_FILE_NAME_8, INPUT_FILE_NAME_9,
INPUT_FILE_NAME_10, INPUT_FILE_NAME_11, INPUT_FILE_NAME_12, INPUT_FILE_NAME_13};

char test_data_file_sorted[14][128] = { SORTED_INPUT_FILE_NAME_0, SORTED_INPUT_FILE_NAME_1, SORTED_INPUT_FILE_NAME_2,
SORTED_INPUT_FILE_NAME_3, SORTED_INPUT_FILE_NAME_4, SORTED_INPUT_FILE_NAME_5, SORTED_INPUT_FILE_NAME_6 ,
SORTED_INPUT_FILE_NAME_7 , SORTED_INPUT_FILE_NAME_8, SORTED_INPUT_FILE_NAME_9, SORTED_INPUT_FILE_NAME_10,
SORTED_INPUT_FILE_NAME_11, SORTED_INPUT_FILE_NAME_12, SORTED_INPUT_FILE_NAME_13};
*/

int test_cases_selection = 3;
char test_data_file_selection[3][128] = { INPUT_FILE_NAME_0, INPUT_FILE_NAME_1, INPUT_FILE_NAME_2 };
int test_data_k_selection[3] = { 13, 483, 44493 };			// k's for selection
int test_data_indices_selected[3] = { 15, 132, 575038 };	// indices of selected elements
