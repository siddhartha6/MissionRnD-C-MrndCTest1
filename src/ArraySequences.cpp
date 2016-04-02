/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL)
	     return NULL;
	int index = 0,diff=0,result[6],res_index=0;
	diff = arr[1] - arr[0];
	int gp_num = arr[0];
	int start_index = 0,flag=0,e_index=1,s_index=0;
	for (index = 0; index < len; index++)
	{       

		if (arr[index + 1] - arr[index] == diff || flag==0 )
		{
			result[s_index] = start_index;
			result[e_index] = index+1;
			//start_index = index;
		}
		else
		{
			diff = arr[index + 1] - arr[index];
			if (flag == 0){
				
				res_index++;
				s_index = 2;
				e_index = 3;
			}
		}

		if (arr[index + 1] % arr[index] == 0)
			flag = 1;
		if (arr[index + 1] % arr[index] != 0 && flag == 1)
		{
			result[4] = start_index;
			result[5] = index+1;
			start_index = index;
			flag = 0;

		}

	}
	return result;
}