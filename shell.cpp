// shell.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
int step[] = { 5,3,1 };

void show(int *A, int len); 
void shell(int *A, int len);
int main()
{
	int *A, len;
	printf("How many number do want to enter?\n");
	scanf_s("%d", &len);
	A = (int*)calloc(len, sizeof(int));
	for (int i = 0; i < len; i++)
		scanf_s("%d", &A[i]);
	show(A, len);
    return 0;
}
void show(int *A , int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", A[i]);
}
void shell(int *A, int len) {
	int temp, k = 0;
	while (k < 3) {
		for (int i = 1; i < len; i += step[k]) {
			temp = a[i];
			for (int j = i - step[k]; j >= 0; j-=step[k])
				if (temp <= a[j]) {
					a[j + step[k]] = a[j];
					a[j] = temp;
				}
		}
		k++;
	}
}