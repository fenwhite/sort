// CountingSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>


int main()
{
	int max = 0,len,i,sum=0;
	int *A,*B;
	printf("How many number do you want to enter?\n");
	scanf_s("%d", &len);
	A = (int*)calloc(len, sizeof(int));
	printf("Please enter the number:\n");
	for (i = 0; i < len; i++)
		scanf_s("%d", &A[i]);
	for (i = 0; i < len; i++)
		if (A[i] > max)
			max = A[i];
	B = (int*)calloc(max+1, sizeof(int));
	for (i = 0; i < max+1; i++)               //initialization
		B[i] = 0;
	for (i = 0; i < len; i++)                 //count
		B[A[i]]++;

	printf("\nsequance: ");
	for (i = 0; i <= max; i++)                //check-out
		printf("%d ", i);
	printf("\n");
	printf("B       : ");
	for (i = 0; i <= max; i++)
		printf("%d ", B[i]);
	printf("\n\n");

	for (i = 0; i < max+1; i++) {             //sum
		sum += B[i];                          //statistics
		B[i] = sum;
	}

	printf("sequance: ");
	for (i = 0; i <= max; i++)                //check-out
		printf("%d ", i);
	printf("\n");
	printf("B       : ");
	for (i = 0; i <= max; i++)
		printf("%d ", B[i]);
	printf("\n\n");

	for (i = max; i >0; i--) {                         //insert sign
				A[B[i]-1] = i;
				int time = B[i] - B[i - 1]-1;     //fill number between sign
				if (time < 0)
					continue;
				else
				    while (time--) 
					    A[B[i] -2 - time] = i;
				
	}
	if (B[0] == 0)                         //Special column
		;
	else
		for (i = 0; i < B[0]; i++)
			A[i] = 0;
	printf("\nsequance:");
	for (i = 0; i < len; i++)
		printf("%d ", i);
	printf("\nA       :");
	for (i = 0; i < len; i++)                         //show A[]
		printf("%d ", A[i]);
	printf("\n");
    return 0;
}

