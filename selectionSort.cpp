// selectionSort.cpp: 定义控制台应用程序的入口点。
//
//
#include "stdafx.h"
#include <stdlib.h>

void selectionSort(int *a, int len);
void show(int *a, int len);
int main()
{
	int len;
	int *a;
	printf("How many munbers do you want to enter?\n");
	scanf_s("%d", &len);
	a = (int*)calloc(len, sizeof(int));
	printf("Now enter munbers:\n");
	for (int i = 0; i < len; i++)
		scanf_s("%d", &a[i]);
	selectionSort(a, len);
	show(a, len);
	free(a);
    return 0;
}
void selectionSort(int *a, int len) {
	int temp,minNum;
	for (int i = 0; i <= len - 2; i++) {
		minNum = i;                   //operate the subscript
		for (int j = i; j < len; j++) 
			if (a[minNum] > a[j]) {
				minNum = j;
			}
		temp = a[i];
		a[i] = a[minNum];
		a[minNum] = temp;
	}
}
void show(int *a, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
}

